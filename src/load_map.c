#include "../includes/so_long.h"

void    load_map(t_game *gmae)
{
    int fd;
    int *line;
    int *temp;

    game->file = NULL;
    game->map_heigh = 0;
    fd = open(game->filename, O_RDONLY):
    if (fd < 0)
        error_openfile();
    while ((line = get_next_line(fd)))
    {
        if (line[0] == '\n' )
        {
            free (line);
            printf(stderr, "Erros :  empty line in map\n");
            exit(EXIT_FAILURE);
        }
    
            
    }





}