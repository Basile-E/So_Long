/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:50:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/04/15 18:26:13 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"


int main(int ac, char **av)
{
    t_game game;
    t_mlx_data data;
    game.map_name = av[1];
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "So_Long");
    
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
    

    height  = 64;
    width   = 64; // taille de 10 tiles de long et large
    ctr = 10; // juste pour des test
    offset = 64; // taille d'une tile 
    X = 0;
    Y = 0;
    
    //data.img = mlx_png_file_to_image(); Mensonge !!!
    data.img = mlx_xpm_file_to_image(data.mlx_ptr, "test/Water.xpm", &width, &height);
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
	    ctr--;
    }

    // test de ft_split //
    
    char **result = ft_split("Hello World 42", ' ');
    for (int i = 0; result[i] != NULL; i++)
    {
        ft_printf("%s\n", result[i]);
        free(result[i]); // Libère chaque chaîne
    }
    free(result); // Libère le tableau

    // test de ft_split //
    
    mlx_hook(data.win_ptr, DestroyNotify, KeyPressMask, kill_win, &data);
    
    map_extractor(game);
    
    mlx_key_hook(data.win_ptr, handle_imput, &data);
    mlx_loop(data.mlx_ptr);
    return 0;
}
