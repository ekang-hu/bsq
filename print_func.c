/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekang <ekang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:43:02 by ekang             #+#    #+#             */
/*   Updated: 2020/07/22 01:43:17 by ekang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_is_error(char *str, t_map *tmap)
{
	if (tmap->error == 1)
		write(2, "map error\n", 10);
	else
		ft_show_tab(str, tmap);
}

void	ft_show_tab(char *str, t_map *tmap)
{
	int		i;

	i = 0;
	write(1, str, (tmap->nb_col + 1) * tmap->nb_line);
}
