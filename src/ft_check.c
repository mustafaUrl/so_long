/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:26:55 by muraler           #+#    #+#             */
/*   Updated: 2022/11/01 14:55:13 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_format(char *str, t_game *g)
{
	char	*s;

	s = ft_strrchr(str, '.');
	if (s == NULL || ft_strncmp(s + 1, "ber", 3) != 0)
		ft_err('b', g);
}

void	wall_check(t_game	*g)
{
	int	i;
	int	y;
	int	x;

	i = -1;
	y = g->max_y - 1;
	x = g->max_x - 1;
	while (i++ < y)
		if (g->map[i][0] != '1' || g->map[i][x] != '1')
			ft_err('f', g);
	i = -1;
	while (i++ < x)
		if (g->map[0][i] != '1' || g->map[y][i] != '1')
			ft_err('f', g);
}

int	map_x(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	rectangle_check(t_game *g)
{
	int	i;

	i = 0;
	g->max_x = map_x(g->map[i]);
	if (g->max_x < 3)
		ft_err('e', g);
	while (i < g->max_y)
	{
		if (g->max_x != map_x(g->map[i]))
			ft_err('e', g);
		g->map[i][g->max_x] = '\0';
		i++;
	}
}

void	check_map(t_game	*g)
{
	g->player = 0;
	g->exit = 0;
	g->coin = 0;
	g->move = 0;
	rectangle_check(g);
	wall_check(g);
	char_check(g);
	inv_check(g);
	valid_path(g);
}
