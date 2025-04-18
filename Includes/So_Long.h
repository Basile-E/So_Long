#ifndef SO_LONG
    #define SO_LONG

    // Includes //

#include "../mlx_linux/mlx.h"
#include "../Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h> // define keymask etc 
#include <fcntl.h> // define 0_RDONLY etc
#define TILE_SIZE 64

    // Structs //

typedef struct          s_game
{
    int     move_count;
    int     collectible_count;
    int     collectible_max;
    void    *sprite;
    char    **map;
    int     player_x_pos;
    int     player_y_pos;
    void    *mlx_ptr;
    void    *win_ptr;
    void    *wall;
    void    *ground;
    void    *player;
    void    *collectible;
    void    *exit;
    int     tile_size_x;
    int     tile_size_y; 
    int     display_size_x;
    int     display_size_y;
    int     rows;
    int     cols;
    int     player_count;
    int     exit_count;
    int     coll_count;
}                       t_game;


    // Define //

    // Fonctions //

int kill_win(t_game *game);
t_game * map_to_img(t_game);
int handle_imput(int keycode, t_game *game);
int open_map(const char *file_name);
char **map_extractor(char *map_name);
t_game *map_to_display(char **map, t_game *game);
t_game *Init_Textures(t_game *game);
int map_to_textures(t_game *game);
int move_player(int keycode, t_game *game);
int map_to_possition(t_game *game);
int print_map_terminal(t_game *game); // troubleshoot
int set_player(t_game * game, int keycode);
int check_next_case(char next_case, t_game *game);
int count_max_collectible(t_game *game);

//backtracking
int is_valid_map(t_game *game);
int check_map_elements(t_game *game);
#endif