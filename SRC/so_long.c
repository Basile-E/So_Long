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

    game = malloc(sizeof(t_game));
    if (!game)
        return (ft_printf("error while first malloc, boulet\n"));
    if (ac != 2)
        return(ft_printf("usage : ./So_Long <mapfile.txt>, boulet\n"));
    // initialise la mlx //    
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        return(ft_printf("erreur d'initialisation de la MiniLibX\n"));
    // place les textures dans la struct pour les utiliser plus tard //   
    Init_Textures(game);
    if (!game->wall)
        return(ft_printf("erreur d'initialisation de l'image\n"));
    // pars la map, l'ajoute a la struct et calcul la taille de l'écran //
    game->map = map_extractor(av[1]);
    map_to_display(game->map, game);
    game->win_ptr = mlx_new_window(game->mlx_ptr, game->display_size_x, game->display_size_y, av[0]);
    // display la map qu'on lui envoi //
    map_to_textures(game);
    //au dessus c'est good//
    map_to_possition(game);
   
    // Danger Zone //


    //basiquement ok, a voir au moment des fonctions d'imput//
    mlx_hook(game->win_ptr, DestroyNotify, KeyPressMask, kill_win, game);
    mlx_key_hook(game->win_ptr, handle_imput, game);
    mlx_loop(game->mlx_ptr);
    return 0;
}

