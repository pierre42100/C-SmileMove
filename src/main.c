/**
 * Project main file
 *
 * @author Pierre HUBERT
 */

#include <SDL2/SDL.h>
#include <unistd.h>
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
    //SDL_Surface *surface = NULL;
    Smile smile[2];

    //Event catcher
    SDL_Event event;
    SDL_bool quit = SDL_FALSE;

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

    //Create smiles
    smile[0] = create_smile("smile.png", renderer);
    smile[1] = create_smile("angry.png", renderer);

    //Put angry smile on the middle of the smile
    set_new_smile_location(&smile[1], WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

    //Inital pause (let the window appear)
    sleep(0.5);

    while(!quit){

        //fillRenderer(black);

        for(int i = 0; i < 2; i++){
            //Update smile location
            move_smile(&smile[i], WINDOW_WIDTH, WINDOW_HEIGHT);

            //Make the smile visible
            make_smile_visible(renderer, &smile[i]);
        }

        //Refresh renderer
        SDL_RenderPresent(renderer);

        SDL_WaitEventTimeout(&event, 0.5);
        if(event.type == SDL_QUIT)
            quit = SDL_TRUE;

        //Small pause
        usleep(2000);

    }


    //Destroy windows
    destroy_all_windows();

    //Success
    fprintf(stdout, "Exited cleany\n");
    return EXIT_SUCCESS;
}
