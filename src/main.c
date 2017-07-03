/**
 * Project main file
 *
 * @author Pierre HUBERT
 */

#include <SDL2/SDL.h>
#include "utils.h"
#include "window.h"
#include "smile.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char *argv[])
{
    //Initializate variables
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    Smile smile;

    //Prepare colors
    SDL_Color black = {0, 0, 0, 255};

    //Initializate SDL
    if(init_SDL() != 0){
        //This is a fatal error
        fatal_error("Couldn't initilizate SDL ! Are the required libraries present ?");
    }

    //Create the window
    if(create_WindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, "Smiley", &window, &renderer) != 0){
        //This is a fatal error
        fatal_error("Couldn't create a window and / or renderer !");
    }

    //Fill renderer in black
    fillRenderer(black);

    //Create a smile
    smile = create_smile("smiley.png");

    //Pause
    getchar();

    //Destroy windows
    destroy_all_windows();

    //Success
    fprintf(stdout, "Exited cleany\n");
    return EXIT_SUCCESS;
}
