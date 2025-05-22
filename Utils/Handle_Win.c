/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:42 by basile            #+#    #+#             */
/*   Updated: 2025/05/22 23:12:18 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

void    kill_textures(t_game *game)
{
    if (game)
    {
        if (game->wall)
            mlx_destroy_image(game->mlx_ptr, game->wall);
        if (game->ground)
            mlx_destroy_image(game->mlx_ptr, game->ground);
        if (game->collectible)
            mlx_destroy_image(game->mlx_ptr, game->collectible);
        if (game->player)
            mlx_destroy_image(game->mlx_ptr, game->player);
        if (game->exit)
            mlx_destroy_image(game->mlx_ptr, game->exit);
    }
}

// Kill tout les proccessus et s'assure que tout est free
int kill_win(t_game *game)
{
    int i;

    i = 0;
    if (game)
    {
        kill_textures(game);
        if (game->map)
        {
            while (game->map[i])
            {
                free(game->map[i]);
                i++;
            }
            free(game->map);
        }
        if (game->win_ptr)
            mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        if (game->mlx_ptr)
            mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
        free(game);
        exit(0);
    }
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

//  Initialise les Textures dans la struct // 
t_game *Init_Textures(t_game *game)
{
    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Water.xpm",&game->tile_size_x ,&game->tile_size_y);
    game->player = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Player.xpm",&game->tile_size_x ,&game->tile_size_y);
    game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Ground.xpm",&game->tile_size_x ,&game->tile_size_y);
    game->collectible = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Collectible.xpm",&game->tile_size_x ,&game->tile_size_y);
    game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Exit.xpm",&game->tile_size_x ,&game->tile_size_y);
    return (game);
}
int check_map_elements(t_game * game)
{
    int y = 0;
    while (y < game->rows)
    {
        int x = 0;
        while (x < game->cols)
        {
            if (game->map[y][x] == 'P')
                (game->player_count)++;
            else if (game->map[y][x] == 'E')
                (game->exit_count)++;
            else if (game->map[y][x] == 'C')
                (game->coll_count)++;
            x++;
        }
        y++;
    }
    return (game->player_count == 1 && game->exit_count > 0 && game->coll_count > 0);
}
