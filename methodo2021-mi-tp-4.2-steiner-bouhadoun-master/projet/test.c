/**
 * \file test.c
 * \brief Fonctions de test
 * \author Steiner/Bouhadoun
 * \date 7 avril 2021
 */

 #include "test.h"

void print_sprite(sprite_t *sprite) {
    printf("Le sprite a les coordonnees suivantes : x = %i , y = %i , w = %i , h = %i \n", sprite->x, sprite->y, sprite->w, sprite->h);
}


void test_init_sprite_param(sprite_t *sprite,int x,int y, int w, int h){
  printf("init_sprite(sprite, %i, %i, %i, %i) :\n", x, y, w, h);
  printf("test1");
  init_sprite(sprite,x,y,w,h);
  printf("test2");
  print_sprite(sprite);
  printf("\n");
}

void test_init_sprite(){
  sprite_t *sprite=malloc(sizeof (sprite_t));
  test_init_sprite_param(sprite,0,0,30,20);
  test_init_sprite_param(sprite,100,2,0,0);
  test_init_sprite_param(sprite,50,30,5,0);
  test_init_sprite_param(sprite,20,2,87,0);
  free(sprite);
}


void test_init_data_param(world_t *world) {
  printf("init_data(world) : \n");
  if (world->gameover == 0) {
    printf("gameover =/= 1 donc le jeu n'est pas terminé.\n");
  }
  init_data(world);
  printf("Vitesse = %i\n", world->vy);
  printf("Vaisseau :\n ");
  print_sprite(&(world->ship));
  printf("\n");
  printf("Ligne d'arrivée :\n");
  print_sprite(&(world->finish));
  printf("\n");
  printf("Mur :\n");
  for (int i =0 ; i < world->nb_murs; i++) {
    print_sprite(&(world->tab_murs[i]));
  }
  printf("\n");
}

void test_init_data(){
  world_t world;
  test_init_data_param(&world);
}


void test_update_data_param(world_t *world) {
  printf("Vitesse de déplacement horizontale : %i\n", world->vy);
  printf("Position verticale de la ligne d'arrivée : %i\n", world->finish.y);
  printf("Position verticale du mur de météores : %i\n", world->tab_murs[1].y);

}

void test_update_data() {
  world_t* world = malloc(sizeof(world_t));
  init_data(world);
  test_update_data_param(world);
  printf("\n");
  world->vy = 2;
  update_data(world);
  test_update_data_param(world);
  printf("\n");
  world->vy = 0;
  update_data(world);
  test_update_data_param(world);
  printf("\n");
  world->vy = -1;
  update_data(world);
  test_update_data_param(world);
  printf("\n");
  free(world);
}


void test_limite_gauche_param(sprite_t* sprite){
  print_sprite(sprite);
  limite_gauche(sprite);
  printf("limite_gauche(sprite) : \n");
  print_sprite(sprite);
}

void test_limite_gauche(){
  sprite_t *sprite = malloc(sizeof(sprite_t));
  init_sprite(sprite,70,70,30,20);
  test_limite_gauche_param(sprite);
  printf("\n");
  sprite->x = 0;
  test_limite_gauche_param(sprite);
  printf("\n");
  sprite->w = 100;
  test_limite_gauche_param(sprite);
  printf("\n");
  free(sprite);
}


void test_limite_droite_param(sprite_t* sprite){
  print_sprite(sprite);
  limite_droite(sprite);
  printf("limite_droite(sprite) : \n");
  print_sprite(sprite);
}

void test_limite_droite(){
  sprite_t *sprite = malloc(sizeof(sprite_t));
  init_sprite(sprite,70,70,30,20);
  test_limite_droite_param(sprite);
  printf("\n");
  sprite->x = SCREEN_WIDTH;
  test_limite_droite_param(sprite);
  printf("\n");
  sprite->w = 100;
  test_limite_droite_param(sprite);
  printf("\n");
  free(sprite);
}


