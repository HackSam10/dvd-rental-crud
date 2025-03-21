/**
 * @file message_main.c
 * @brief Defines global constants used by the main module.
 *
 * This file defines messages as global constants that will be used
 * by the main module, to communicate with the user,
 * it does this through the char pointer array structure.
 */

#include "main.h"


/**
 * @brief Implementation of global constant messages
 * that will be used by the main module.
 */
const char *message_main[MAIN_COUNT] = {
    [MAIN_TITLE] = "MENU PRINCIPAL",
    [MAIN_OPTION_DVD] = "1 - Gerenciar DvDs",
    [MAIN_OPTION_USER] = "2 - Gerenciar Usuarios",
    [MAIN_OPTION_RENT_DVD] = "3 - Gerenciar Alugueis",
    [MAIN_OPTION_PRINT_REPORT] = "4 - Imprimir Relatório",
    [MAIN_OPTION_EXIT] = "5 - SAIR",
    [MAIN_DEFAULT_OPTION] = "VOCÊ ESCOLHEU UMA OPÇÃO INVÁLIDA. POR FAVOR, DIGITE (5) PARA SAIR DO JOGO!",
    [MAIN_WAIT] = "Aguarde..."
};
