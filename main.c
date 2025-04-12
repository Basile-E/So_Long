/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:50:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/04/11 11:19:23 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MinilibX/mlx.h" 
#include <unistd.h>
#include <stdlib.h>

// DANGER ZONE // 
#include <stdio.h>
#include <X11/X.h>

typedef struct          s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
}                       t_mlx_data;

int key_hook(int keycode, t_mlx_data *data)
{
    printf("hello from Keyhook%i,\n", keycode);
    if (keycode == 99)
    {
        //fonctionne pour kill la win mais seg fault 
        //voir comment correctement free la mlx
        mlx_destroy_display(data->win_ptr);
        free(data->mlx_ptr);// le seg fault viens probablement de la
    }
    
    return (0);
}

int kill_win(t_mlx_data *data)
{
    mlx_destroy_window(data->mlx_ptr,data->win_ptr);// good mais ne termine pas le program
    free(data->mlx_ptr);
    exit(0);
    return 0;
}

int main(int ac, char **av)
{
    t_mlx_data data;
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 720, 720, "So_Long");
    
    if (!data.mlx_ptr)
    {
        write(2, "erreur d'initialisation de la MiniLibX", 39);
        return(1);
    }
 
    int height;
    int width;
    int ctr;
    int offset;
    int X;
    int Y;
    

    height  = 640;
    width   = 640; // taille de 10 tiles de long et large
    ctr = 10; // juste pour des test
    offset = 64; // taille d'une tile 
    X = 0;
    Y = 0;
    
    //data.img = mlx_png_file_to_image(); Mensonge !!!
    data.img = mlx_xpm_file_to_image(data.mlx_ptr, "/home/baecoliv/Documents/Common Core/So_Long/Textures/test/Water.xpm", &width, &height);
    if (!data.img)
    {
        write(2, "erreur d'initialisation de l'image\n", 35);
        return(1);
    }
    //mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
    //mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 64);

    
    
    while(ctr > 0)
    {
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, X, Y);
        X = X + offset;
    }
    
    mlx_hook(data.win_ptr, DestroyNotify, KeyPressMask, kill_win, &data);
    //mlx_hook(data.win_ptr, 2, 1L<<0, close, &data);
    //mlx_key_hook(data.win_ptr, key_hook, &data);
    //mlx_hook(data.win_ptr, ON_DESTROY, 0, close, &data);
    mlx_loop(data.mlx_ptr);
    return 0;
}
