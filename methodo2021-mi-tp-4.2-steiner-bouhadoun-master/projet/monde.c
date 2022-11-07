/**
 * \file main.c
 * \brief Module qui gère les données du monde
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */

#include "monde.h"
<<<<<<< HEAD
=======

>>>>>>> 620c1bfe81f551d6a6b545e2cff10cc1cacde157

int randint(int a, int b){
    if (a>=b){
        return a;
    } else {
        return (rand()%(b-a)+a);
    }
}

 /* <! Initialisation et nettoyage !> */

void init_sprite (sprite_t* sprite, int x, int y, int w, int h) {
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
    sprite->c = 1;
}


void init_data(world_t *world){
    //on n'est pas à la fin du jeu
    world->gameover = 0;
    world->vy = INITIAL_SPEED ;
    world->temps_initial = SDL_GetTicks()/1000;
    world->etat_fin = 0;
    world->nb_missiles = 0;
    world->rejouer = 'o';
    world->aff_temps = malloc(sizeof(char)*10);
    world->aff_missiles = malloc(sizeof(char)*10);
    world->aff_niveau = malloc(sizeof(char)*15);
    if (world->niveau == 1) {
        init_sprite(&(world->ship), SCREEN_WIDTH/2, SCREEN_HEIGHT-SHIP_SIZE/2, SHIP_SIZE, SHIP_SIZE);
        init_sprite(&(world->finish), SCREEN_WIDTH/2, -960, SCREEN_WIDTH, FINISH_LINE_HEIGHT);
        init_walls(world);
    } else if (world->niveau <= NIVEAU_MAX ) {
        init_sprite(&(world->ship), SCREEN_WIDTH/2, SCREEN_HEIGHT-SHIP_SIZE/2, SHIP_SIZE, SHIP_SIZE);
        rand_lvl(world, (8 + 2 * world->niveau));
    }
}


void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    free(world->aff_temps);
    free(world->aff_missiles);
    free(world->aff_niveau);
}

//Fonction qui initialise les murs du 1er niveau du jeu
void init_walls(world_t* world){
    init_sprite(&(world->tab_murs[0]), 48, 0, 96, 188);
    init_sprite(&(world->tab_murs[1]), 252, 0, 96, 188);
    init_sprite(&(world->tab_murs[2]), 16, -352, 32, 156);
    init_sprite(&(world->tab_murs[3]), 188, -352, 224, 156);
    init_sprite(&(world->tab_murs[4]), 48, -672, 96, 156);
    init_sprite(&(world->tab_murs[5]), 252, -672, 96, 156);
    world->nb_murs = 6;
}

int is_game_over(world_t *world){
    return world->gameover;
}

// Fonction qui génére un niveau aléatoire
void rand_lvl(world_t* world, int nbMurs) {
    int i, col, h, x, y, w, cote = 0; //col : nombre de mur pour chaque ligne ; h : la hauteur de chaque ligne de mur ; w : la largeur du mur ; cote de quel côté de l'écran se trouvait l'ouverture du mur précédent (-1 : gauche, 1 : droite, 0 : neutre)
    world->nb_murs = nbMurs;
    y = SCREEN_HEIGHT;
    i = 0;
    while (i < nbMurs) {
        y -= 7*METEORITE_SIZE;

        // on determine le nombre de murs (1 ou 2)
        col = randint(1,3);
        // on diminue les chances de n'avoir qu'un seul mur
        if (col == 1) {
            col = randint(1,3);
        }
        // on determine la hauteur des murs sur la ligne
        h = randint(2,7) * METEORITE_SIZE;

        // on determine l'abscisse de la ligne en fonction de la taille du mur
        y -= h/2;
        if (col == 1) {
            w = randint(4, (SCREEN_WIDTH/METEORITE_SIZE - 2)) * METEORITE_SIZE;
            x = randint(w/2, (SCREEN_WIDTH-w/2));
            init_sprite(&(world->tab_murs[i]), x, y, w, h);
            i++;
        } else if (col == 2){
            w = randint(1, SCREEN_WIDTH/METEORITE_SIZE - 3) * METEORITE_SIZE;
            while (w < 5*METEORITE_SIZE && cote == -1 || w > 5*METEORITE_SIZE && cote == 1) {
                w = randint(1, SCREEN_WIDTH/METEORITE_SIZE - 3) * METEORITE_SIZE;
            }
            x = w/2;
            cote = 0;
            if (w < 5*METEORITE_SIZE) {
                cote = -1;
            } else if (w > SCREEN_WIDTH - 4 * METEORITE_SIZE) {
                cote = 1;
            }
            init_sprite(&(world->tab_murs[i]), x, y, w, h);
            i++;
            w = (SCREEN_WIDTH - w) - 2 * METEORITE_SIZE;
            x = SCREEN_WIDTH - w/2  ;
            init_sprite(&(world->tab_murs[i]), x, y, w, h);
            i++;
        }
    }
    y -= 4*METEORITE_SIZE;
    init_sprite(&(world->finish), SCREEN_WIDTH/2, y, SCREEN_WIDTH, FINISH_LINE_HEIGHT);
}

