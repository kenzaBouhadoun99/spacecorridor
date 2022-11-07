<<<<<<< HEAD
/**
 * \file graphique.c
 * \brief Affichage graphique du jeu
 * \author Hugues Steiner Bouhadoun Kenza
 * \version 1.0
 * \date 07 avril 2021
 */

#include "constantes.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "monde.h"


#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    TTF_Font* font; /*textures liée a l'image représentant l'affichage du texte*/
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* ship; /*Texture liée à l'image représentant le vaisseau*/
    SDL_Texture* ligneA; /*Texture liée à l'image représentant la ligne d'arrivée*/
    SDL_Texture* meteore; /*Texture liée à l'image représentant la meteore*/
    SDL_Texture* missile;/*Texture liée à l'image représentant le missile*/
};

/**
 * \brief Type qui correspond aux textures du jeu
*/
typedef struct textures_s ressources;

/* <! INITIALISATION ET NETTOYAGE !> */


/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
 */
void init(SDL_Window **window, SDL_Renderer ** renderer, ressources *textures, world_t * world);

/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/
void clean(SDL_Window *window, SDL_Renderer * renderer,ressources *textures, world_t * world);


/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/
void  init_textures(SDL_Renderer *renderer, ressources*textures);

/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/
void clean_textures(ressources*textures) ;

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */
void refresh_graphics(SDL_Renderer *renderer, world_t *world,ressources *textures);


/* <! APPLICATION DE TEXTURES SUR LES SPRITES !> */

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/
void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);


/**
 * \brief La fonction applique la texture associé au sprite sur le renderer
 * \param renderer le renderer
 * \param texture la texture liée au sprite
 * \param sprite le sprite sur lequel appliquer la texture
*/
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) ;


/**
 * \brief La fonction applique la texture associé au mur de météorite sur le renderer
 * \param renderer le renderer
 * \param texture la texture liée au mur
 * \param sprite le mur sur lequel appliquer la texture
*/
void apply_mur(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) ;

/**
 * \brief La fonction applique la texture associé au mur de météorite sur le renderer
 * \param renderer le renderer
 * \param ressource la texture liée au sprite
 * \param world les données du monde
*/
void apply_walls(SDL_Renderer *renderer, SDL_Texture *ressources,world_t* world);


/**
 * \brief La fonction qui applique la texture associé à un missiles sur le renderer
 * \param renderer le renderer
 * \param texture la texture liée au missile
 * \param sprite le missile sur lequel appliquer la texture
 */
void apply_missiles2(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) ;

/**
 * \brief La fonction qui applique la texture associé aux missiles sur le renderer*
 * \param renderer le renderer
 * \param ressources la texture liée au missile
 * \param world les données du monde
 */
void apply_missiles(SDL_Renderer *renderer, SDL_Texture *ressources,world_t* world);





/* <! AFFICHAGE HUD ET TEXTE DE FIN DE PARTIE !> */

/**
* \brief La fonction applique la texture associé a l'affichage du texte sur l'écran
* \param renderer le renderer
* \param world les données du monde
* \param textures les textures
*/
void print_affichage(SDL_Renderer *renderer, world_t *world,ressources *textures);

/**
* \brief La fonction applique la texture associé a l'affichage du nombre de missiles restant sur l'écran
* \param renderer le renderer
* \param world les données du monde
* \param textures les textures du jeu
*/
void print_missiles(SDL_Renderer *renderer, world_t *world,ressources*textures);

/**
* \brief La fonction applique la texture associé a l'affichage du temps sur l'écran
* \param renderer le renderer
* \param world les données du monde
* \param textures les textures du jeu
*/
void print_temps(SDL_Renderer *renderer, world_t *world,ressources *textures);

/**
 * \brief La fonction applique la texture associé a l'affichage du niveau sur l'écran
 * \param renderer le renderer
 * \param world les données du monde
 * \param textures les textures du jeu
 */
void print_niveau(SDL_Renderer *renderer, world_t *world,ressources*textures);

/**
 * \brief La fonction affiche le texte demandant au joueur si il veut rejouer
 * \param renderer le renderer
 * \param world les données du monde
 * \param textures les textures du jeu
 */
