/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Imput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:15:46 by basile            #+#    #+#             */
/*   Updated: 2025/04/18 09:40:47 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

// Gere les input envoyer par mlx_key_hook et appel les fonction néscéssaire //
int handle_imput(int keycode, t_game *game)
{
    ft_printf("keycode : %i\n", keycode);
    if (keycode == 65307)
        kill_win(game);
    if ((keycode <= 119) && (keycode >= 97))
        move_player(keycode, game);
    return (0);
}

// En fonction du keycode passer en param par Handle_Imput deplace le joueur, augmente le compteur de move et display la map //
int move_player(int keycode, t_game *game)
{
    if ((keycode == 119) && (game->map[game->player_y_pos - 1][game->player_x_pos] != '1' ))
    {
        set_player(game, keycode);
        map_to_textures(game);
        game->move_count += 1;
    }
    if (keycode == 97 && (game->map[game->player_y_pos][game->player_x_pos - 1] != '1' ))
    {
        set_player(game, keycode);
        map_to_textures(game);
        game->move_count += 1;
    }
    if (keycode == 115 && (game->map[game->player_y_pos + 1][game->player_x_pos] != '1' ))
    {
        set_player(game, keycode);   
        map_to_textures(game);
        game->move_count += 1;
    }
    if (keycode == 100 && (game->map[game->player_y_pos][game->player_x_pos + 1] != '1' ))
    {
        set_player(game, keycode);   
        map_to_textures(game);
        game->move_count += 1;
    }
    return (1);
}

// potentielement redondant mais set la position du joueur sur la carte et reset l'ancienne possition //
int set_player(t_game * game, int keycode)
{
    if ((keycode == 119) && (1 == check_next_case(game->map[game->player_y_pos - 1][game->player_x_pos], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos -= 1][game->player_x_pos] = 'P';
        ft_printf("Movement Count : %i\n", game->move_count);
    }
    if (keycode == 97 && (check_next_case(game->map[game->player_y_pos][game->player_x_pos - 1], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos][game->player_x_pos -= 1] = 'P';
        ft_printf("Movement Count : %i\n", game->move_count);
    }
    if (keycode == 115 && (1 == check_next_case(game->map[game->player_y_pos + 1][game->player_x_pos], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos += 1][game->player_x_pos] = 'P';
        ft_printf("Movement Count : %i\n", game->move_count);
    }
    if (keycode == 100 && (1 == check_next_case(game->map[game->player_y_pos][game->player_x_pos + 1], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos][game->player_x_pos += 1] = 'P';
        ft_printf("Movement Count : %i\n", game->move_count);
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
