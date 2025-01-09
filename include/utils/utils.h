/**
 * @file utils.h
 * @brief This module aims to serve as a utility for other modules,
 * providing functions and structs shared between other modules.
 *
 * This module provides helper functions common among other modules,
 * as well as global structs and enums commonly used in function prototypes of other modules.
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdint.h>


/**
 * @struct ids_global
 * @brief Struct used to generate and maintain player identifications (ids)
 * and match histories.
 */
typedef struct ids_global{
    unsigned int id_user; /**< Player identification. */
}ids_global;



/**
 * @brief Function used to collect possible characters remaining in the terminal
 * buffer after a user input operation.
 */
void ClearTerminal(void);



/**
 * @brief function used to offer a new input attempt to the user.
 * @return The function returns 1 for a new user attempt or 0 for not trying again.
 */
int new_chance(void);

#endif
