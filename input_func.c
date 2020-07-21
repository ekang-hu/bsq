/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekang <ekang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:36:47 by ekang             #+#    #+#             */
/*   Updated: 2020/07/22 01:27:57 by ekang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

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
