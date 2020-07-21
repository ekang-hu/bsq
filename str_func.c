/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekang <ekang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:42:11 by ekang             #+#    #+#             */
/*   Updated: 2020/07/22 01:42:39 by ekang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int		ft_atoi(char *str, t_map *tmap)
{
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\n')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				nbr = nbr * 10 + str[i] - 48;
			}
		}
		else
		{
			tmap->error = 1;
			return (0);
		}
		i++;
	}
	return (nbr);
}

int		line_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
