/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:25 by basile            #+#    #+#             */
/*   Updated: 2025/05/22 21:50:57 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

// open le file présent a l'adresse envoyer en param //
int	open_file(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFailed to open the map file\n", 35);
		return (-1);
	}
	return (fd);
}

// Passe la map .ber en char ** map //
char	**map_extractor(char *map_name)
{
	int		fd;
	char	*current_line;
	char	*old_line;
	char	*temp;
	char	**map;

	fd = open_file(map_name);
	if (fd == -1)
		return (NULL);
	current_line = get_next_line(fd);
	while (current_line)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		old_line = current_line;
		current_line = ft_strjoin(current_line, temp);
		free(old_line);
		free(temp);
	}
	map = ft_split(current_line, '\n');
	free(current_line);
	close(fd);
	return (map);
}
//  Display la map dans game //
int	map_to_textures(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
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
			x++;
		}
		y++;
	}
	return (1);
}
// sert a récupérer la possition du joueur //
int	map_to_possition(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x_pos = x;
				game->player_y_pos = y;
			}
			x++;
		}
		y++;
	}
	return (1);
}
// conte le nombre de collectible au debut du jeu //
int	count_max_collectible(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->collectible_max += 1;
			x++;
		}
		y++;
	}
	return (1);
}
