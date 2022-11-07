/**
 * \file monde.h
 * \brief En-tête du module qui gère les données du monde
 * \author Bouhadoun/Steiner
 * \version 1.0
 * \date 7 avril 2021
 */

 #ifndef MONDE_H
 #define MONDE_H


 #include "constantes.h"
 #include "sdl2-light.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>


<<<<<<< HEAD
 /** La fonction qui permet de générer un entier aléatoire entre deux bornes
  * \param a la borne minimum
  * \param b la borne maximum (exclue)
  * \return Un entier aléatoire entre les deux bornes
 */
 int randint(int a, int b);

 /* <! Les structures !> */
=======
/** La fonction qui permet de générer un entier aléatoire entre deux bornes
 * \param a la borne minimum
 * \param b la borne maximum (exclue)
 * \return Un entier aléatoire entre les deux bornes
*/
int randint(int a, int b);
>>>>>>> 620c1bfe81f551d6a6b545e2cff10cc1cacde157

 /**
 *  \brief Représentation d'un sprite
 *  \param x L'abscisse du sprite
 *  \param y L'ordonnée du sprite
 *  \param w La largeur du sprite
 *  \param h La hauteur du sprite
 *  \param c La varialbe qui détermine si le sprite peut entrer en collision (0=non/1=oui)
 */
struct sprite_s {
    int x;
    int y;
    int w;
    int h;
    int c;
};

/**
 * \brief Type qui correspond aux sprites du jeu
*/

typedef struct sprite_s sprite_t;



/**
 * \brief Représentation du monde du jeu
 * \param ship Le sprite correspondant au vaisseau
 * \param finish Le sprite correspondant à la ligne d'arrivée
 * \param tab_mur Un tableau contenant tous les murs du niveau
 * \param tab_missiles Un tableau contenant tous les murs du niveau
 * \param nb_murs Nombre de murs dans le niveau (taille effective de tab_mur)
 * \param nb_missiles Nombre de missiles tirés par le joueur (taille effective de tab_missiles)
 * \param aff_missiles Enregistrement sous forme d'une chaine de caractères du nombre de missiles restant pour le joueur
 * \param temps Temps ecoulé depuis le début du jeu
 * \param aff_temps Enregistrement sous forme d'une chaine de caractères du temps écoulé depuis le début du niveau
<<<<<<< HEAD
 * \param aff_niveau Enregistrement sous forme d'une chaine de caractères du niveau actuel
=======
>>>>>>> 620c1bfe81f551d6a6b545e2cff10cc1cacde157
 * \param temps_initial Temps auquel commence le niveau
 * \param vy La vitesse de déplacements des murs et de la ligne d'arrivée
 * \param etat_fin Champ indiquant comment se finit la partie : 0 : niveau en cours, 1 niveau réussi, 2 niveau perdu, 3 : fin du jeu
 * \param niveau A quel niveau en est le joueur
 * \param rejouer Est-ce qu'on continue à jouer
 * \param gameover Est-ce que le jeu est terminé (fermeture de la fenêtre)
*/
struct world_s{
    sprite_t ship;
    sprite_t finish;
    sprite_t tab_murs[MAX_MUR];
    sprite_t tab_missiles[MAX_MISSILES];
    int nb_murs;
    int nb_missiles;
    char* aff_missiles;
    char* aff_temps;
<<<<<<< HEAD
    char* aff_niveau;
=======
>>>>>>> 620c1bfe81f551d6a6b545e2cff10cc1cacde157
    int temps;
    int temps_initial;
    int vy;
    int etat_fin;
    int niveau;
    char rejouer;
    int gameover;
    };


/**
 * \brief Type qui correspond aux données du monde
 */
typedef struct world_s world_t;

 /* <! Initialisation et nettoyage !> */

 /**
  * \brief La fonction qui initialise les sprites
  * \param sprite le sprite à initialiser
  * \param x l'abscisse voulue pour le sprite
  * \param y l'ordonnée voulue pour le sprite
  * \param w La largeur voulue du sprite
  * \param h La hauteur voulue du sprite
  */
 void init_sprite (sprite_t* sprite, int x, int y, int w, int h);

/**
 * \brief La fonction qui initialise les données du monde du jeu
 * \param world les données du monde
 */
void init_data(world_t *world);


/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */
void clean_data(world_t *world);

/**
 * \brief La fonction initialise les murs du 1er niveau du jeu
 * \param world les données du monde
 */
void init_walls(world_t* world);

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */
int is_game_over(world_t *world);


/**
 * \brief La fonction qui permet de générer un niveau aléatoire
 * \param world les données du monde
 * \param nbMurs le nombre de murs souhaité
 */
void rand_lvl(world_t*world, int nbMurs);



 /* <! Génération des collisions entre sprites et les bords du jeu !> */

/**
  * \brief La fonction qui vérifie si le vaisseau dépasse la limite gauche
  * \param sprite le vaisseau
  */
 void limite_gauche(sprite_t* sprite);


 /**
  * \brief La fonction qui vérifie si le vaisseau dépasse la limite droite
  * \param sprite le vaisseau
  */
 void limite_droite(sprite_t* sprite);


/**
  * \brief La fonction qui vérifie si deux sprite sont en collision
  * \param sprite sp1 Le premier sprite
  * \param sprite sp2 Le second sprite sprite
  */
int sprites_collide(sprite_t* sp1, sprite_t* sp2);


/**
 * \brief La fonction qui gère la collision de deux sprites dans le monde
 * \param sp1 le premier sprite
 * \param sp2 le deuxième sprite
 * \param world les données du monde
 */
void handle_sprites_collision(sprite_t* sp1, sprite_t* sp2, world_t* world, int make_disappear);


 /* <! Rafraichissement et mise a jour !> */

/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */
void update_data(world_t *world);


/**
 * \brief La fonction qui fait bouger les murs du jeu
 * \param world les données du monde
 */
void update_walls(world_t* world); //apdate rafraichissement


/**
 * \brief La fonction qui fait bouger les missiles du jeu
 * \param world les données du monde
 */
void update_missiles(world_t* world);

 #endif
