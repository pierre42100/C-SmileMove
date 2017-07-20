/**
 * Smile object
 *
 * @author Pierre HUBERT
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "utils.h"

#define MOVE_DOWN 3
#define MOVE_UP -1
#define MOVE_LEFT -2
#define MOVE_RIGHT 3

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

    //Movements of the smile
    int w_movement;
    int h_movement;

    //The smile object
    SDL_Surface *image;
    SDL_Texture *texture;

    //Defines if the smile was initializated or not
    int initializated;
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

    //Initialize smile movement
    smile.w_movement = MOVE_RIGHT;
    smile.h_movement = MOVE_DOWN;

    //Get smile size
    smile.w = smile.image->w;
    smile.h = smile.image->h;

    //Copy the image into a new texture
    smile.texture = SDL_CreateTextureFromSurface(renderer, smile.image);

    //Free memory by removing surface
    SDL_FreeSurface(smile.image);

    //Mark the smile as initilizated
    smile.initializated = 1;

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
 * Move a smile
 *
 * @param Smile *smile The smile to move
 * @param int max_x
 * @param int max_y > The maximum area that can be reached by the smile
 * @return void
 */
void move_smile(Smile *smile, int max_x, int max_y){

    int new_x, new_y;

    //Set new smile width and height
    new_x = smile->x + smile->w_movement;
    new_y = smile->y + smile->h_movement;

    //Check if we reached the maximum width and / or height
    if(new_x > (max_x - smile->w/2))
        smile->w_movement = MOVE_LEFT * alea(0, 2); //We have to go left
    if(new_x < -smile->w/2)
        smile->w_movement = MOVE_RIGHT * alea(0, 2); //We have to go right

    if(new_y > (max_y - smile->h/2))
        smile->h_movement = MOVE_UP * alea(0, 2); //We have to go up
    if(new_y < -smile->h/2)
        smile->h_movement = MOVE_DOWN * alea(0, 2); //We have to go down

    //Set new smile location
    set_new_smile_location(smile, new_x, new_y);

    //End of function
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

/**
 * Make the smile visible on its new location (draw in surface)
 *
 * @param SDL_Surface *surface The target surface
 * @param Smile *smile The smile to make visible
 * @return void
 */
void make_smile_visible_surface(SDL_Surface *surface, Smile *smile){

    //Define target rectangle
    SDL_Rect target_area = {smile->x, smile->y, smile->w, smile->h};

    //Copy the smile texture to the target renderer
    SDL_BlitSurface(smile->image, NULL, surface, &target_area);

    //End of the function
    return;
}
