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
        ft_printf("temp apres gnl :\n%s\n", temp);
        current_line = ft_strjoin(current_line, temp),
        ft_printf("current line apres join :\n%s\n", current_line);
    }
    map = ft_split(current_line, '\n');
    free(temp);
    return (map);
}

int map_to_textures(t_game *game, t_textures *s_textures)
{
    
}