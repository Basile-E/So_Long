#include "../Includes/So_Long.h"

int main(int ac, char **av)
{
    ft_printf("Bienvenu dans les tests\n");
    
    t_textures  *textures;
    t_game      *game;  

    textures = malloc(sizeof(t_textures));
    if (!textures)
        return (ft_printf("Erreur : allocation mémoire pour textures a échoué\n"));
    game = malloc(sizeof(t_game));
    if (!game)
        return (ft_printf("Erreur : allocation mémoire pour game a échoué\n"));
    game->map = map_extractor(av[1]);
    if (!game->map)
    {
        free(game);
        return (ft_printf("Erreur : map_extractor a échoué\n"));
    }

    map_to_display(game->map, textures);
    ft_printf("Width: %d, Height: %d\n", textures->display_size_x, textures->display_size_y); // troubleshoot
    



    free(game);
    return 0;
}
