/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_checks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:00:00 by you               #+#    #+#             */
/*   Updated: 2025/04/17 12:45:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void check_file_extension(t_game *game)
{
    size_t len = ft_strlen(game->filename);
    if (len < 5
     || game->filename[len-1] != 'r'
     || game->filename[len-2] != 'e'
     || game->filename[len-3] != 'b'
     || game->filename[len-4] != '.')
        ft_error("Error: bad file extension");
}

static void check_rectangular(t_game *game)
{
    size_t w = ft_strlen(game->array[0]);
    for (int i = 1; i < game->y; i++)
        if (ft_strlen(game->array[i]) != w)
            ft_error("Error: map not rectangular");
}

void validate_map(t_game *game)
{
    check_file_extension(game);
    check_rectangular(game);
    check_walls(game);
    check_elements(game);
    check_path(game);
}
