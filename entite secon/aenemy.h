#ifndef ANIMENNEMI_H_
#define ANIMENNEMI_H_
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#define spriteenemy1_W 85
#define spriteenemy1_H 180

typedef struct background

{

	SDL_Surface *background;

	SDL_Rect posbg;

	int dx,fx,dy,fy;

}background;

typedef struct enemy
{
	SDL_Rect position_enemy;/*!< rectangle */
	SDL_Rect pos2;/*!< rectangle */
	SDL_Rect pos1;/*!< rectangle */
	SDL_Rect position_sprite ;/*!< rectangle */
	int direction ; /*!< entier */
	SDL_Surface *spriteleft;/*!< surface */
	SDL_Surface *spriteright;/*!< surface */
}enemy;

void animEnm (enemy *e, SDL_Surface *screen,background b);

void initialiserenemy(enemy *e);

void freesurfaceenemy(enemy *e);

void affichage_enemy(enemy e, SDL_Surface *screen,background b);
void mvm_alea_enemy(enemy *e);


#endif