/* <! Génération des collisions entre sprites et les bords du jeu !> */

//Fonction qui vérifie si le vaisseau dépasse la limite gauche de l'écran
void limite_gauche(sprite_t* sprite) {
    if (sprite->x < sprite->w/2) {
        sprite->x = sprite->w/2 ;
    }
}

//Fonction qui vérifie si le vaisseau dépasse la limite droite de l'écran
void limite_droite(sprite_t* sprite) {
    if (sprite->x > SCREEN_WIDTH-sprite->w/2) {
        sprite->x = SCREEN_WIDTH-sprite->w/2 ;
    }
}

//Fonction qui vérifie si deux sprites sont en collision
int sprites_collide(sprite_t* sp1, sprite_t* sp2){

    if ((abs(sp1->x - sp2->x) <= (sp1->w + sp2->w)/2) && (abs(sp1->y - sp2->y) <= (sp1->h + sp2->h)/2) && sp1->c == 1){
        return 1;
    }
    return 0;
}


//Fonction qui réduit la vitesse du mode à 0 en cas de collision de sprite
void handle_sprites_collision(sprite_t* sp1, sprite_t* sp2, world_t* world, int make_disappear) {
    if (sprites_collide(sp1, sp2) == 1){
        if (make_disappear == 1){
            world->vy = 0;
            sp1->c = 0;
            sp1->y = -200;
            world->etat_fin = 2;
        } else if (make_disappear == 0) {
            world->vy = 0;
            sp1->c = 0;
            if (world->niveau == NIVEAU_MAX) {
                world->etat_fin = 3;
            } else {
                world->etat_fin = 1;
            }
        } else if (make_disappear == 3) {
            sp1->c = 0;
            sp1->y = -200;
            sp2->h -= METEORITE_SIZE;
            sp2->y -= METEORITE_SIZE/2;
            if (sp2->h < METEORITE_SIZE/2) {
                sp2->c = 0;
                sp2->w = 0;
                sp2->x = -200;
            }
        }
    }
}


 /* <! Rafraichissement et mise a jour !> */

void update_data(world_t *world){
    if (world->etat_fin == 0) {
        world->temps = SDL_GetTicks()/1000;
    }
    if (world->rejouer =='o' && world->etat_fin != 0){
      world->temps = 0;
    }

    world->finish.y += world->vy ;
    update_walls(world);
    update_missiles(world);
    limite_gauche(&(world->ship));
    limite_droite(&(world->ship));
    for (int i = 0; i < world->nb_murs; i++){
        handle_sprites_collision(&(world->ship), &(world->tab_murs[i]), world, 1);
        for (int y = 0; y < world->nb_missiles; y++){
            handle_sprites_collision(&(world->tab_missiles[y]), &(world->tab_murs[i]), world, 3);
        }
    }
    handle_sprites_collision(&(world->ship), &(world->finish), world, 0);
}


//Fonction qui fait bouger les murs
void update_walls(world_t* world){
    for (int i = 0; i< world->nb_murs; i++) {
        world->tab_murs[i].y += world->vy;
    }
}


//Fonction qui fait bouger les missiles
void update_missiles(world_t* world){
  for (int i= 0; i< world->nb_missiles;i++){
      world->tab_missiles[i].y -= VITESSE_MISSILES;
      if ( world->tab_missiles[i].y < 0 ) {
          world->tab_missiles[i].x = -30;
          world->tab_missiles[i].c = 0;
      }
  }
}
