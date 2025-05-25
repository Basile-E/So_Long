/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 01:00:22 by baecoliv          #+#    #+#             */
/*   Updated: 2025/05/25 02:08:14 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int	is_ber_file(const char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b' || filename[len
			- 2] != 'e' || filename[len - 1] != 'r')
		return (0);
	return (1);
}

void	kill_textures(t_game *game)
{
	if (game)
	{
		if (game->wall)
			mlx_destroy_image(game->mlx_ptr, game->wall);
		if (game->ground)
			mlx_destroy_image(game->mlx_ptr, game->ground);
		if (game->collectible)
			mlx_destroy_image(game->mlx_ptr, game->collectible);
		if (game->player)
			mlx_destroy_image(game->mlx_ptr, game->player);
		if (game->exit)
			mlx_destroy_image(game->mlx_ptr, game->exit);
	}
}

// Kill tout les proccessus et s'assure que tout est free
int	kill_win(t_game *game)
{
	int	i;

	i = 0;
	if (game)
	{
		kill_textures(game);
		if (game->map)
		{
			while (game->map[i])
			{
				free(game->map[i]);
				i++;
			}
			free(game->map);
		}
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
			mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		free(game);
		exit(1);
	}
	return (1);
}
