/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:36:46 by muraler           #+#    #+#             */
/*   Updated: 2022/10/26 14:39:23 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	f1(t_game *err, int x, int y)
{
	if (err->map[y][x + 1] == 'E')
		err->ch_exit = 1;
	else if (err->map[y][x - 1] == 'E')
		err->ch_exit = 1;
	else if (err->map[y - 1][x] == 'E')
		err->ch_exit = 1;
	else if (err->map[y + 1][x] == 'E')
		err->ch_exit = 1;
}

void	f2(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'C')
	{
		g->map[y][x] = 's';
		g->ch_coin--;
	}
	else
		g->map[y][x] = 'n';
}

void	err_map(t_game *g, int x, int y)
{
	if (g->ch_exit != 1 || g->ch_coin != 0)
	{
		f1(g, x, y);
		if (g->map[y - 1][x] == 'C' || g->map[y - 1][x] == '0')
		{
			f2(g, x, y - 1);
			err_map(g, x, y - 1);
		}
		if (g->map[y + 1][x] == 'C' || g->map[y + 1][x] == '0')
		{
			f2(g, x, y + 1);
			err_map(g, x, y + 1);
		}
		if (g->map[y][x + 1] == 'C' || g->map[y][x + 1] == '0')
		{
			f2(g, x + 1, y);
			err_map(g, x + 1, y);
		}
		if (g->map[y][x - 1] == 'C' || g->map[y][x - 1] == '0')
		{
			f2(g, x - 1, y);
			err_map(g, x - 1, y);
		}
	}
}

void	map_edit(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->max_y)
	{
		j = 0;
		while (j < g->max_x)
		{
			if (g->map[i][j] == 's')
				g->map[i][j] = 'C';
			if (g->map[i][j] == 'n')
				g->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	valid_path(t_game *err)
{
	err->ch_coin = err->coin;
	err->ch_exit = 0;
	err_map(err, err->player_x, err->player_y);
	if (err->ch_exit == 1 && err->ch_coin == 0)
		map_edit(err);
	else
		ft_err('i', err);
}
