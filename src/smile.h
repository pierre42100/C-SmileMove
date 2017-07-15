#ifndef SMILE_H_INCLUDED
#define SMILE_H_INCLUDED

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
    SDL_Surface image;
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
Smile create_smile(const char *filename, SDL_Renderer *renderer);

/**
 * Set the new location of a smile
 *
 * @param Smile *smile The smile object
 * @param int x
 * @param int y > Coordinates of the new location
 * @return void;
 */
void set_new_smile_location(Smile *smile, int x, int y);

/**
 * Move a smile
 *
 * @param Smile *smile The smile to move
 * @param int max_x
 * @param int max_y > The maximum area that can be reached by the smile
 * @return void
 */
void move_smile(Smile *smile, int max_x, int max_y);

/**
 * Make the smile visible on its new location
 *
 * @param SDL_Renderer *renderer The target renderer
 * @param Smile *smile The smile to make visible
 * @return void
 */
void make_smile_visible(SDL_Renderer *renderer, Smile *smile);

#endif // SMILE_H_INCLUDED
