#ifndef SO_LONG
    #define SO_LONG

    // Includes //

#include "../mlx_linux/mlx.h"
#include "../Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h> // define keymask etc 
#include <fcntl.h> // define 0_RDONLY etc

    // Structs //

typedef struct          s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
}                       t_mlx_data;

typedef struct          s_game
{
    int     collectible_count;
    void    *sprite;
    char    **map;
    int     player_x_pos;
    int     player_y_pos;
    int     win_size_x;
    int     win_size_y;
    char    *map_name;
}                       t_game;

    // Define //

    // Fonctions //

int kill_win(t_mlx_data *data);
t_game * map_to_img(t_game);
int handle_imput(int keycode, t_mlx_data *data);
int open_map(const char *file_name);
char **map_extractor(t_game game);

#endif