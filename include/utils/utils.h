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
#include <sodium.h>

/**
 * @struct confronto
 * @brief Used to store individual player data in a match result record. 
 * The struct is used especially in the placar struct, to store data in a
 * confrontation between two players.
 */
typedef struct confronto{
    unsigned int id; /**< referenced player identifier. */
    char player[14]; /**< username of the referenced player. */
    uint32_t vitorias; /**< Player victory marker. */
    uint32_t derrotas; /**< Player loss marker. */
}confronto;




/**
 * @struct placar
 * @brief struct used to store data from a confrontation history between two players.
 */
typedef struct placar{
    unsigned int id; /**< Unique match identification. */
    confronto P1; /**< First player details. */
    confronto P2; /**< Second player details. */
    uint32_t empate; /**< Number of draws in the confrontation. */
    uint32_t PartidasJogadas; /**< Number of matches played. */
    uint8_t JogarNovamente : 1; /**< bit field used as flag for a new start. */
    uint8_t erro : 1; /**< bit field used as a flag for errors. */
}placar;



/**
 * @struct ranking
 * @brief struct used to store individual performance data for a given player,
 * with the aim of helping to create a player ranking.
 */
typedef struct ranking{
    unsigned int id; /**< Referenced player identifier. */
    int vitorias; /**< Player victory marker. */
    int derrotas; /**< Player loss marker. */
    int empate; /**< Player draw marker. */
    char name[14]; /**< username of the referenced player. */
    bool error; /**< Flag that indicates an error in some operation. */
}ranking;



/**
 * @struct user
 * @brief Struct representing a player.
 * 
 * This struct is used to represent a player, it stores all personal data,
 * such as username, login, password, performance data and also
 * auxiliary flags for functions that use it.
 */
typedef struct user{
    unsigned int id; /**< player identifier */
    char login[14]; /**< player login */
    char password[crypto_pwhash_STRBYTES]; /**< password hash with length defined in sodium.h */
    char name[14]; /**< player username */
    char peca; /**< player piece, used by the game module. */
    int vitorias; /**< Player victory marker. */
    int derrotas; /**< Player loss marker. */
    int empate; /**< Player draw marker. */
    uint8_t update_rank; /**< flag used by the ranking module, it informs that the player has new performance data. */
    unsigned char erro: 1; /**< bit field used as a flag for errors. */
    unsigned char memory: 1; /**< bit field used as a flag to indicate that the memory can be reused. */
}user;



/**
 * @struct ids_global
 * @brief Struct used to generate and maintain player identifications (ids)
 * and match histories.
 */
typedef struct ids_global{
    unsigned int id_user; /**< Player identification. */
    unsigned int id_placar; /**< Identification of match history (struct placar). */
}ids_global;



/**
 * @struct register_name
 * @brief struct used to record usernames created in the game and store them in a binary file.
 */
typedef struct register_name{
    char name[14]; /**< Name created by a user. */
}register_name;





/**
 * @brief Function used to collect possible characters remaining in the terminal
 * buffer after a user input operation.
 */
void LimpaTerminal(void);



/**
 * @brief function used to offer a new input attempt to the user.
 * @return The function returns 1 for a new user attempt or 0 for not trying again.
 */
int new_chance(void);

#endif