void print_play_again (SDL_Renderer *renderer, world_t *world,ressources *textures);


#endif
=======
/**
 * \file graphique.c
 * \brief Affichage graphique du jeu
 * \author Hugues Steiner Bouhadoun Kenza
 * \version 1.0
 * \date 07 avril 2021
 */

#include "constantes.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "monde.h"


#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    TTF_Font* font; /*textures liée a l'image représentant l'affichage du texte*/
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* ship; /*Texture liée à l'image représentant le vaisseau*/
    SDL_Texture* ligneA; /*Texture liée à l'image représentant la ligne d'arrivée*/
    SDL_Texture* meteore; /*Texture liée à l'image représentant la meteore*/
    SDL_Texture* missile;/*Texture liée à l'image représentant le missile*/
};

/**
 * \brief Type qui correspond aux textures du jeu
*/
typedef struct textures_s ressources;

/* <! INITIALISATION ET NETTOYAGE !> */


/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
 */
void init(SDL_Window **window, SDL_Renderer ** renderer, ressources *textures, world_t * world);

/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/
void clean(SDL_Window *window, SDL_Renderer * renderer,ressources *textures, world_t * world);


/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/
void  init_textures(SDL_Renderer *renderer, ressources*textures);

/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/
void clean_textures(ressources*textures) ;

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */
void refresh_graphics(SDL_Renderer *renderer, world_t *world,ressources *textures);


/* <! APPLICATION DE TEXTURES SUR LES SPRITES !> */

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/
void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);


/**
 * \brief La fonction applique la texture associé au sprite sur le renderer
 * \param renderer le renderer
 * \param texture la texture liée au sprite
 * \param sprite le sprite sur lequel appliquer la texture
*/
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) ;


/**
 * \brief La fonction applique la texture associé au mur de météorite sur le renderer
 * \param renderer le renderer
 * \param texture la texture liée au mur
 * \param sprite le mur sur lequel appliquer la texture
*/
void apply_mur(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) ;

/**
 * \brief La fonction applique la texture associé au mur de météorite sur le renderer
 * \param renderer le renderer
 * \param ressource la texture liée au sprite
 * \param world les données du monde
*/
void apply_walls(SDL_Renderer *renderer, SDL_Texture *ressources,world_t* world);


/**
 * \brief La fonction qui applique la texture associé à un missiles sur le renderer
 * \param renderer le renderer
 * \param texture la texture liée au missile
 * \param sprite le missile sur lequel appliquer la texture
 */
void apply_missiles2(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) ;

/**
 * \brief La fonction qui applique la texture associé aux missiles sur le renderer*
 * \param renderer le renderer
 * \param ressources la texture liée au missile
 * \param world les données du monde
 */
void apply_missiles(SDL_Renderer *renderer, SDL_Texture *ressources,world_t* world);





/* <! AFFICHAGE HUD ET TEXTE DE FIN DE PARTIE !> */

/**
* \brief La fonction applique la texture associé a l'affichage du texte sur l'écran
* \param renderer le renderer
* \param world les données du monde
* \param textures les textures
*/
void print_affichage(SDL_Renderer *renderer, world_t *world,ressources *textures);

/**
* \brief La fonction applique la texture associé a l'affichage du nombre de missiles restant sur l'écran
* \param renderer le renderer
* \param world les données du monde
* \param textures les textures du jeu
*/
void print_missiles(SDL_Renderer *renderer, world_t *world,ressources*textures);

/**
* \brief La fonction applique la texture associé a l'affichage du temps sur l'écran
* \param renderer le renderer
* \param world les données du monde
* \param textures les textures du jeu
*/
void print_temps(SDL_Renderer *renderer, world_t *world,ressources *textures);

/**
 * \brief La fonction affiche le texte demandant au joueur si il veut rejouer
 * \param renderer le renderer
 * \param world les données du monde
 * \param textures les textures du jeu
 */
void print_play_again (SDL_Renderer *renderer, world_t *world,ressources *textures);



#endif
>>>>>>> 620c1bfe81f551d6a6b545e2cff10cc1cacde157
