/**
 * @file utils.c
 * @brief This file contains the implementation of the functions offered by the utils module.
 * 
 * This module provides helper functions common among other modules.
 */

#include <stdio.h>
#include "../../include/utils/utils.h"
#include "utils_internal.h"


/**
 * @brief Function used to collect possible characters remaining in the terminal
 * buffer after a user input operation.
 */
void LimpaTerminal(void){
int a;

for(a = 'a'; a != 10 && a != EOF; a = getchar()){}
}




/**
 * @brief function used to offer a new input attempt to the user.
 * @return The function returns 1 for a new user attempt or 0 for not trying again.
 */
int new_chance(void){
int char_buffer = 0;

puts(message_utils[UTILS_NEW_CHANCE]);
char_buffer = getchar();

if(char_buffer != 10) LimpaTerminal();

if(char_buffer == 'y' || char_buffer == 'Y') return 1;
return 0;
}
