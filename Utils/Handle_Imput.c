/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Imput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:15:46 by basile            #+#    #+#             */
/*   Updated: 2025/04/16 14:54:57 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int handle_imput(int keycode, t_game *game)
{
    ft_printf("key being pressed : %i,\n", keycode);
    if (keycode == 99)
        kill_win(game);
    if ((keycode <= 122) && (keycode >= 100))
        move_player(keycode, game);
    return (0);
}

int move_player(int keycode, t_game *game)
{
    //map_to_possition(game);
    if ((keycode == 122) && (game->map[game->player_y_pos - 1][game->player_x_pos] != '1' ))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos - 1][game->player_x_pos] = 'p';
        game->player_y_pos -= 1;
        map_to_textures(game);
        print_map_terminal(game);
    }
    if (keycode == 113 && (game->map[game->player_y_pos][game->player_x_pos - 1] != '1' ))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos][game->player_x_pos - 1] = 'p';
        game->player_x_pos -= 1;
        map_to_textures(game);
        print_map_terminal(game);
    }
    if (keycode == 115 && (game->map[game->player_y_pos + 1][game->player_x_pos] != '1' ))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos + 1][game->player_x_pos] = 'p';
        game->player_y_pos += 1;
        map_to_textures(game);
        print_map_terminal(game);
    }
    if (keycode == 100 && (game->map[game->player_y_pos][game->player_x_pos + 1] != '1' ))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos][game->player_x_pos + 1] = 'p';
        game->player_x_pos += 1;
        map_to_textures(game);
        print_map_terminal(game);
    }
    return (1);
}

// faire une fonction pour les modification de la carte 