void test_sprites_collide_param(sprite_t* sp1, sprite_t* sp2) {
  printf("1er sprite : \n");
  print_sprite(sp1);
  printf("2eme sprite : \n");
  print_sprite(sp2);
  printf("Les deux sprites");
  if (sprites_collide(sp1, sp2) == 1) {
    printf(" sont en collision.\n");
  } else {
    printf(" ne sont pas en collisions.\n");
  }

}

void test_sprites_collide(){
  sprite_t* sp1 = malloc(sizeof(sprite_t));
  sprite_t* sp2 = malloc(sizeof(sprite_t));
  init_sprite(sp1, 5, 2, 2, 2);
  init_sprite(sp2, 10, 2, 2, 2);
  test_sprites_collide_param(sp1, sp2);
  printf("\n");
  sp1->x = 9;
  test_sprites_collide_param(sp1, sp2);
  printf("\n");
  sp1->y = 5;
  test_sprites_collide_param(sp1, sp2);
  printf("\n");
  sp1->h = 8;
  test_sprites_collide_param(sp1, sp2);
  printf("\n");
  free(sp1);
  free(sp2);
}


void test_handle_sprites_collision_param(sprite_t* sp1, sprite_t* sp2, world_t* world, int make_disappear) {
  printf("La vitesse du monde = %i.\n", world->vy);
  printf("1er sprite : \n");
  print_sprite(sp1);
  printf("2eme sprite : \n");
  print_sprite(sp2);
  printf("Les deux sprites");
  if (sprites_collide(sp1, sp2) == 1) {
    printf(" sont en collision.\n");
    world->vy = 0;
  } else {
    printf(" ne sont pas en collisions.\n");
  }
  printf("La vitesse du monde = %i.\n", world->vy);
}

void test_handle_sprites_collision(){
  world_t* world = malloc(sizeof(world_t));
  sprite_t* sp1 = malloc(sizeof(sprite_t));
  sprite_t* sp2 = malloc(sizeof(sprite_t));
  init_sprite(sp1, 5, 2, 2, 2);
  init_sprite(sp2, 10, 2, 2, 2);
  world->vy = 1;
  test_handle_sprites_collision_param(sp1, sp2, world, 0);
  printf("\n");
  sp1->x = 9;
  world->vy = 1;
  test_handle_sprites_collision_param(sp1, sp2, world, 0);
  printf("\n");
  sp1->y = 5;
  world->vy = 1;
  test_handle_sprites_collision_param(sp1, sp2, world, 0);
  printf("\n");
  sp1->h = 8;
  world->vy = 1;
  test_handle_sprites_collision_param(sp1, sp2, world, 0);
  printf("\n");
  free(sp1);
  free(sp2);
  free(world);
}


void test_init_walls_param(world_t* world){
  for (int i=0;i<world->nb_murs;i++) {
    printf("Mur %i : ", i);
    print_sprite(&(world->tab_murs[i]));
  }
}

 void test_init_walls(){
    world_t* world = malloc(sizeof(world_t));
    init_walls(world);
    test_init_walls_param(world);
    printf("\n");
    free(world);
 }


void test_update_walls_param(world_t* world) {
  for (int i=0;i<world->nb_murs;i++) {
    printf("Mur %i : ", i);
    print_sprite(&(world->tab_murs[i]));
  }
  printf("update_walls : \n");
  update_walls(world);
  for (int i = 0; i < world->nb_murs; i++) {
    printf("Mur %i : ", i);
    print_sprite(&(world->tab_murs[i]));
  }

}

void test_update_walls(){
  world_t* world = malloc(sizeof(world_t));
  init_data(world);
  test_update_walls_param(world);
  printf("\n");
  free(world);
}


 int main(int argc, char* args[]){
    test_init_sprite();
    printf("\n");
    test_init_data();
    printf("\n");
    test_update_data();
    printf("\n");
    test_limite_gauche();
    printf("\n");
    test_limite_droite();
    printf("\n");
    test_sprites_collide();
    printf("\n");
    test_handle_sprites_collision();
    printf("\n");
    test_init_walls();
    printf("\n");
    test_update_walls();

    return 0;
 }
