/**
 * @file message_internal.c
 * @brief Defines global constants used by the internal module.
 *
 * This file defines messages as global constants that will be used
 * by the internal module, to communicate with the user,
 * it does this through the char pointer array structure.
 */

#include "interface_internal.h"



/**
 * @brief Implementation of the message constant used in the interface module.
 * that will be used by the interface module.
 */
const char *message_interface[INTERFACE_COUNT] = {
    [INTERFACE_HEADER_MENSAGEM] = "DvD Reantal Software",
    [INTERFACE_SELECTION_USER] = "\n\nPlease select the number of the potion you wish to choose: "
};
