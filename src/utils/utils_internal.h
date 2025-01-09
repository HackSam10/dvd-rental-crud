/**
 * @file utils_internal.h
 * @brief Header for internal use of the utils module.
 *
 * This file aims to include enums, and global constants
 * used by the utils module.
 *
 * This file is not intended for external use and should only
 * be included by utils.c and message_utils.c, files internal to the utils module.
 */

#ifndef UTILS_INTERNAL_H
#define UTILS_INTERNAL_H

/**
 * @enum type_message_utils
 * @brief enum used to index access to messages
 * from the "message_utils" char pointer array.
 */
enum type_message_utils{
    UTILS_NEW_CHANCE,
    UTILS_COUNT
};




/**
 * @brief Defining the external global constant that stores
 * the messages used by the utils module.
 */
extern const char *message_utils[UTILS_COUNT];

#endif
