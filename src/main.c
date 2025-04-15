#include "../includes/so_long.h"

static void  initialize_and_run(t_game  *game, char *argv)
{
    game->filename = argv[1];
    game->moves = 0;
    game->num_exist = 0;
    game->num_collectibles = 0;
    game->num_players = 0;
    game->player.x = 0;
    game->player.y = 0;
    game->exit = 0;
}

int main(int argc, char argv)
{
    t_game  game;

    if (argc != 2)
    {
        printf (stderr, "Usage: ./so_long   map.ber\n");
        return (EXIT_FAILURE);
    }
    initialize_and_run(&game, argv);
    load_map(game);
    validate_map(game);
    map.mlx = mlx_init();
    map.wnd = mlx_new_window(map.mlx)

    return (0);

}

