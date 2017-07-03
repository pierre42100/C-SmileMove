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

    //The smile object
    SDL_Surface image;
};
typedef struct Smile Smile;

/**
 * Create a new smile
 *
 * @param char filename The path to the smile image file
 * @return Smile
 */
Smile create_smile(const char *filename);

#endif // SMILE_H_INCLUDED
