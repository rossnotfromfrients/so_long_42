/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodolhop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:25:53 by rodolhop          #+#    #+#             */
/*   Updated: 2025/04/14 17:26:30 by rodolhop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define IMG_PXL    50
# define WND_NAME   "so_long"
# define UP         13
# define DOWN       1
# define LEFT       0
# define RIGHT      2
# define ESC        53

// ───────────────────────────────
// textures: all game sprites
// ───────────────────────────────
typedef struct s_textures
{
    void    *floor;
    void    *collectible;
    void    *wall;
    void    *exit_closed;
    void    *exit_open;
    void    *player_left_1;
    void    *player_right_1;
    void    *player_up_1;
    void    *player_down_1;
    void    *player_left_2;
    void    *player_right_2;
    void    *player_up_2;
    void    *player_down_2;
    void    *enemy;
}   t_textures;

// ───────────────────────────────
// player: coordinates on map
// ───────────────────────────────
typedef struct s_player
{
    int     x;
    int     y;
}   t_player;

// ───────────────────────────────
// main game state
// ───────────────────────────────
typedef struct s_game
{
    // map data
    char        **array;
    char        **copy;
    char        *file;
    char        *filename;

    // map dimensions
    int         x;
    int         y;

    // element counts
    int         e;
    int         c;
    int         p;

    int         c_check;       // how many collectibles reached in validation
    int         e_check;       // exit reached flag in validation
    int         exit_active;   // is exit active (all C collected)
    int         moves;         // player moves count

    // graphics
    void        *mlx;
    void        *wnd;
    t_textures  txtrs;

    // player state
    t_player    player;
}   t_game;

// ───────────────────────────────
// function prototypes
// ───────────────────────────────
void    init_game(t_game *game);
void    load_map(t_game *game);
void    validate_map(t_game *game);
void    start_game(t_game *game);
void    render_map(t_game *game);
void    move_player(t_game *game, int dx, int dy);
int     key_hook(int keycode, t_game *game);
void    close_game(t_game *game);
void    ft_error(char *msg);

#endif

