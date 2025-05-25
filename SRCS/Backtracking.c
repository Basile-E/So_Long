/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:23:14 by basile            #+#             */
/*   Updated: 2025/04/18 10:08:08 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->cols || y >= game->rows || map[y][x] == '1'
		|| map[y][x] == 'F' || map[y][x] == 'E')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

int	check_map_dimensions(t_game *game)
{
	int	max_cols;
	int	max_rows;

	max_cols = 1980 / TILE_SIZE;
	max_rows = 1080 / TILE_SIZE;
	if (game->cols > max_cols || game->rows > max_rows)
	{
		ft_printf("Error\nMap too large for display (max %dx%d tiles)\n",
			max_cols, max_rows);
		return (0);
	}
	return (1);
}

void	init_map_validation(t_game *game)
{
	game->player_count = 0;
	game->exit_count = 0;
	game->coll_count = 0;
	game->rows = game->display_size_y / game->tile_size_y;
	game->cols = game->display_size_x / game->tile_size_x;
}

static int	check_valid_chars(char **map, int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'P'
				&& map[y][x] != 'E' && map[y][x] != 'C')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	is_valid_map(t_game *game)
{
	int	**visited;
	int	is_valid;

	init_map_validation(game);
	if (!check_map_dimensions(game))
		return (0);
	if (!check_map_borders(game->map, game->rows, game->cols))
		return (0);
	if (!check_map_rectangle(game->map))
		return (0);
	if (!check_map_elements(game))
		return (0);
	if (!check_valid_chars(game->map, game->rows, game->cols))
		return (0);
	is_valid = check_all_collectibles(game);
	return (is_valid);
}
