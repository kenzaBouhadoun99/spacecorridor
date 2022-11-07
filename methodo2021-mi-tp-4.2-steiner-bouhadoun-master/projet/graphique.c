/**
 * \file graphique.c
 * \brief Affichage graphique du jeu
 * \author Hugues Steiner /Bouhadoun Kenza
 * \version 1.0
 * \date 07 avril 2021
 */

#include "graphique.h"

/* <! INITIALISATION ET NETTOYAGE !> */

// La fonction initialise les textures nécessaires à l'affichage graphique du jeu
void  init_textures(SDL_Renderer *renderer, ressources*textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
    textures->ship = load_image("ressources/spaceship.bmp", renderer);
    textures->ligneA = load_image("ressources/finish_line.bmp", renderer);
    textures->missile = load_image("ressources/missile.bmp", renderer);
    textures->meteore = load_image("ressources/meteorite.bmp", renderer);
    textures->font=load_font("ressources/arial.ttf",14);
}

// La fonction nettoie les textures
void clean_textures(ressources*textures){
    clean_texture(textures->background);
    clean_texture(textures->ship);
    clean_texture(textures->ligneA);
    clean_texture(textures->meteore);
    clean_font(textures->font);
    clean_texture(textures->missile);
    //clean_font(TTF_Font * font);
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,ressources*textures){
    //on vide le renderer
    clear_renderer(renderer);

    //application des textures dans le renderer
    apply_background(renderer, textures->background);
    apply_sprite(renderer, textures->ship, &(world->ship));
    apply_sprite(renderer, textures->ligneA, &(world->finish));
    apply_missiles(renderer, textures->missile, world);
    apply_walls(renderer, textures->meteore, world);
    print_temps(renderer,world,textures);
    print_niveau(renderer,world,textures);
    print_affichage(renderer,world,textures);
    print_missiles(renderer,world,textures);
    print_play_again (renderer,world,textures);
    update_screen(renderer);
}


/* <! APPLICATION DE TEXTURES SUR LES SPRITES !> */

// La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}

// La fonction applique la texture associé au sprite sur le renderer
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) {
    if(texture != NULL){
      apply_texture(texture, renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }
}

// La fonction applique la texture associé à un mur de météorite sur le renderer
void apply_mur(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) {
    if(texture != NULL){
        for (int j = sprite->y - sprite->h/2; j < sprite->y + sprite->h/2; j += METEORITE_SIZE) {
            for (int i = sprite->x - sprite->w/2; i < sprite->x + sprite->w/2; i += METEORITE_SIZE) {
                apply_texture(texture, renderer, i, j);
            }
        }
    }
}

// Fonction qui fait apparaitre les murs de météores à l'écran
void apply_walls(SDL_Renderer *renderer, SDL_Texture *texture, world_t* world) {
    for (int i = 0; i < world->nb_murs; i++) {
        apply_mur(renderer, texture, &(world->tab_murs[i]));
    }
}

// Fonction qui affiche un missile
void apply_missiles2(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite) {
    if(texture != NULL){
        for (int j = sprite->y - sprite->h/2; j < sprite->y + sprite->h/2; j += MISSILES_SIZE) {
            for (int i = sprite->x - sprite->w/2; i < sprite->x + sprite->w/2; i += MISSILES_SIZE) {
                apply_texture(texture, renderer, i, j);
            }
        }
    }
}

// Fonction qui fait apparaitre les missiles à l'écran
void apply_missiles(SDL_Renderer *renderer, SDL_Texture *texture, world_t* world){
  for (int i = 0; i < world->nb_missiles; i++) {
      apply_missiles2(renderer, texture, &(world->tab_missiles[i]));
  }
}



/* <! AFFICHAGE HUD ET TEXTE DE FIN DE PARTIE !> */


//La fonction qui permet d'afficher le texte de fin du jeu sur l'écran
void print_affichage(SDL_Renderer *renderer, world_t *world,ressources *textures){
        switch (world->etat_fin){
            case 1:
                apply_text(renderer,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2-80,200,50,"Vous avez gagne !",textures->font);
                break;
            case 2:
                apply_text(renderer,SCREEN_WIDTH/2-140,SCREEN_HEIGHT/2-80,280,50,"Vous avez perdu !",textures->font);
                break;
        }
      }


// La fonction qui permet d'afficher lee nombre de missiles disponible
void print_missiles(SDL_Renderer *renderer, world_t *world,ressources*textures){
    //On crée une chaîne de caratères à partir du nombre de missiles restant
    sprintf(world->aff_missiles,"MISL : %d", 10 - world->nb_missiles);

    //On applique le texte
    apply_text(renderer,0,50,100,50,world->aff_missiles,textures->font);
}

// La fonction qui fait afficher le temps sur l'écran
void print_temps(SDL_Renderer *renderer, world_t *world,ressources*textures){
      sprintf(world->aff_temps,"TEMPS : %d S", (world->temps - world->temps_initial));
      //On crée une chaîne de caratères à partir de la variable du temps
      apply_text(renderer,0,0,100,50,world->aff_temps,textures->font);//on applique le temps en haut à gauche
}

// La fonction qui fait afficher le numéro du niveau en cours
void print_niveau(SDL_Renderer *renderer, world_t *world,ressources*textures){
      sprintf(world->aff_niveau,"NIV : %d", world->niveau);
      //On crée une chaîne de caratères à partir de la variable du temps
      apply_text(renderer,200,0,100,40,world->aff_niveau,textures->font);//on applique le temps en haut à gauche
}


//La fonction qui permet d'afficher si le joueur veux rejouer ou quitter le jeu
 void print_play_again (SDL_Renderer *renderer, world_t *world,ressources *textures){
        if (world->etat_fin == 1  ){
              apply_text(renderer,SCREEN_WIDTH/2-140,SCREEN_HEIGHT/2-20,280,40,"Voulez-vous passer au niveau suivant?",textures->font);
              apply_text(renderer,SCREEN_WIDTH/2-90,SCREEN_HEIGHT/2+20,180,25,"'Prochain niveau->Entree",textures->font);
              apply_text(renderer,SCREEN_WIDTH/2-90,SCREEN_HEIGHT/2+80,180,25,"Pour quitter->Echap",textures->font);
        } else if (world->etat_fin == 2 ) {
              apply_text(renderer,SCREEN_WIDTH/2-140,SCREEN_HEIGHT/2-20,280,40,"Voulez-vous rejouer?",textures->font);
              apply_text(renderer,SCREEN_WIDTH/2-90,SCREEN_HEIGHT/2+20,180,25,"Pour rejouer->Entree",textures->font);
              apply_text(renderer,SCREEN_WIDTH/2-90,SCREEN_HEIGHT/2+80,180,25,"Pour quitter->Echap",textures->font);
        } else if (world->etat_fin == 3) {
              apply_text(renderer,SCREEN_WIDTH/2-140,SCREEN_HEIGHT/2-40,280,40,"Felicitations!",textures->font);
              apply_text(renderer,SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2,280,40,"Vous avez fini ce jeu!",textures->font);

        }
  }
