/**
 * @file main.h
 * @brief Header for internal use of the main module.
 *
 * This file aims to include external modules, enums, and global constants
 * used by the main module.
 *
 * This file is not intended for external use and should only
 * be included by main.c and message.c, files internal to the main module.
 *
 * @dependencies
 * This module depends on the following modules:
 * - @ref ../include/interface.h "interface": Provides a user interface.
 */

#ifndef MAIN_H
#define MAIN_H

#include "../include/interface/interface.h"

/**
 * @enum type_message_main
 * @brief enum used to index access to messages
 * from the "message_main" char pointer array..
 */
enum type_message_main{
    MAIN_TITLE, /**< Main menu title */
    MAIN_OPTION_DVD, /**< First option to choose from the main menu */
    MAIN_OPTION_USER, /**< Second option to choose from the main menu */
    MAIN_OPTION_RENT_DVD, /**< Third option to choose from the main menu */
    MAIN_OPTION_PRINT_REPORT, /**< Fourth option to choose from the main menu */
    MAIN_OPTION_EXIT, /**< Fiveth option to choose from the main menu */
    MAIN_DEFAULT_OPTION, /**< Default message if the user does not choose any menu option */
    MAIN_WAIT, /**< waiting message */
    MAIN_COUNT /**< Total number of messages */
};

/**
 * @enum main_pick_user
 * @brief enum used to identify the value returned by the user through
 * the menu_options function, offered by the interface module.
 */
typedef enum main_pick_user{
    DVD = 1, USER, RENT_DVD, PRINT_REPORT, EXIT
}main_pick_user;

/**
 * @brief Defining the external global constant that stores
 * the messages used by the main module.
 */
extern const char *message_main[MAIN_COUNT];

#endif
