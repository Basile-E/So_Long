/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:42 by basile            #+#    #+#             */
/*   Updated: 2025/04/17 14:46:11 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"
// Kill tout les proccessus et s'assure que tout est free
int kill_win(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr,game->win_ptr);// good mais ne termine pas le program
    free(game->mlx_ptr);
    exit(0);
    return (0);
}
// permet de connaitre la taille du display en x et y pour mlx_nez_window
t_game *map_to_display(char **map, t_game *game)
{
    int x;
    int y;

    x = ft_strlen(map[0]);
    y = 0;
    while (map[y] != NULL)
        y++;
    game->display_size_y = y * TILE_SIZE;
    game->display_size_x = x * TILE_SIZE;

    return (game);
}

t_game *Init_Textures(t_game *game)
{
    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "test/Water.xpm",&game->tile_size_x ,&game->tile_size_y);
    game->player = mlx_xpm_file_to_image(game->mlx_ptr, "test/Player.xpm",&game->tile_size_x ,&game->tile_size_y);
    game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "test/Ground.xpm",&game->tile_size_x ,&game->tile_size_y);
    game->collectible = mlx_xpm_file_to_image(game->mlx_ptr, "test/Collectible.xpm",&game->tile_size_x ,&game->tile_size_y);
    game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "test/Exit.xpm",&game->tile_size_x ,&game->tile_size_y);
    return (game);
}
