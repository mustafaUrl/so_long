/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:41:07 by muraler           #+#    #+#             */
/*   Updated: 2022/10/26 14:41:07 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free(game);
	exit(0);
}

void	ft_err(char c, t_game *g)
{
	ft_printf("\n!!!==========Error==========!!!\n");
	if (c == 'a')
		ft_printf("\n---> You entered missing or too many arguments <---\n");
	else if (c == 'b')
		ft_printf("\n---> Your file extension is not .ber <---\n");
	else if (c == 'c')
		ft_printf("\n---> File description eroor <---\n");
	else if (c == 'd')
		ft_printf("\n---> fd=-1 || !map || y < 3 <---\n");
	else if (c == 'e')
		ft_printf("\n---> Not rectangular or x <---\n");
	else if (c == 'f')
		ft_printf("\n---> The perimeter is not walled <---\n");
	else if (c == 'g')
		ft_printf("\n---> Undefined character <---\n");
	else if (c == 'h')
		ft_printf("\n---> İnventory error <---\n");
	else if (c == 'i')
		ft_printf("\n---> No valid path <---\n");
	ft_printf("\n!!!==========Error==========!!!\n");
	exit_hook(g);
}

void	inv_check(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->max_y)
	{
		j = 0;
		while (j < g->max_x)
		{
			if (g->map[i][j] == 'P')
			{
				g->player_x = j;
				g->player_y = i;
				g->player++;
			}
			if (g->map[i][j] == 'C')
				g->coin++;
			if (g->map[i][j] == 'E')
				g->exit++;
			j++;
		}
		i++;
	}
	if (g->player != 1 || g->coin < 1 || g->exit != 1)
		ft_err('h', g);
}

void	char_check(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->max_y)
	{
		j = 0;
		while (j < g->max_x && g->map[i][j] != '\0')
		{
			if (!(ft_strchr("01CEP", g->map[i][j])))
				ft_err('g', g);
			j++;
		}
		i++;
	}
}
