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

void	flood_fill(char **map, int x, int y, int max_x, int max_y)
{
    if (x < 0 || y < 0 || x >= max_x || y >= max_y 
        || map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E')
        return;
    
    map[y][x] = 'F';
    
    flood_fill(map, x + 1, y, max_x, max_y);
    flood_fill(map, x - 1, y, max_x, max_y);
    flood_fill(map, x, y + 1, max_x, max_y);
    flood_fill(map, x, y - 1, max_x, max_y);
}

int	check_map_dimensions(t_game *game)
{
	int	max_cols;
	int	max_rows;

	max_cols = 1980 / TILE_SIZE; // 30 tiles maximum width
	max_rows = 1080 / TILE_SIZE; // 16 tiles maximum height
	if (game->cols > max_cols || game->rows > max_rows)
	{
		ft_printf("Error\nMap too large for display (max %dx%d tiles)\n",
			max_cols, max_rows);
		return (0);
	}
	return (1);
}
// Initialize map validation parameters
void	init_map_validation(t_game *game)
{
	game->player_count = 0;
	game->exit_count = 0;
	game->coll_count = 0;
	game->rows = game->display_size_y / game->tile_size_y;
	game->cols = game->display_size_x / game->tile_size_x;
}

// Renvoi 1 si la map est valide et 0 si elle ne l'est pas
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
		return(0);
	is_valid = check_all_collectibles(game);
	return (is_valid);
}
