# So-Long

[]
{}
||


il manque :

[X]l'affichage du nombre de déplacement
[X] esc pour quiter le jeu 
[] verifier que la map a au moins : une sortie, un collectible, un stater pos et quelle est bien entourer de murs 
[X] les messages d'erreurs doivent etre Errror\n suite du message


est-ce que c'est illegal :

d'avoir des leak ?
que le So Long puisse prendre des map.txt ?
 
# To-Do #


[X]    faire les fonctions de creation des sprites en partant d'un tableau

[X]    si possible : faire la fonction qui envoie les sprites a la fenetre tout les x fois par seconde (on peut choisire ?)

[X]     faire la fonction de parsing de map pour en faire un tableau

[X]    faire les fonction de gestion des input : esc, w, a, s, d, close win

[X]    faire une fonction qui lie un keyhook type "w" a une fonction qui modifie la map pour monter le joueur d'une case

[X]    trouver des textures qui ont pas les bords chelou, ou comprendre comment m'en servir

[X]    faire un clean du main, ajouter les variables nécessaire a des struct dans le .h et supprimer le rest ou l'envoyer dans ./test/

[X]    monter les structures nécéssaires

[X]    je peux potentiellement faire un strlen de mon premier appel a gnl sur current line pour avoir la longeure de la fenetre en multipliant par 64

[X]    je peux avoir le y en comptant le nombre de ligne dans char ** map

[X]    faire une structure d'affichage qui a ses param


# Fichiers #

[X] Backtracking.c : gere tout le backtracking pour les verifications du mapfile
[X] Handle_Win.c :  gere les fonctions de la fenettre, kill_win, map_to_img, display_img
[X] Handle_Imputs : toutes les fonction des imputs
[X] Handle_Map :    les fonction de parsing de la map, de modification apres input de l'utilisateur   

# For the shit and gigles #

[X]    faire un color code pour du beau turquoise dans le make file

[X]    faire un effet dégradé de couleur comme le logo homyzsh sur l'ascii art

[ ]   faire un ascii art pour le makefile de la libft


