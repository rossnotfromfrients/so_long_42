/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:50:00 by you               #+#    #+#             */
/*   Updated: 2025/04/17 14:50:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	save_player(t_game *map, int x, int y)
{
	map->p += 1;
	map->player.x = x;
	map->player.y = y;
}

void	check_elements(t_game *map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->array[y][x] == 'C')
				map->c++;
			else if (map->array[y][x] == 'E')
				map->e++;
			else if (map->array[y][x] == 'P')
				save_player(map, x, y);
			else if (map->array[y][x] != '0' && map->array[y][x] != '1')
				ft_error("invalid map char");
			x++;
		}
		y++;
	}
	if (map->p != 1 || map->c < 1 || map->e < 1)
		ft_error("missing elements");
}

void	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->x)
	{
		if (game->array[0][x] != '1' ||
			game->array[game->y - 1][x] != '1')
			ft_error("Error: top/bottom wall missing");
		x++;
	}
	y = 0;
	while (y < game->y)
	{
		if (game->array[y][0] != '1' ||
			game->array[y][game->x - 1] != '1')
			ft_error("Error: side wall missing");
		y++;
	}
}

void	check_size(t_game *game)
{
	int	row;
	int	len;
	int	ref_len;

	row = 0;
	ref_len = ft_strlen(game->array[0]);
	while (game->array[row])
	{
		len = ft_strlen(game->array[row]);
		if (len != ref_len)
			ft_error("Error: map is not rectangular");
		row++;
	}
	game->x = ref_len;
}
