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
    INTERFACE_RANKING_TITLE,
    INTERFACE_PRINT_RANKING_RANKING,
    INTERFACE_PRINT_RANKING_NAMES,
    INTERFACE_PRINT_RANKING_VICTORIES,
    INTERFACE_PRINT_RANKING_DEFEATS,
    INTERFACE_PRINT_RANKING_DRAW,
    INTERFACE_PLACAR_HEADER_CONFRONTO,
    INTERFACE_PLACAR_HEADER_PARTIDA,
    INTERFACE_PLACAR_PLAYERS,
    INTERFACE_PLACAR_VITORIA,
    INTERFACE_PLACAR_DERROTAS,
    INTERFACE_PLACAR_EMPATES,
    INTERFACE_PLACAR_PARTIDAS,
    INTERFACE_COUNT
};



/**
 * @brief Defining the external global constant that stores
 * the messages used by the interface module.
 */
extern const char *message_interface[INTERFACE_COUNT];

#endif
