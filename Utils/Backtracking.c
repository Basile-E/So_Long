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

    int i = 0;
    while (i < rows)
    {
        visited[i] = ft_calloc(cols, sizeof(int));
        if (!visited[i])
        {
            int j = i - 1;
            while (j >= 0)
            {
                free(visited[j]);
                j--;
            }
            free(visited);
            return NULL;
        }
        i++;
    }
    return visited;
}

// Libère l'array visité 
static void free_visited(int **visited, int rows)
{
    int i = 0;
    while (i < rows)
    {
        ft_free_ptr((char **)&visited[i]);
        i++;
    }
    free(visited);
}

// Vérifie si les bords de la map sont bien des '1'
static int check_map_borders(char **map, int rows, int cols)
{
    int i = 0;
    while (i < rows)
    {
        if (map[i][0] != '1' || map[i][cols - 1] != '1')
            return 0;
        i++;
    }
    int j = 0;
    while (j < cols)
    {
        if (map[0][j] != '1' || map[rows - 1][j] != '1')
            return 0;
        j++;
    }
    return 1;
}

// Renvoi 1 si la map est valide et 0 si elle ne l'est pas 
int is_valid_map(t_game *game)
{
    int **visited;
    game->player_count = 0;
    game->exit_count = 0;
    game->coll_count = 0;
    game->rows = game->display_size_y / game->tile_size_y;
    game->cols = game->display_size_x / game->tile_size_x;
    if (game->cols == game->rows)
        return(0);
    if (!check_map_borders(game->map, game->rows, game->cols))
        return (0);
    if (!check_map_elements(game))
        return (0);
    visited = allocate_visited(game->rows, game->cols);
    if (!visited)
        return (0);
    map_to_possition(game);
    if (!dfs(game->map, visited, game->player_x_pos, game->player_y_pos, game->cols, game->rows))
    {
        free_visited(visited, game->rows);
        return (0);
    }
    free_visited(visited, game->rows);
    return (1);
}

