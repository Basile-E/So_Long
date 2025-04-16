#ifndef SO_LONG
    #define SO_LONG

    // Includes //

#include "../mlx_linux/mlx.h"
#include "../Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h> // define keymask etc 
#include <fcntl.h> // define 0_RDONLY etc
#define TILE_SIZE 64

    // Structs //

typedef struct          s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}                       t_mlx;

typedef struct          s_game
{
    int     collectible_count;
    void    *sprite;
    char    **map;
    int     player_x_pos;
    int     player_y_pos;
    int     win_size_x;
    int     win_size_y;
}                       t_game;

typedef struct          s_textures
{
    void    *wall;
    void    *ground;
    void    *player;
    void    *collectible;
    int     tile_size_x;
    int     tile_size_y; 
    int     display_size_x;
    int     display_size_y;
}                       t_textures;

    // Define //

    // Fonctions //

int kill_win(t_mlx *data);
t_game * map_to_img(t_game);
int handle_imput(int keycode, t_mlx *data);
int open_map(const char *file_name);
char **map_extractor(char *map_name);
t_textures *map_to_display(char **map, t_textures *textures);
t_textures *Init_Textures(t_textures *textures, t_mlx *mlx);
int map_to_textures(t_game *game, t_textures *textures, t_mlx *mlx);

#endif