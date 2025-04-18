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


// Execute le Backtracking //
static int dfs(char **map, int **visited, int x, int y, int max_x, int max_y)
{
    if (x < 0 || y < 0 || x >= max_x || y >= max_y || map[y][x] == '1' || visited[y][x])
        return 0;
    if (map[y][x] == 'E')
        return 1;

    visited[y][x] = 1;

    if (dfs(map, visited, x + 1, y, max_x, max_y) ||
        dfs(map, visited, x - 1, y, max_x, max_y) ||
        dfs(map, visited, x, y + 1, max_x, max_y) ||
        dfs(map, visited, x, y - 1, max_x, max_y))
        return 1;

    return 0;
}

// Alloue la Mémoire 
static int **allocate_visited(int rows, int cols)
{
    int **visited = ft_calloc(rows, sizeof(int *));
    if (!visited)
        return NULL;

    for (int i = 0; i < rows; i++)
    {
        visited[i] = ft_calloc(cols, sizeof(int));
        if (!visited[i])
        {
            while (--i >= 0)
                free(visited[i]);
            free(visited);
            return NULL;
        }
    }
    return visited;
}

// Libere l'array visité 
static void free_visited(int **visited, int rows)
{
    for (int i = 0; i < rows; i++)
        ft_free_ptr((char **)&visited[i]);
    free(visited);
}

// Renvoi 1 si la map est valide et 0 si elle ne l'est pas 
int is_valid_map(t_game *game)
{
    int **visited;
    int result = 0;
    int rows = game->display_size_y / game->tile_size_y;
    int cols = game->display_size_x / game->tile_size_x;

    visited = allocate_visited(rows, cols);
    if (!visited)
        return 0;

    map_to_possition(game); // Remplace find_player_position
    result = dfs(game->map, visited, game->player_x_pos, game->player_y_pos, cols, rows);

    free_visited(visited, rows);
    return result;
}

