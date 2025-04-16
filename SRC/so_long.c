/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:50:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/04/16 14:30:26 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"


int main(int ac, char **av)
{
    t_game      *game;
    t_mlx_data  *data;
    t_textures  *textures;

    game = malloc(sizeof(t_game));
    data = malloc(sizeof(t_mlx_data));
    textures = malloc(sizeof(t_textures));
    if (!textures || !data || !game)
        return (ft_printf("error while first malloc, boulet\n"));
    if (ac != 2)
        return(ft_printf("usage : ./So_Long <mapfile.txt>, boulet\n"));
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
    return(ft_printf("erreur d'initialisation de la MiniLibX\n"));
    //au dessus c'est good//

    data->img = mlx_xpm_file_to_image(data->mlx_ptr, "test/Water.xpm",&textures->tile_size ,&textures->tile_size);
    if (!data->img)
    return(ft_printf("erreur d'initialisation de l'image\n"));
    game->map = map_extractor(av[1]);
    map_to_display(game->map, textures);
    data->win_ptr = mlx_new_window(data->mlx_ptr, textures->display_size_x, textures->display_size_y, av[0]);
    // Danger Zone //
    
    
    
    int ctr = 10;
    int X = 0;
    while(ctr > 0)
    {
        
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, X, 0);
        X +=textures->tile_size;
        ft_printf("texture.tile_size = %d\n", textures->tile_size);
        ft_printf("x = %d\n", X);
	    ctr--;
    } //boucle troubleshoot de img basiquement sera remplacer par l'affichage de la carte et des textures
    


    //basiquement ok, a voir au moment des fonctions d'imput//
    mlx_hook(data->win_ptr, DestroyNotify, KeyPressMask, kill_win, &data);
    mlx_key_hook(data->win_ptr, handle_imput, &data);
    mlx_loop(data->mlx_ptr);
    return 0;
}
