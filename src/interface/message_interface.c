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
    [INTERFACE_HEADER_MENSAGEM] = "BEM VINDOS AO JOGO DA VELHA",
    [INTERFACE_SELECTION_USER] = "\n\nPOR FAVOR, DIGITE O NUMERO DA OPCAO QUE VOCE DESEJA ESCOLHER: ",
    [INTERFACE_RANKING_TITLE] = "MENU DE RANKING",
    [INTERFACE_PRINT_RANKING_RANKING] = "Ranking",
    [INTERFACE_PRINT_RANKING_NAMES] = "Nomes",
    [INTERFACE_PRINT_RANKING_VICTORIES] = "Vitorias",
    [INTERFACE_PRINT_RANKING_DEFEATS] = "Derrotas",
    [INTERFACE_PRINT_RANKING_DRAW] = "Empates",
    [INTERFACE_PLACAR_HEADER_CONFRONTO] = "O PLACAR DO CONFRONTO EH: ",
    [INTERFACE_PLACAR_HEADER_PARTIDA] = "O PLACAR DA PARTIDA ATUAL EH: ",
    [INTERFACE_PLACAR_PLAYERS] = "Jogadores",
    [INTERFACE_PLACAR_VITORIA] = "Vitorias",
    [INTERFACE_PLACAR_DERROTAS] = "Derrotas",
    [INTERFACE_PLACAR_EMPATES] = "Empates",
    [INTERFACE_PLACAR_PARTIDAS] = "Partidas"
};
