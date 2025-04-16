/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:25 by basile            #+#    #+#             */
/*   Updated: 2025/04/16 16:09:16 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int open_file(const char *file_name)
{
    int fd;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error: Failed to open the map file\n", 35);
        return (-1);
    }

    return(fd);
}


// faut en fait un appel depuis main en lui passant la structure game en param
// fonctionne !! 
char **map_extractor(char *map_name)
{
    int     fd;
    char    *current_line;
    char    *temp;
    char    **map;

    fd = open_file(map_name);
    if (fd == -1)
        return (NULL);
    
    current_line = get_next_line(fd);
    while(current_line)
    {
        temp = get_next_line(fd);
        if (!temp)
            break;
        current_line = ft_strjoin(current_line, temp);
    }
    map = ft_split(current_line, '\n');
    free(temp);
    return (map);
}

int map_to_textures(t_game *game)
{
    int x;
    int y;
    int print_x;
    int print_y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            print_x = x * game->tile_size_x;
            print_y = y * game->tile_size_y;
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall, (print_x), (print_y));
                if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->ground, (print_x), (print_y));
            if (game->map[y][x] == 'p')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player, (print_x), (print_y));
            x++;
        }
        y++;
    }
    return (1);
}
// sert a récupérer la possition du joueur // 
// il faut une fonction qui met a jour la map //
int map_to_possition(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            if (game->map[y][x] == 'p')
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

// prendre le code au dessus et faire une fonction set player possition

int print_map_terminal(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        ft_printf("%s\n",game->map[y]);
        y++;
    }
    return (1);
}