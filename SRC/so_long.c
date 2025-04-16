/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:50:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/04/16 16:07:57 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"


int main(int ac, char **av)
{
    t_game      *game;
    t_mlx       *mlx;
    t_textures  *textures;

    game = malloc(sizeof(t_game));
    mlx = malloc(sizeof(t_mlx));
    textures = malloc(sizeof(t_textures));
    if (!textures || !mlx || !game)
        return (ft_printf("error while first malloc, boulet\n"));
    if (ac != 2)
        return(ft_printf("usage : ./So_Long <mapfile.txt>, boulet\n"));
    // initialise la mlx //    
    mlx->mlx_ptr = mlx_init();
    if (!mlx->mlx_ptr)
        return(ft_printf("erreur d'initialisation de la MiniLibX\n"));
    // place les textures dans la struct pour les utiliser plus tard //   
    Init_Textures(textures, mlx);
    if (!textures->wall)
        return(ft_printf("erreur d'initialisation de l'image\n"));
    // pars la map, l'ajoute a la struct et calcul la taille de l'écran //
    game->map = map_extractor(av[1]);
    map_to_display(game->map, textures);
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, textures->display_size_x, textures->display_size_y, av[0]);
    //au dessus c'est good//
   
   
    // Danger Zone //
    map_to_textures(game, textures, mlx);




    // int ctr = 10;
    // int X = 0;
    // while(ctr > 0)
    // { 
    //     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, textures->wall, X, 0);
    //     X +=textures->tile_size_x;
    //     ft_printf("texture.tile_size = %d\n", textures->tile_size_x);
    //     ft_printf("x = %d\n", X);
	//     ctr--;
    // } //boucle troubleshoot de img basiquement sera remplacer par l'affichage de la carte et des textures
    


    //basiquement ok, a voir au moment des fonctions d'imput//
    mlx_hook(mlx->win_ptr, DestroyNotify, KeyPressMask, kill_win, mlx);
    mlx_key_hook(mlx->win_ptr, handle_imput, mlx);
    mlx_loop(mlx->mlx_ptr);
    return 0;
}
