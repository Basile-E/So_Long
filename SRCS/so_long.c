/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:50:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/05/25 01:21:18 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	init_game(t_game *game)
// {
// 	game = init_game_textures(game);
// 	game->mlx_ptr = mlx_init();
// 	game->map = map_extractor(av[1]);
// }

#include "So_Long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_putstr_fd("Error\nGame Malloc failed\n", 2), 2);
	game = init_game_textures(game);
	game->mlx_ptr = mlx_init();
	game->map = map_extractor(av[1]);
	Init_Textures(game);
	map_to_display(game->map, game);
	map_to_possition(game);
	count_max_collectible(game);
	if (ac != 2 || !game->map)
		return (ft_putstr_fd("Error\nat first line, boulet\n", 2), kill_win(game));
	if (!is_ber_file(av[1]))
		return (ft_putstr_fd("Error\nFile must be a .ber\n", 2), kill_win(game), 1);
	if (!game->mlx_ptr)
		return (ft_putstr_fd("Error\nd'initialisation de la MiniLibX\n", 2),
				kill_win(game));
	if (!game->wall)
		return (ft_putstr_fd("Error\nd'initialisation de l'image\n", 2),
				kill_win(game));
	count_max_collectible(game);
	if (1 != is_valid_map(game))
		return (ft_putstr_fd("Error\nMap invalide\n", 2), kill_win(game));
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->display_size_x,
		game->display_size_y, av[0]);
	map_to_textures(game);
	mlx_hook(game->win_ptr, DestroyNotify, KeyPressMask, kill_win, game);
	mlx_key_hook(game->win_ptr, handle_imput, game);
	mlx_loop(game->mlx_ptr);
	kill_win(game);
	return (0);
}
