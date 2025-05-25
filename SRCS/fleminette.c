/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fleminette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 01:55:20 by baecoliv          #+#    #+#             */
/*   Updated: 2025/05/25 02:05:06 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

void	fleminette(int keycode, t_game *game)
{
	set_player(game, keycode);
	map_to_textures(game);
	game->move_count += 1;
}

void	textinette(t_game *game, int y, int x)
{			
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall, (x * 64), (y * 64));
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->ground, (x * 64), (y * 64));
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player, (x * 64), (y * 64));
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collectible, (x * 64), (y * 64));
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit, (x * 64), (y * 64));
}
