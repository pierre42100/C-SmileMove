/**
 * Utilities header file
 *
 * @author Pierre HUBERT
 */

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

/**
 * Make pause
 */
void sdl_pause();

/**
 * Handle fatal errors
 *
 * @param const char *error The string describing the error
 */
void fatal_error(const char *error);

/**
 * Generates a random number in a specified interval
 *
 * @param int min The minimum number
 * @param int max The maximum number
 * @return int The result number
 */
int alea(int max, int min);

#endif // UTILS_H_INCLUDED
