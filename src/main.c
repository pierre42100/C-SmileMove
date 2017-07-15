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
    SDL_Texture *texture = NULL;
    Smile smile;

    //Prepare colors
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color blue = {0, 0, 255, 255};

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

    //Crate a texture with the same size as the renderer
    createTexture(renderer, texture, 0, 0);

    //Create a smile
    smile = create_smile("smile.png", renderer);

        //Choose renderer texture as target
        SDL_SetRenderTarget(renderer, texture);

        //Fill renderer in black
        fillRenderer(blue);

        //Update smile location
        set_new_smile_location(&smile, 5, 50);

        //Make the smile visible
        make_smile_visible(renderer, &smile);

        //Copy the texture into the renderer
        cloneTextureIntoRenderer(renderer, texture);

        //Refresh renderer
        SDL_RenderPresent(renderer);


    //Pause
    getchar();

    //Destroy windows
    destroy_all_windows();

    //Success
    fprintf(stdout, "Exited cleany\n");
    return EXIT_SUCCESS;
}
