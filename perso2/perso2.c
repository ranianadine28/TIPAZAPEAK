
/**
* @file perso2.c
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





//*****************************************************************************************************************************************************************************************************



//*********************************************************************************************************************************************************************************************************

background initialiser_background(background b,int posx,int posy,int i)//fond de level i
{
char fond[20];

	sprintf(fond,"fond%d.png",i);
        b.img= IMG_Load(fond);
	if (b.img==NULL)
    	{
        printf ("Unable to load background init2:%s\n",SDL_GetError());
    	}
	b.pos.x=posx;
	b.pos.y=posy;
return b ;
}
//*********************************************************************************************************************************************************************************************************


//*********************************************************************************************************************************************************************************************************


void mouvement (personnage *c )
{
if(c->direction ==1)
{
c->position_perso.x+=5; 

if(c->position_perso.x +c->position_sprite.w >700)
c->position_perso.x=700-c->position_sprite.w ;

}
else if (c->direction ==0)
{

c->position_perso.x-=5;

if(c->position_perso.x +c->position_sprite.w <0)
c->position_perso.x=10;
}
}




void animperso (personnage *c, SDL_Surface *screen)
{
		if (c->direction ==1)
                {	c->numr++; //le compteur de droite augmente 

			if(c->numr==4)//si on arrive à la fin du spritesheet on reprend  
				{
				c->numr=0;
				c->position_sprite.x=0;
				}
			else 		//si non on avance vers la frame suivante on multipliant la largeur de frame par le compteur  
				{
				c->position_sprite.x=c->numr*200;
				}
				c->position_sprite.y=600;
                }
                else if (c->direction ==0)   
		{	c->numl++;
			if(c->numl==4)
			{
				c->numl=0;
				c->position_sprite.x=0;
		   	}
			else 
			{
				c->position_sprite.x=c->numl*120;
			}
				c->position_sprite.y=0;
                 }		
				
					
}




void affichageperso(personnage c, SDL_Surface * screen)

{
	SDL_BlitSurface(c.vie_perso.vie[c.vie_perso.nbredevie], NULL, screen, &c.vie_perso.position_de_vie);
	SDL_BlitSurface(c.score_perso.score_texte, NULL, screen, &c.score_perso.position_score);
 	SDL_BlitSurface(c.sprite,&c.position_sprite, screen, &c.position_perso);
}



personnage initiaperso(personnage c)
{
char scoree[100];
  c.sprite= IMG_Load("sprite1.png");  
	

	//Définition des différentes positions du personnage par rapport au background 
	c.position_perso.x = 600;
  	c.position_perso.y = 500;
	c.position_perso.w=200;
	c.position_perso.h=450;

	c.direction=1;    //1 à droite et 0 à gauche 

	//chargement des images de la structure vie en les stockant dans un tableau 
	c.vie_perso.vie[1]=IMG_Load("image_de_vie1.jpg");
	c.vie_perso.vie[2]=IMG_Load("image_de_vie2.jpg");
	c.vie_perso.vie[3]=IMG_Load("image_de_vie3.jpg");
	c.vie_perso.vie[0]=IMG_Load("image_de_vie0.jpg");

	//Définition de la position de ces images par rapport au background
	c.vie_perso.position_de_vie.x=20 ; 
	c.vie_perso.position_de_vie.y=10 ; 
	
	//initialisation de nbre de vie 
	c.vie_perso.nbredevie=3;

	//initialisation du score 
	c.score_perso.score_atteint=0;
	
	//Définition de la position de frame
	c.position_sprite.x=0;
	c.position_sprite.y=400;
	c.position_sprite.w=200;
	c.position_sprite.h=300;

		
	//initialisation des compteurs	
	c.numr=-1;
	c.numl=-1;
	
	//Définition de la couleur noire 	
	SDL_Color policeNoire={0,0,0};

	//ouverture de la police 
	c.score_perso.police_score= TTF_OpenFont("angelina.TTF" , 40);

	//j'ai effectué l'écriture de texte selon le format que j'en aurais besoin 
	sprintf(scoree,"Score: %d",c.score_perso.score_atteint);

	//écriture dans le champ sdl surface* le score 
        c.score_perso.score_texte= TTF_RenderText_Blended(c.score_perso.police_score,scoree,policeNoire);	

	//Définition de la position du texte du score 
	c.score_perso.position_score.x=50 ;
	c.score_perso.position_score.y=100 ;

	c.velocity=1;

	c.speed=0;
return c ; 

}
//***********************************************************************************************************************************************************************************************************
//***********************************************************************************************************************************************************************************************************

personnage initiaperso2(personnage c)
{
char scoree[100];
  c.sprite= IMG_Load("sprite1.png");  
	

	//Définition des différentes positions du personnage par rapport au background 
	c.position_perso.x = 10;
  	c.position_perso.y = 500;
	c.position_perso.w=200;
	c.position_perso.h=300;

	c.direction=1;    //1 à droite et 0 à gauche 

	//chargement des images de la structure vie en les stockant dans un tableau 
	c.vie_perso.vie[1]=IMG_Load("image_de_vie1.jpg");
	c.vie_perso.vie[2]=IMG_Load("image_de_vie2.jpg");
	c.vie_perso.vie[3]=IMG_Load("image_de_vie3.jpg");
	c.vie_perso.vie[0]=IMG_Load("image_de_vie0.jpg");

	//Définition de la position de ces images par rapport au background
	c.vie_perso.position_de_vie.x=20 ; 
	c.vie_perso.position_de_vie.y=120 ; 
	
	//initialisation de nbre de vie 
	c.vie_perso.nbredevie=0;

	//initialisation du score 
	c.score_perso.score_atteint=0;
	
	//Définition de la position de frame
	c.position_sprite.x=0;
	c.position_sprite.y=300;
	c.position_sprite.w=200;
	c.position_sprite.h=300;

		
	//initialisation des compteurs	
	c.numr=-1;
	c.numl=-1;
	
	//Définition de la couleur noire 	
	SDL_Color policeNoire={0,0,0};

	//ouverture de la police 
	c.score_perso.police_score= TTF_OpenFont("angelina.TTF" , 40);

	//j'ai effectué l'écriture de texte selon le format que j'en aurais besoin 
	sprintf(scoree,"Score: %d",c.score_perso.score_atteint);

	//écriture dans le champ sdl surface* le score 
        c.score_perso.score_texte= TTF_RenderText_Blended(c.score_perso.police_score,scoree,policeNoire);	

	//Définition de la position du texte du score 
	c.score_perso.position_score.x=50 ;
	c.score_perso.position_score.y=180 ;

	c.velocity=1;

	c.speed=0;
return c ; 

}
