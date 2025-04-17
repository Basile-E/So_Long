/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Imput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:15:46 by basile            #+#    #+#             */
/*   Updated: 2025/04/17 14:58:58 by basile           ###   ########.fr       */
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

int set_player(t_game * game, int keycode)
{
    if ((keycode == 122) && (1 == check_next_case(game->map[game->player_y_pos - 1][game->player_x_pos], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos -= 1][game->player_x_pos] = 'p';
    }
    if (keycode == 113 && (check_next_case(game->map[game->player_y_pos][game->player_x_pos - 1], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos][game->player_x_pos -= 1] = 'p';
    }
    if (keycode == 115 && (1 == check_next_case(game->map[game->player_y_pos + 1][game->player_x_pos], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos += 1][game->player_x_pos] = 'p';
    }
    if (keycode == 100 && (1 == check_next_case(game->map[game->player_y_pos][game->player_x_pos + 1], game)))
    {
        game->map[game->player_y_pos][game->player_x_pos] = '0';
        game->map[game->player_y_pos][game->player_x_pos += 1] = 'p';
    }
    return (1);
}

// si la ligne de set_player est trop longue
// je peux passer toute la map et faire le calcul dans la fonction
int check_next_case(char next_case, t_game *game)
{
    if (next_case == '1')
        return (0);
    if (next_case == 'c')
        game->collectible_count += 1;
    if (next_case == 'e')
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
