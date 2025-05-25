/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:50:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/05/25 02:12:42 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

static int	init_and_validate(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (ft_putstr_fd("Error\nUsage: ./so_long <map.ber>\n", 2), 1);
	if (!is_ber_file(av[1]))
		return (ft_putstr_fd("Error\nFile must be a .ber\n", 2), 1);
	game = init_game_textures(game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_putstr_fd("Error\nMLX initialization failed\n", 2), 1);
	game->map = map_extractor(av[1]);
	if (!game->map)
		return (ft_putstr_fd("Error\nMap loading failed\n", 2), 1);
	init_textures(game);
	if (!game->wall)
		return (ft_putstr_fd("Error\nTexture loading failed\n", 2), 1);
	return (0);
}

static int	setup_map(t_game *game, char *title)
{
	map_to_display(game->map, game);
	map_to_possition(game);
	count_max_collectible(game);
	if (1 != is_valid_map(game))
		return (ft_putstr_fd("Error\nMap invalide\n", 2), 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->display_size_x,
			game->display_size_y, title);
	if (!game->win_ptr)
		return (ft_putstr_fd("Error\nWindow creation failed\n", 2), 1);
	map_to_textures(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_putstr_fd("Error\nGame Malloc failed\n", 2), 2);
	if (init_and_validate(game, ac, av))
		return (kill_win(game));
	if (setup_map(game, "So_Long"))
		return (kill_win(game));
	mlx_hook(game->win_ptr, DestroyNotify, KeyPressMask, kill_win, game);
	mlx_key_hook(game->win_ptr, handle_imput, game);
	mlx_loop(game->mlx_ptr);
	kill_win(game);
	return (0);
}
