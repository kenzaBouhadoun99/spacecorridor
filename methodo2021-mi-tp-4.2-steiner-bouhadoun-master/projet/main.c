/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */

#include "sdl2-light.h"
#include "graphique.h"
#include "monde.h"
#include "constantes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/
void clean(SDL_Window *window, SDL_Renderer * renderer,ressources *textures, world_t * world);


/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
 */
void init(SDL_Window **window, SDL_Renderer ** renderer, ressources *textures, world_t * world);


/**
  * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
  * \param event paramètre qui contient les événements
  * \param world les données du monde
  */
 void handle_events(SDL_Event *event,world_t *world);


int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    ressources textures;
    SDL_Renderer *renderer;
    SDL_Window *window;
    //initialisation du jeu
    init(&window,&renderer,&textures,&world);
    world.niveau = 1;

    while (!is_game_over(&world)) { //tant que le jeu n'est pas fini
        while (world.rejouer == 'o' ) {
            //initialisation du jeu
            clean_data(&world);
            init_data(&world);
            while (world.etat_fin == 0 || world.rejouer == 'a'){
                world.rejouer = 'a';

                //gestion des évènements
                handle_events(&event,&world);

                //mise à jour des données liée à la physique du monde
                update_data(&world);

                //rafraichissement de l'écran
                refresh_graphics(renderer,&world,&textures);

                // pause de 10 ms pour controler la vitesse de rafraichissement
                pause(10);
            }
        }
    }

    //nettoyage final
    clean(window,renderer,&textures,&world);
    return 0;
}


// La fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
void init(SDL_Window **window, SDL_Renderer ** renderer, ressources*textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_ttf();/*textures liée a l'image représentant l'affichage du texte*/
    init_textures(*renderer,textures);
}

// La fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
void clean(SDL_Window *window, SDL_Renderer * renderer,ressources*textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}


void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {

        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1;
            world->etat_fin = 2;
            world->rejouer = 'n';
        }

        //si une touche est appuyée
        if (event->type == SDL_KEYDOWN) {
            // Pour faciliter le test, la vitesse est limitée pour l'instant
            if (event->key.keysym.sym == SDLK_DOWN && world->vy >= -4 && world->etat_fin == 0)  {
                world->vy -= 1;
            } else if (event->key.keysym.sym == SDLK_UP && world->vy <= 4 && world->etat_fin == 0) {
                world->vy += 1;
            } else if (event->key.keysym.sym == SDLK_RIGHT && world->etat_fin == 0) {
                world->ship.x += MOVING_STEP;
            } else if (event->key.keysym.sym == SDLK_LEFT && world->etat_fin == 0) {
                world->ship.x -= MOVING_STEP;
            } else if (event->key.keysym.sym == SDLK_ESCAPE) {
                world->gameover = 1;
                world->etat_fin = 2;
                world->rejouer = 'n';
            }  else if (event->key.keysym.sym == SDLK_d && world->etat_fin == 0 && world->nb_missiles < 10) {
                init_sprite(&(world->tab_missiles[world->nb_missiles]), world->ship.x,SCREEN_HEIGHT,MISSILES_SIZE,MISSILES_SIZE);
                world->nb_missiles++;
            }else if (event->key.keysym.sym ==SDLK_RETURN){
                if (world->etat_fin != 3){
                    world->rejouer = 'o';
                    world->temps_initial =SDL_GetTicks()/1000;
                    if (world->etat_fin == 1) {
                        world->niveau ++;
                    }
                } else {
                    world->gameover = 1;
                    world->rejouer = 'n';
                }
            }
        }
    }
}
