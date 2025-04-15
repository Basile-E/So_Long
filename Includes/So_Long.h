#ifndef SO_LONG
    #define SO_LONG

    // Includes //

#include "../mlx_linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>

    // Structs //

typedef struct          s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
}                       t_mlx_data;

    // Define //

    // Fonctions //

int kill_win(t_mlx_data *data);
int handle_imput(int keycode, t_mlx_data *data);

#endif