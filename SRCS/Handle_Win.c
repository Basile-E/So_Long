/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:42 by basile            #+#    #+#             */
/*   Updated: 2025/05/25 02:07:42 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

// permet de connaitre la taille du display en x et y pour mlx_nez_window
t_game	*map_to_display(char **map, t_game *game)
{
	int	x;
	int	y;

	x = ft_strlen(map[0]);
	y = 0;
	while (map[y] != NULL)
		y++;
	game->display_size_y = y * TILE_SIZE;
	game->display_size_x = x * TILE_SIZE;
	return (game);
}

//  Initialise les Textures dans la struct //
t_game	*init_textures(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Water.xpm",
			&game->tile_size_x, &game->tile_size_y);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Player.xpm",
			&game->tile_size_x, &game->tile_size_y);
	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Ground.xpm",
			&game->tile_size_x, &game->tile_size_y);
	game->collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"Textures/Collectible.xpm", &game->tile_size_x, &game->tile_size_y);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "Textures/Exit.xpm",
			&game->tile_size_x, &game->tile_size_y);
	return (game);
}

// Initialize game struct texture elements to NULL
t_game	*init_game_textures(t_game *game)
{
	if (!game)
		return (NULL);
	game->wall = NULL;
	game->ground = NULL;
	game->player = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->win_ptr = NULL;
	game->move_count = 0;
	game->collectible_count = 0;
	game->collectible_max = 0;
	game->player_x_pos = 0;
	game->player_y_pos = 0;
	return (game);
}

int	check_map_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
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
	return (game->player_count == 1 && game->exit_count == 1
		&& game->coll_count > 0);
}
