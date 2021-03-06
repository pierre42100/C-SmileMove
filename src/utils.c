/**
 * Project main utilities
 *
 * @author Pierre HUBERT
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>

#include "window.h"

/**
 * Make a pause
 */
void sdl_pause(){
        SDL_Event event;

        SDL_WaitEvent(&event);

        if(event.window.event == SDL_WINDOWEVENT_CLOSE)
                return;
}

/**
 * Generates a random number in a specified interval
 *
 * @param int min The minimum number
 * @param int max The maximum number
 * @return int The result number
 */
int alea(int max, int min){
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

/**
 * Handle a fatal error
 *
 * @param char[] error The description of the error
 */
void fatal_error(const char *error){

    //Display fatal error
    fprintf(stderr, "A fatal error occured: %s\n", error);
    fprintf(stderr, "Last SDL Error (if any) : %s\n", SDL_GetError());

    //Destroy windows and renderers
    destroy_all_windows();

    //Quit script
    exit(EXIT_FAILURE);
}
