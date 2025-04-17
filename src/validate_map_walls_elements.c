/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_walls_elements.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:00:00 by you               #+#    #+#             */
/*   Updated: 2025/04/17 13:00:00 by you               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_symbol(t_game *game, char c)
{
	if (c == 'C')
		game->c++;
	else if (c == 'E')
		game->e++;
	else if (c == 'P')
		game->p++;
	else if (c != '0' && c != '1')
		ft_error("Error: invalid map character");
}

void	check_params(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->c = 0;
	game->e = 0;
	game->p = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			check_symbol(game, game->array[y][x]);
			x++;
		}
		y++;
	}
	if (game->c < 1 || game->e < 1 || game->p != 1)
		ft_error("Error: wrong number of map elements");
}

#include "../includes/so_long.h"

void	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->x)
	{
		if (game->array[0][x] != '1'
		 || game->array[game->y - 1][x] != '1')
			ft_error("Error: map not surrounded by top/bottom walls");
		x++;
	}
	y = 0;
	while (y < game->y)
	{
		if (game->array[y][0] != '1'
		 || game->array[y][game->x - 1] != '1')
			ft_error("Error: map not surrounded by side walls");
		y++;
	}
}
