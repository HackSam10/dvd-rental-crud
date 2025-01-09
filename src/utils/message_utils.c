/**
 * @file message_utils.c
 * @brief Defines global constants used by the utils module.
 *
 * This file defines messages as global constants that will be used
 * by the utils module, to communicate with the user,
 * it does this through the char pointer array structure.
 */

#include "utils_internal.h"


/**
 * @brief Implementation of the message constant used in the utils module.
 * that will be used by the utils module.
 */
const char *message_utils[UTILS_COUNT] = {
    [UTILS_NEW_CHANCE] = "Por favor, digite (Y) para tentar novamente, ou outra tecla para retornar ao menu: "
};
