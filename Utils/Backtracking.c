/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:23:14 by basile            #+#    #+#             */
/*   Updated: 2025/04/17 16:34:24 by basile           ###   ########.fr       */
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
    int **visited = malloc(rows * sizeof(int *));
    if (!visited)
        return NULL;

    int i = 0;
    while (i < rows)
    {
        visited[i] = malloc(cols * sizeof(int));
        if (!visited[i])
        {
            int j = i;
            while (--j >= 0)
                free(visited[j]);
            free(visited);
            return NULL;
        }
        int j = 0;
        while (j < cols)
        {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    return visited;
}

// Libere l'array visité 
static void free_visited(int **visited, int rows)
{
    int i = 0;
    while (i < rows)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
}

// Trouve la Pos du joueur //
static int find_player_position(t_game *game, int *player_x, int *player_y)
{
    int y = 0;
    while (y < game->display_size_y / game->tile_size_y)
    {
        int x = 0;
        while (x < game->display_size_x / game->tile_size_x)
        {
            if (game->map[y][x] == 'P')
            {
                *player_x = x;
                *player_y = y;
                return 1;
            }
            x++;
        }
        y++;
    }
    return 0;
}

// Renvoi 1 si la map est valide et 0 si elle ne l'est pas 
int is_valid_map(t_game *game)
{
    int **visited;
    int result = 0;
    int player_x, player_y;
    int rows = game->display_size_y / game->tile_size_y;
    int cols = game->display_size_x / game->tile_size_x;

    visited = allocate_visited(rows, cols);
    if (!visited)
        return 0;

    if (find_player_position(game, &player_x, &player_y))
        result = dfs(game->map, visited, player_x, player_y, cols, rows);

    free_visited(visited, rows);
    return result;
}

