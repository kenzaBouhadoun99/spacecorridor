/**
 * \file constantes.h
 * \brief listes des constantes utilisée dans le jeu
 * \author Hugues Steiner
 * \version 1.0
 * \date 7 avril 2021
 */


#ifndef CONSTANTES_H
#define CONSTANTES_H

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 300

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 480

/**
 * \brief Taille d'un vaisseau
 */

#define SHIP_SIZE 32

/**
 * \brief Taille d'un météorite
*/
#define METEORITE_SIZE 32

/**
 * \brief Taille d'un missile
*/
#define MISSILES_SIZE 10

/**
 * \brief Hauteur de la ligne d'arrivée
 */
#define FINISH_LINE_HEIGHT 10

/**
 * \brief Pas de déplacement horizontal du vaisseau
*/
#define MOVING_STEP 8

/**
  * \brief Vitesse initiale de déplacement vertical des éléments du jeu
*/
#define INITIAL_SPEED 2

/**
 * \brief Nombre de mur maximal
*/
#define MAX_MUR 20

/**
 * \brief Nombre maximum de missiles
 */
#define MAX_MISSILES 50

/**
 * \brief Vitesse de déplacement des missiles
 */
#define VITESSE_MISSILES 7

/**
 * \brief nombre de niveau dans le jeu
 */
#define NIVEAU_MAX 3

#endif
