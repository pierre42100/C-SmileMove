#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

/**
 * Initializate SDL
 *
 * @return int 0 in case of success / -1 else
 */
int init_SDL();

/**
 * Create a new window and a new renderer and return their pointers
 *
 * @param int width The width of the new window
 * @param int height The height of the new window
 * @param char[] title The title of the new window
 * @param **SDL_Window window The target pointer on window
 * @param **SDL_Renderer renderer The target renderer
 * @return int 0 for a success / -1 in case of failure
 */
int create_WindowAndRenderer(int width, int height, const char *title, SDL_Window **window, SDL_Renderer **renderer);

/**
 * Destroy a window and every associated renderers
 *
 * @return void
 */
void destroy_all_windows();

/**
 * Fill the renderer with one color
 *
 * @param SDL_Color color The color to use to fill renderer
 * @return void
 */
void fillRenderer(SDL_Color color);

#endif // WINDOW_H_INCLUDED
