/**
 * Smile object
 *
 * @author Pierre HUBERT
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "utils.h"

/**
 * Smile object structure
 */
struct Smile {

    //Position of the smile on the screen
    int x;
    int y;

    //Size of the smile
    int w;
    int h;

    //The smile object
    SDL_Surface *image;
    SDL_Texture *texture;
};
typedef struct Smile Smile;

/**
 * Create a new smile
 *
 * @param char filename The path to the smile image file
 * @param SDL_Renderer *renderer The target renderer (the one that will show the smileys)
 * @return Smile
 */
Smile create_smile(const char *filename, SDL_Renderer *renderer){

    //Declare smile object
    Smile smile;

    //Try to load smile file
    smile.image = IMG_Load(filename);

    //Check for errors
    if(smile.image == NULL)
        fatal_error("Couldn't load an image !");

    //Initialize smile position
    smile.x = 0;
    smile.y = 0;

    //Get smile size
    smile.w = smile.image->w;
    smile.h = smile.image->h;

    //Copy the image into a new texture
    smile.texture = SDL_CreateTextureFromSurface(renderer, smile.image);

    //Free memory by removing surface
    SDL_FreeSurface(smile.image);

    //Return pointer on it
    return smile;

}

/**
 * Set the new location of a smile
 *
 * @param Smile *smile The smile object
 * @param int x
 * @param int y > Coordinates of the new location
 * @return void
 */
void set_new_smile_location(Smile *smile, int x, int y){

    //Append new location
    smile->x = x;
    smile->y = y;

    //End of the function
    return;
}

/**
 * Make the smile visible on its new location
 *
 * @param SDL_Renderer *renderer The target renderer
 * @param Smile *smile The smile to make visible
 * @return void
 */
void make_smile_visible(SDL_Renderer *renderer, Smile *smile){

    //Define target rectangle
    SDL_Rect target_area = {smile->x, smile->y, smile->w, smile->h};

    //Copy the smile texture to the target renderer
    SDL_RenderCopy(renderer, smile->texture, NULL, &target_area);

    //End of the function
    return;
}
