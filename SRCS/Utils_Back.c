/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:57:18 by baecoliv          #+#    #+#             */
/*   Updated: 2025/05/25 00:59:09 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

char	**copy_map(char **map, int rows)
{
    char	**map_copy;
    int		i;

    map_copy = malloc(sizeof(char *) * (rows + 1));
    if (!map_copy)
        return (NULL);
    i = 0;
    while (map[i])
    {
        map_copy[i] = ft_strdup(map[i]);
        if (!map_copy[i])
        {
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            return (NULL);
        }
        i++;
    }
    map_copy[i] = NULL;
    return (map_copy);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_all_collectibles(t_game *game)
{
    char	**map_copy;
    int		i;
    int		j;
    int		result;

    map_copy = copy_map(game->map, game->rows);
    if (!map_copy)
        return (0);
    flood_fill(map_copy, game->player_x_pos, game->player_y_pos, 
            game->cols, game->rows);
    result = 1;
    i = 0;
    while (i < game->rows)
    {
        j = 0;
        while (j < game->cols)
        {
            if (map_copy[i][j] == 'C')
                result = 0;
            j++;
        }
        i++;
    }
	free_map(map_copy, game->rows);
    return (result);
}

// Vérifie si les bords de la map sont bien des '1'
int	check_map_borders(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < cols)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

// Check if map is rectangular (all lines same length)
int	check_map_rectangle(char **map)
{
	int	first_len;
	int	i;

	if (!map || !map[0])
		return (0);
	first_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_len)
			return (0);
		i++;
	}
	return (1);
}
