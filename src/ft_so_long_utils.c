/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:41:57 by muraler           #+#    #+#             */
/*   Updated: 2022/10/26 14:57:25 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fnd_max_y(char *a, t_game *g)
{
	char	*s;
	int		i;
	int		fd;

	i = 0;
	fd = open(a, O_RDONLY);
	if (fd < 0)
		ft_err('c', g);
	s = get_next_line(fd);
	while (s && *s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	return (i);
}

void	map_init(t_game *g, char *av)
{
	char	*s;
	int		i;
	int		fd;

	i = 0;
	g->max_y = fnd_max_y(av, g);
	fd = open(av, O_RDONLY);
	g->map = malloc(sizeof(char *) * g->max_y);
	if (fd == -1 || !g->map || g->max_y < 3)
		ft_err('d', g);
	s = get_next_line(fd);
	while (i < g->max_y)
	{
		g->map[i] = s;
		i++;
		s = get_next_line(fd);
	}
	close(fd);
}

int	key_func(int code, t_game *g)
{
	if (code == 13)
		up(g);
	if (code == 1)
		down(g);
	if (code == 0)
		left(g);
	if (code == 2)
		right(g);
	if (code == 53 || code == 12)
	{
		free(g);
		mlx_destroy_window(g->mlx, g->window);
		exit(0);
	}
	return (0);
}
