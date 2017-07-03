/**
 * Window functions
 *
 * @author Pierre HUBERT
 */

 #include <SDL2/SDL.h>

/**
 * Static window pointer
 */
static SDL_Window *local_window = NULL;

/**
 * Static renderer pointer
 */
static SDL_Renderer *local_renderer = NULL;

/**
 * Initializate SDL
 *
 * @return int 0 in case of success / -1 else
 */
int init_SDL(){

    //Try to initializate SDl
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        return -1;

    //Success
    return 0;
}

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
int create_WindowAndRenderer(int width, int height, const char *title, SDL_Window **window, SDL_Renderer **renderer){

    //Try to create the window
    *window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    //Check for errors
    if(*window == NULL)
        return -1; //An error occured

    //Save pointer to window
    local_window = *window;

    //Create renderer
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

    //Check if it failed
    if(*renderer == NULL){
        *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_SOFTWARE);
    }

    //Check for errors
    if(*renderer == NULL)
        return -1; //An error occured

    //Store renderer locally
    local_renderer = *renderer;

    //This is a success
    return 0;
}

/**
 * Destroy a window and every associated renderers
 *
 * @return void
 */
void destroy_all_windows(){

    //Check for renderer to destroy
    if(local_renderer != NULL)
        SDL_DestroyRenderer(local_renderer);

    //Check for windows to destroy
    if(local_window != NULL)
        SDL_DestroyWindow(local_window);

    //Quit SDL
    SDL_Quit();
}

/**
 * Fill the renderer with one color
 *
 * @param SDL_Color color The color to use to fill renderer
 * @return void
 */
void fillRenderer(SDL_Color color){
    //Set the renderer as the target
    SDL_SetRenderTarget(local_renderer, NULL);

    //Update renderer color
    SDL_SetRenderDrawColor(local_renderer, color.r, color.g, color.b, color.a);

    //Clean renderer
    SDL_RenderClear(local_renderer);

    //Update window
    SDL_RenderPresent(local_renderer);
}
