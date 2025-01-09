/**
 * @file interface_internal.h
 * @brief Header for internal use of the interface module.
 *
 * This file aims to include enums, and global constants
 * used by the interface module.
 *
 * This file is not intended for external use and should only
 * be included by interface.c and message_interface.c, files internal to the interface module.
 */

#ifndef INTERFACE_INTERNAL_H
#define INTERFACE_INTERNAL_H


/**
 * @enum message_interface_type
 * @brief enum used to index access to messages
 * from the "message_interface" char pointer array.
 */
enum message_interface_type{
    INTERFACE_HEADER_MENSAGEM,
    INTERFACE_SELECTION_USER,
    INTERFACE_COUNT
};



/**
 * @brief Defining the external global constant that stores
 * the messages used by the interface module.
 */
extern const char *message_interface[INTERFACE_COUNT];

#endif
