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
    [MAIN_OPTION_ONE] = "1 - JOGAR ",
    [MAIN_OPTION_TWO] = "2 - CRIAR CONTA",
    [MAIN_OPTION_THREE] = "3 - TROCAR NOME",
    [MAIN_OPTION_FOUR] = "4 - RANKING",
    [MAIN_OPTION_FIVE] = "5 - HISTORICO DE CONFRONTO",
    [MAIN_OPTION_SIX] = "6 - EXCLUIR CONTA",
    [MAIN_OPTION_SEVEN] = "7 - SAIR",
    [MAIN_ERROR_LOGIN] = "Ocorreu um erro, por favor, verifique os dados e tente novamente...",
    [MAIN_ERROR_CREAT_USER] = "Não foi possível criar a conta, tente novamente mais tarde...",
    [MAIN_SUCCESS_CREAT_USER] = "Conta criada com sucesso! Aguarde...",
    [MAIN_ERROR_CHANGE_NAME] = "Não foi possivel realizar a troca de nomes.",
    [MAIN_SUCCESS_CHANGE_NAME] = "O nome de usuario foi trocado com sucesso!", 
    [MAIN_ERROR_RANKING] = "Ocorreu um erro insperado, tente novamente mais tarde!",
    [MAIN_ERROR_HISTORY] = "Não foi possivel vizualizar o historico.",
    [MAIN_ERROR_DELETE] = "não foi possível excluir a conta, tente novamente mais tarde.",
    [MAIN_SUCCESS_DELETE] = "Sua conta foi excluida com sucesso.\nO seu nome de usuario ainda sera mantido em nossos registros.",
    [MAIN_DEFAULT_OPTION] = "VOCÊ ESCOLHEU UMA OPÇÃO INVÁLIDA. POR FAVOR, DIGITE (7) PARA SAIR DO JOGO!",
    [MAIN_WAIT] = "Aguarde..."
};
