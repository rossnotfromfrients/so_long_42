#include "../includes/so_long.h"

void	load_map(t_game *game)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error: can't open map file");
	game->file = NULL;
	y = 0;
	while ((line = get_next_line(fd)))
	{
		if (line[0] == '\n')
			ft_error("Error: empty line in map");
		game->file = ft_strjoinfree(game->file, line);
		free(line);
		y++;
	}
	close(fd);
	if (y == 0)
		ft_error("Error: map is empty");
	game->y = y;
	game->array = ft_split(game->file, '\n');
	game->copy = ft_split(game->file, '\n');
	if (!game->array || !game->copy)
		ft_error("Error: map split failed");
}
