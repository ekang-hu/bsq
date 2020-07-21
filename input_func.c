/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekang <ekang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:36:47 by ekang             #+#    #+#             */
/*   Updated: 2020/07/22 00:37:08 by ekang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*ft_split_map2(char *str, char *map, int *str_index, t_map *tmap)
{
	int		j;

	j = 0;
	if (line_len(&(str[*str_index])) != tmap->nb_col)
	{
		tmap->error = 1;
		return (NULL);
	}
	map = &(str[*str_index]);
	while (map[j] && j < tmap->nb_col + 1)
	{
		if (map[j] != tmap->empty && map[j] != tmap->obs && map[j] != '\n')
		{
			tmap->error = 1;
			return (NULL);
		}
		*str_index = *str_index + 1;
		j++;
	}
	return (map);
}

char	**ft_split_map(char *str, t_map *tmap)
{
	int		i;
	char	**map;
	int		str_index;

	i = 0;
	str_index = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (tmap->nb_line + 1))))
		exit(1);
	while (str[str_index] && i < tmap->nb_line)
	{
		map[i] = ft_split_map2(str, map[i], &str_index, tmap);
		i++;
	}
	if (i != tmap->nb_line || str[str_index] != 0)
	{
		tmap->error = 1;
		return (NULL);
	}
	map[i] = NULL;
	return (map);
}

char	*ft_first_line(char *str, char *buffer, int i, t_map *tmap)
{
	while (buffer[i] != '\n')
		i++;
	((i < 3) ? tmap->error = 1 : 0);
	if (tmap->error == 1)
		return (NULL);
	tmap->full = buffer[i - 1];
	buffer[i - 1] = '.';
	tmap->obs = buffer[i - 2];
	buffer[i - 2] = '.';
	tmap->empty = buffer[i - 3];
	buffer[i - 3] = '.';
	tmap->nb_line = ft_atoi(buffer, tmap);
	if (tmap->empty == tmap->full || tmap->empty == tmap->obs
			|| tmap->full == tmap->obs ||
			tmap->error == 1 || !(buffer[++i]) || buffer[i] == '\n')
	{
		tmap->error = 1;
		return (NULL);
	}
	tmap->nb_col = line_len(&(buffer[i]));
	if (!(str = malloc(sizeof(char) * ((tmap->nb_col + 1)
						* (tmap->nb_line + 1) + 1))))
		exit(1);
	ft_strcpy(str, &(buffer[i]));
	return (str);
}

void	ft_read_input2(int fd, char *buffer, t_map *tmap)
{
	int		ret;
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while ((ret = read(fd, buffer, BUFFSIZE)))
	{
		buffer[ret] = '\0';
		if (!str)
		{
			str = ft_first_line(str, buffer, i, tmap);
		}
		else if (tmap->error != 1)
			str = ft_strcat(str, buffer);
	}
	if (str && tmap->error != 1)
		ft_process_map(str, tmap);
	else
		(tmap->error = 1);
	ft_is_error(str, tmap);
	free(str);
}

void	ft_read_input(int argc, char **argv, int i, t_map *tmap)
{
	char	buffer[BUFFSIZE + 1];
	int		fd;

	fd = 0;
	while (i < argc)
	{
		tmap->error = 0;
		if (argc > 1)
		{
			i++;
			fd = open(argv[i], O_RDONLY);
		}
		if (i > 1 && i < argc)
			ft_putchar('\n');
		if (fd == -1 && i < argc)
			write(2, "map error\n", 10);
		else if (fd != -1)
		{
			ft_read_input2(fd, buffer, tmap);
			if (argc != 1)
				close(fd);
			else
				i = 1;
		}
	}
}
