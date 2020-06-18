#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

typedef struct vie 
{
	int nbredevie ;/*!< entier */
	SDL_Surface *vie[4];/*!< surface */
	SDL_Rect position_de_vie ; /*!< rectangle */
	
}vie  ;


typedef struct score
{
	int score_atteint;/*!< entier */
	SDL_Rect position_score ; /*!< rectangle */
	TTF_Font *police_score; /*!< font */
	SDL_Surface *score_texte;/*!< surface */
	
}score  ;


/**
* @struct personnage
* @brief struct for personnage
*/
typedef struct personnage
    {
	SDL_Surface *sprite;
	SDL_Rect position_perso;
	SDL_Rect position_sprite;
	int direction;
	int numr , numl ;
	vie vie_perso ;/*!<vie */
	score score_perso ;
	int velocity ;/*!< entier */
	int speed ; /*!< entier */
     } personnage;



typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos ; 

}background;

personnage initiaperso(personnage c);
personnage initiaperso2(personnage c);

void animperso (personnage *c, SDL_Surface *screen);



void affichageperso(personnage c, SDL_Surface * screen);

void mouvement (personnage *c );





background initialiser_background(background b,int posx,int posy,int i);








