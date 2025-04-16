/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:42 by basile            #+#    #+#             */
/*   Updated: 2025/04/16 15:55:49 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"
// Kill tout les proccessus et s'assure que tout est free
int kill_win(t_mlx *data)
{
    mlx_destroy_window(data->mlx_ptr,data->win_ptr);// good mais ne termine pas le program
    free(data->mlx_ptr);
    exit(0);
    return (0);
}
// permet de connaitre la taille du display en x et y pour mlx_nez_window
t_textures *map_to_display(char **map, t_textures *textures)
{
    int x;
    int y;

    x = ft_strlen(map[0]);
    y = 0;
    while (map[y] != NULL)
        y++;
    // troubleshoot
    ft_printf("Largeur (x): %d, Hauteur (y): %d\n", x, y);
    // Utiliser x et y pour configurer la fenêtre ou les textures
    textures->display_size_y = y * TILE_SIZE;
    textures->display_size_x = x * TILE_SIZE;
    ft_printf("textures->display_size_y %d\ntextures->display_size_x %d\n", textures->display_size_y, textures->display_size_x);

    return (textures);
}

t_textures *Init_Textures(t_textures *textures, t_mlx *mlx)
{
    textures->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "test/Water.xpm",&textures->tile_size_x ,&textures->tile_size_y);
    textures->player = mlx_xpm_file_to_image(mlx->mlx_ptr, "test/Water.xpm",&textures->tile_size_x ,&textures->tile_size_y);
    return (textures);
}