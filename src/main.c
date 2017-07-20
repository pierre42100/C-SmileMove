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

#define NUMBER_MAX_SMILES 20
#define NUMBER_INTERVAL_BETWEEN_NEW_SMILES 100

int main(int argc, char *argv[])
{
    //Initializate variables
    //SDL Variables
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;

    //Event catcher
    SDL_Event event;
    SDL_bool quit = SDL_FALSE;

    //Smile variables
    Smile smile[NUMBER_MAX_SMILES];
    int currSmile = 0;
    int waitBeforeNextSmile = NUMBER_INTERVAL_BETWEEN_NEW_SMILES;

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

    //Create a texture with the same size as the renderer
    createTexture(renderer, texture, WINDOW_WIDTH, WINDOW_HEIGHT);

    //Inital pause (let the window appear)
    sleep(0.5);

    while(!quit){

        //Fill the screen
        fillRenderer(black);

        //Create a new smile if required
        if(waitBeforeNextSmile < NUMBER_INTERVAL_BETWEEN_NEW_SMILES){
            waitBeforeNextSmile++;
        }
        else if(currSmile < NUMBER_MAX_SMILES){
            //Reset counter
            waitBeforeNextSmile = 0;

            //Create the smile
            if(currSmile != 2)
                smile[currSmile] = create_smile("smile.png", renderer);
            else
                smile[currSmile] = create_smile("angry.png", renderer);

            //Prepare for next smile
            currSmile++;
        }

        //Move and display sime
        for(int i = 0; i < currSmile; i++){

            //Check if the smile exists
            if(smile[i].initializated == 0)
                break;

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
        usleep(2500);

    }


    //Destroy windows
    destroy_all_windows();

    //Success
    fprintf(stdout, "Exited cleany\n");
    return EXIT_SUCCESS;
}
