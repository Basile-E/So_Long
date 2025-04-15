/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:25 by basile            #+#    #+#             */
/*   Updated: 2025/04/15 18:46:21 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int open_map(const char *file_name)
{
    int fd;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error: Failed to open the map file\n", 32);
        return (-1);
    }

    return(fd);
}


// faut en fait un appel depuis main en lui passant la structure game en param
// fonctionne !! 
char **map_extractor(t_game game)
{
    int     fd;
    char    *line;
    char    *current_line;
    char    *temp;

    fd = open_map(game.map_name);
    if (fd == -1)
        return (NULL);
    
    line = NULL;
    current_line = get_next_line(fd);
    while(current_line)
    {
        temp = line; // Sauvegarde l'ancienne chaîne
        line = ft_strjoin(line, current_line); // Concatène la ligne actuelle
        free(temp); // Libère l'ancienne chaîne
        ft_printf("%s\n", current_line); // troubleshoot 
        free(current_line); // Libère la ligne lue
        current_line = get_next_line(fd); 
    }
    game.map = ft_split(line, '\n');
    free(line);
    return (game.map);
}
