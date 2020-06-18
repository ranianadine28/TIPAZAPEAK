/**
* @file main.c
* @brief Testing Program.
* @author rania hajyoussef
* @version 0.1
* @date Apr 25, 2020
*
* Testing program for background scrollilng
*
*/

#include "perso2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"


int main()
{

SDL_Init(SDL_INIT_VIDEO);
TTF_Init();


int go=1 ; 


personnage c1,c2;

background b ; 

SDL_Event event ;
 

SDL_Surface *screen=NULL ;

screen=SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);



c1=initiaperso(c1);
c2=initiaperso2(c2);
	

b=initialiser_background(b,0,0,1);

SDL_BlitSurface(b.img, NULL, screen, &(b.pos));


SDL_Flip(screen);




affichageperso(c1,screen);

affichageperso(c2,screen);
SDL_Flip(screen);
while(go)
{   

SDL_PollEvent(&event);

switch(event.type)
        {

	case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            	{	
		case SDLK_RIGHT:
			c1.direction=1;	
			c2.direction=-1;
		break;

		case SDLK_LEFT: 
			c1.direction=0;
			c2.direction=-1;
		break;	
               case SDLK_q:
			c2.direction=1;	
			c1.direction=-1;
		break;

		case SDLK_d: 
			c2.direction=0;
			c1.direction=-1;
		break;	


		case SDLK_ESCAPE:
			
			go=0;
			
		break;	
		}
	}
SDL_BlitSurface(b.img, NULL, screen, &(b.pos));




mouvement (&c1);

mouvement (&c2);

animperso (&c1,screen);

animperso (&c2,screen);

affichageperso(c1,screen);

affichageperso(c2,screen);

	
	
SDL_Flip(screen);
c1.direction=-1;
c2.direction=-1;
}

SDL_FreeSurface(b.img);
SDL_Quit();

return EXIT_SUCCESS;
}
