/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Imput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:15:46 by basile            #+#    #+#             */
/*   Updated: 2025/04/17 16:35:21 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

// Gere les input envoyer par mlx_key_hook et appel les fonction néscéssaire //
int handle_imput(int keycode, t_game *game)
{
    ft_printf("key being pressed : %i,\n", keycode);
    if (keycode == 99)
        kill_win(game);
    if ((keycode <= 122) && (keycode >= 100))
        move_player(keycode, game);
    return (0);
}

// En fonction du keycode passer en param par Handle_Imput deplace le joueur et display la map //
int move_player(int keycode, t_game *game)
{
    if ((keycode == 122) && (game->map[game->player_y_pos - 1][game->player_x_pos] != '1' ))
    {
        set_player(game, keycode);
        map_to_textures(game);
    }
    if (keycode == 113 && (game->map[game->player_y_pos][game->player_x_pos - 1] != '1' ))
    {
        set_player(game, keycode);
        map_to_textures(game);
    }
    if (keycode == 115 && (game->map[game->player_y_pos + 1][game->player_x_pos] != '1' ))
    {
        set_player(game, keycode);   
        map_to_textures(game);
    }
    if (keycode == 100 && (game->map[game->player_y_pos][game->player_x_pos + 1] != '1' ))
    {
        set_player(game, keycode);   
        map_to_textures(game);
    }
    return (1);
}

// potentielement redondant mais set la position du joueur sur la carte et reset l'ancienne possition //
int set_player(t_game * game, int keycode)
{
    if ((keycode == 122) && (1 == check_next_case(game->map[game->player_y_pos - 1][game->player_x_pos], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos -= 1][game->player_x_pos] = 'P';
    }
    if (keycode == 113 && (check_next_case(game->map[game->player_y_pos][game->player_x_pos - 1], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos][game->player_x_pos -= 1] = 'P';
    }
    if (keycode == 115 && (1 == check_next_case(game->map[game->player_y_pos + 1][game->player_x_pos], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos += 1][game->player_x_pos] = 'P';
    }
    if (keycode == 100 && (1 == check_next_case(game->map[game->player_y_pos][game->player_x_pos + 1], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos][game->player_x_pos += 1] = 'P';
    }
    return (1);
}

// check si la prochaine case est un mur, un collectible ou la sortie //
// et autorise ou non le déplacement //
int check_next_case(char next_case, t_game *game)
{
    if (next_case == '1')
        return (0);
    if (next_case == 'C')
        game->collectible_count += 1;
    if (next_case == 'E')
    {
        if (game->collectible_count == game->collectible_max)
        {
            ft_printf("felicitation vous avez fini le niveau !\n");
            kill_win(game);
            return (1);
        }
        else
            return (0);
    }
    return (1);
}
