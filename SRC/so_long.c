/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:50:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/04/18 09:48:18 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"


int main(int ac, char **av)
{
    t_game      *game;

    game = malloc(sizeof(t_game));
    if (!game || ac != 2)
        return (ft_printf("Error\nwhile first malloc, boulet\n"));
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        return(ft_printf("Error\nd'initialisation de la MiniLibX\n")); 
    Init_Textures(game);
    if (!game->wall)
        return(ft_printf("Error\nd'initialisation de l'image\n"));
    game->map = map_extractor(av[1]);
    map_to_display(game->map, game);
    game->win_ptr = mlx_new_window(game->mlx_ptr, game->display_size_x, game->display_size_y, av[0]);
    map_to_textures(game);
    map_to_possition(game);
    count_max_collectible(game);
    if (1 != is_valid_map(game))
        return (ft_printf("Error\nMap invalide\n"));
    mlx_hook(game->win_ptr, DestroyNotify, KeyPressMask, kill_win, game);
    mlx_key_hook(game->win_ptr, handle_imput, game);
    mlx_loop(game->mlx_ptr);
    return 0;
}
