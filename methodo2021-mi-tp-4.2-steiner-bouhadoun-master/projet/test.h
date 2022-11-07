/**
 * \file test.h
 * \brief En-têtes des fonctions de test
 * \author Steiner/Bouhadoun
 * \date 7 avril 2021
 */


#include <stdio.h>
#include <stdlib.h>
#include "sdl2-light.h"
#include "monde.h"
#include "constantes.h"

#ifndef TEST_H
#define TEST_H


 /**
  * \brief fonction qui permet d'afficher les champs d'un sprite
  * \param sprite le sprite à afficher
  */

 void print_sprite(sprite_t *sprite);


/**
 *  \brief Fonction qui test la fonction d'initialisation du sprite
 * \param sprite le sprite à initialiser
 * \param x l'abscisse voulue pour le sprite
 * \param y l'ordonnée voulue pour le sprite
 * \param w la largeur voulue du sprite
 * \param h la hauteur voulue du sprite
 */
void test_init_sprite_param(sprite_t *sprite,int x,int y, int w, int h);

/**
 * \brief Fonction qui appelle la fonction test_init_sprite_param
 */
void test_init_sprite();


/**
  * \brief Fonction qui teste la fonction qui initialise les données du monde du jeu
  * \param world les données du monde
  */

void test_init_data_param(world_t *world);

/**
 * \brief Fonction qui appelle la fonction test_init_data_param
 */
void test_init_data();


/**
  * \brief La fonction qui teste la fonction qui met à jour les données en tenant compte de la physique du monde
  * \param les données du monde
  */
void test_update_data_param(world_t *world);

/**
 * \brief Fonction qui appelle la fonction test_update_data_param
 */
void test_update_data();


/**
  * \brief La fonction qui teste la fonction qui vérifie si le vaisseau dépasse la limite gauche
  * \param sprite le vaisseau
  */
void test_limite_gauche_param(sprite_t*sprite);

/**
 * \brief Fonction qui appelle la fonction test_limite_gauche_param
 */
void test_limite_gauche();


/**
  * \brief La fonction qui teste la fonction qui vérifie si le vaisseau dépasse la limite droite
  * \param sprite le vaisseau
  */
void test_limite_droite_param(sprite_t*sprite);

/**
 * \brief Fonction qui appelle la fonction test_limite_droite_param
 */
void test_limite_droite();


/**
  * \brief La fonction qui teste la fonction qui vérifie si deux sprite sont en collision
  * \param sprite sp1 Le premier sprite
  * \param sprite sp2 Le second sprite sprite
  */
void test_sprites_collide_param(sprite_t* sp1, sprite_t* sp2);

/**
 * \brief Fonction qui appelle la fonction test_sprites_collide_param
 */
void test_sprites_collide();


/**
 * \brief Fonction qui teste la gestion de la collision
 * \param sp1 le premier sprite
 * \param sp2 le deuxième sprite
 * \param world le monde
*/
void test_handle_sprites_collision_param(sprite_t* sp1, sprite_t* sp2, world_t* world, int make_disappear);

/**
 * \brief Fonction qui appelle la fonction de test de la gestion de la collision
 */
void test_handle_sprites_collision();



/**
 * \brief Fonction qui test l'initialisation des murs dans le monde
 * \param world les données du monde
 */
 void test_init_walls_param(world_t* world);

/**
 * \brief Fonction qui appelle la fonction test_init_walls_param
 */
 void test_init_walls();


/**
 * \brief Fonction qui test le déplacement des murs
 * \param world les données du monde
 */
void test_update_walls_param(world_t* world);

/**
 * \brief Fonction qui appelle la fonction test_update_walls_param
 */
void test_update_walls();



#endif
