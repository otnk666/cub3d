#include "cub3d.h"

int check_filename(char* filename)
{
    char* extention;
    int diff;

    if (!filename)
        return (0);
    extention = ft_strchr(filename, '.');
    if (!extention)
        return (0);
    diff = ft_strncmp(extention, ".cub", 4);
    if(diff)
        return (0);
    return(1);
}

void init_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->img = NULL;
    game->tex.no = NULL;
    game->tex.so = NULL;
    game->tex.we = NULL;
    game->tex.ea = NULL;
    game->floor.r = -1;
    game->floor.g = -1;
    game->floor.b = -1;
    game->ceiling.r = -1;
    game->ceiling.g = -1;
    game->ceiling.b = -1;
    game->map.grid = NULL;
    game->map.width = -1;
    game->map.height = -1;
}

int main (int argc, char* argv[])
{
    t_game game;

    if (argc != 2)
        perror_and_exit("Error: usage: ./cub3d file.cub3d", NULL);
    
    if (!check_filename(argv[1]))
         perror_and_exit("Error: usage: ./cub3d file.cub3d", NULL);
    
    init_game(&game);
    parse(argv[1],&game);

    printf("%s\n", game.tex.no);
    printf("%s\n", game.tex.so);
    printf("%s\n", game.tex.we);
    printf("%s\n", game.tex.ea);
    printf("%d,%d,%d\n", game.floor.r, game.floor.g, game.floor.b);
    printf("%d,%d,%d\n", game.ceiling.r, game.ceiling.g, game.ceiling.b);
    int i = 0; 
    while(i < game.map.height)
    {
        printf("%s", game.map.grid[i++]);
    }
}