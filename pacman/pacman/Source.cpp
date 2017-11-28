

#include <SDL.h>

#include "GameManager.h"

int main(int argc, char** argv)
{
    //===========================================================================//
    //                             INIT CODE HERE
    //===========================================================================//
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen;
	screen = SDL_SetVideoMode(800, 640, 32, SDL_SWSURFACE); //this setVideoMode is not identified and will give error when it's run//

	const int FPS = 30;
	Uint32 start;

	// create one instance of GameManager
	GameManager* manager =  GameManager::getInstance();
	manager->Init();
// same error setcolorkey is unidentified so it will not run//
	SDL_SetColorKey(manager->spriteSheet, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 0xff, 0x00, 0xff));

	Uint32 color = SDL_MapRGB(screen->format, 0x00,0x00,0x00);

	while(manager->running)
    {
		start = SDL_GetTicks();

		//render
		SDL_FillRect(screen,&screen->clip_rect,color);


        // here update
		manager->Update();
		// here Draw
		manager->Draw(screen);

// sdl_flip will not run once the program starts running//
		
        SDL_Flip(screen);
		if(1000/FPS > SDL_GetTicks()-start)
        {
			SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
		}

	}
	manager->Dispose();

	SDL_Quit();
	return 0;
}
