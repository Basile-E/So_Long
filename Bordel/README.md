# So-Long

[]
{}

il me faut un fonction qui init la player position et la possition des collectibles
elle prend la game en input et parse la map en cherchan p, un fois qu'il est dessus il set la player pos idem pour les collectible 

il faudrais que cette fonction change le fichier de la map

dans la fonction handle_imput :
si keycode == 122
    move_player(keycode, t_game *game) 
etc 

move_player(keycode, t_game *game)
if (keycap == 122 (up))
    game.map[player_pos_x][player_pos_y + 1] = game.map[player_pos_x][player_pos_y]
    update player pos
etc


possible probleme avec le fait d'avor une struct diff pour game et mlx je peux les mettre ensemble 

# To-Do #


[  ]    faire les fonctions de creation des sprites en partant d'un tableau

[  ]    si possible : faire la fonction qui envoie les sprites a la fenetre tout les x fois par seconde (on peut choisire ?)

[X]     faire la fonction de parsing de map pour en faire un tableau

[  ]    faire les fonction de gestion des input : ctrl + c, w, a, s, d, close win

[  ]    faire une fonction qui lie un keyhook type "w" a une fonction qui modifie la map pour monter le joueur d'une case

[  ]    trouver des textures qui ont pas les bords chelou, ou comprendre comment m'en servir

[  ]    faire un clean du main, ajouter les variables nécessaire a des struct dans le .h et supprimer le rest ou l'envoyer dans ./test/

[  ]    monter les structures nécéssaires

[  ]    je peux potentiellement faire un strlen de mon premier appel a gnl sur current line pour avoir la longeure de la fenetre en multipliant par 64

[  ]    je peux avoir le y en comptant le nombre de ligne dans char ** map

[  ]    faire une structure d'affichage qui a ses param


# Fichiers #

Handle_Win.c :  gere les fonctions de la fenettre, kill_win, map_to_img, display_img
Handle_Imputs : toutes les fonction des imputs
Handle_Map :    les fonction de parsing de la map, de modification apres input de l'utilisateur   

# For the shit and gigles #

[X]    faire un color code pour du beau turquoise dans le make file

[X]    faire un effet dégradé de couleur comme le logo homyzsh sur l'ascii art

[  ]    faire un ascii art pour le makefile de la libft


