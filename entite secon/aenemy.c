#include "aenemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"



//***********************************************************************************************************************************************************************************************************

void initialiserenemy(enemy *e)
{

e->spriteleft=IMG_Load("Ewizard left.png");
e->spriteright=IMG_Load("Ewizard right.png");

if (e->spriteleft==NULL)
    {
        printf ("Unable to load sprite ennemi left:%s\n",SDL_GetError());
    }
if (e->spriteright==NULL)
    {
        printf ("Unable to load sprite ennemi right:%s\n",SDL_GetError());
    }

e->position_enemy.x = 20;
e->position_enemy.y = 350;
e->position_sprite.x=0;
e->position_sprite.y=0;
e->position_sprite.h=spriteenemy1_H;
e->position_sprite.w=spriteenemy1_W;

e->direction=0;
}

//***********************************************************************************************************************************************************************************************************

void animEnm (enemy *e, SDL_Surface *screen,background b)
{
int i ;
	for(i=0;i<6;i++)
	{
	if(e->direction==1) //si le deplacement est à droite 
		{
		e->position_sprite.x=i*spriteenemy1_W;
		e->position_sprite.y=100;
		
		affichage_enemy(*e,screen,b);
		SDL_Delay(100);
		}

	else if(e->direction==0)//si le deplacement est à gauche
		{
		e->position_sprite.x=i*spriteenemy1_W;
		e->position_sprite.y=0;

		affichage_enemy(*e,screen,b);
		SDL_Delay(100);
		}
	}

}



//***********************************************************************************************************************************************************************************************************

void freesurfaceenemy(enemy *e)
{
SDL_FreeSurface(e->spriteleft);
SDL_FreeSurface(e->spriteright);
}

//***********************************************************************************************************************************************************************************************************

void affichage_enemy(enemy e, SDL_Surface *screen,background b)
{
	SDL_BlitSurface(b.background, NULL, screen, &b.posbg);
	if(e.direction==0)
SDL_BlitSurface(e.spriteleft,&e.position_sprite, screen, &e.position_enemy);

	else if(e.direction==1)
SDL_BlitSurface(e.spriteright,&e.position_sprite, screen, &e.position_enemy);

SDL_Flip(screen);
SDL_Delay(10);

}



//***********************************************************************************************************************************************************************************************************





void mvm_alea_enemy(enemy *e)
{
	if(e->direction==1)
	{	
		if(e->position_enemy.x!=e->pos2.x)
			e->position_enemy.x+=10;
		
			
		else 
			e->direction=0;
	}
	
	if(e->direction==0)
	{
		if(e->position_enemy.x!=e->pos1.x)
			e->position_enemy.x-=10;
		
		
		else 
			e->direction=1;
	}
	
	
	
}

