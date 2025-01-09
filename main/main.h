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
 * - @ref ../include/user.h "user" : Provides access to internal user operations.
 * - @ref ../include/ranking.h "ranking": Provides access to player rankings.
 */

#ifndef MAIN_H
#define MAIN_H

#include "../include/interface/interface.h"
#include "../include/user/user.h"
#include "../include/ranking/ranking.h"

/**
 * @enum type_message_main
 * @brief enum used to index access to messages
 * from the "message_main" char pointer array..
 */
enum type_message_main{
    MAIN_TITLE, /**< Main menu title */
    MAIN_OPTION_ONE, /**< First option to choose from the main menu */
    MAIN_OPTION_TWO, /**< Second option to choose from the main menu */
    MAIN_OPTION_THREE, /**< Third option to choose from the main menu */ 
    MAIN_OPTION_FOUR, /**< Fourth option to choose from the main menu */
    MAIN_OPTION_FIVE, /**< Fifth option to choose from the main menu */
    MAIN_OPTION_SIX, /**< Sixth option to choose from the main menu */
    MAIN_OPTION_SEVEN, /**< Seventh option to choose from the main menu */
    MAIN_ERROR_LOGIN, /**< Login error message */
    MAIN_ERROR_CREAT_USER, /**< Error message when creating user */
    MAIN_SUCCESS_CREAT_USER, /**< Success message when creating user */
    MAIN_ERROR_CHANGE_NAME, /**< Error message when change name */
    MAIN_SUCCESS_CHANGE_NAME, /**< Success message when change name */
    MAIN_ERROR_RANKING, /**< Error message when accessing the ranking */
    MAIN_ERROR_HISTORY, /**< Error message when accessing match history */
    MAIN_ERROR_DELETE, /**< Error message when deleting account */
    MAIN_SUCCESS_DELETE, /**< Success message when deleting account */
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
    GAME = 1, REGISTER, CHANGE_NAME, RANKING, HISTORY, DELETE, EXIT
}main_pick_user;

/**
 * @brief Defining the external global constant that stores
 * the messages used by the main module.
 */
extern const char *message_main[MAIN_COUNT];

#endif
