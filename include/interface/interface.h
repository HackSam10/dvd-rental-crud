/**
 * @file interface.h
 * @brief This header is the API that provides a public interface for 
 * users of the interface module.
 *
 * This file contains the functions and dependencies offered by
 * the interface module. Its objective is to offer access to “graphical” 
 * interface functions for communication between software users and clients
 * of this module.
 * 
 * @dependencies
 * This module depends on structures and functions offered by the utils module.
 * @ref utils.h : offers structs and functions. 
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include "../utils/utils.h"

/**
 * @struct box_config
 * @brief Struct used to provide configuration arguments for the chat_box function.
 */
typedef struct box_config{
    int box_margin; /**< Sets the margin from the terminal to the text box. */
    int box_horizontal_size; /**< Sets the horizontal size of the box in characters. */
    int box_vertical_size; /**< Sets the vertical size of the box in characters. */
    int args_count; /**< Defines the number of arguments that the function will receive later. */
}box_config;



/**
 * @struct config_table
 * @brief Struct used to provide configuration arguments for the menu_options function.
 */
typedef struct config_table{
    int table_margin; /**< Sets the margin from the terminal to the menu. */
    int table_size; /**< Sets the horizontal size of the options menu. The value must be a multiple of 6 for alignment reasons. */
    int args_count; /**< Defines the number of arguments that the function will receive later. */
    const char *title; /**< A pointer to the string that served as the title for the menu. */
    bool value_return; /**< Defines whether the function will return a user value or not. */
}config_table;




/**
 * @enum flag_print_placar
 * @brief enum used by the menu_print_placar function, its purpose is to
 * define whether the function will print a general scoreboard
 * listing all the players' matches, or whether the function will print
 * a scoreboard for a current matchup,
 * it does this by changing the title of the scoreboard.
 */
typedef enum flag_print_placar{
    GERAL, /**< print the general scoreboard. */
    PARTIDA_ATUAL /**< prints the current match score */
}flag_print_placar;


/**
 * @brief Function used to print messages in a text box.
 *
 * This function receives as its first argument a configuration struct
 * defined by the module, which informs the dimensions of the text box 
 * and the number of messages that will be passed to it in the next arguments.
 * The function can receive a varied number of arguments, but the number
 * must be informed in the configuration struct, that is, in the first parameter.
 *
 * @param config Used to configure the text box.
 * @param ... strings containing the text message.
 * @return Void The function does not return values.
 */
void chat_box(box_config config, ...);



/**
 * @brief This function prints a header message.
 *
 * This is a procedure, which neither receives nor returns values.
 * Its purpose is to print a main header in the graphical interface.
 */
void header_menu(void);



/**
 * @brief Function used to offer a menu of options to the user.
 *
 * The function prints a menu of options for the user on the terminal,
 * it can be configured through the config_table struct, which makes it flexible
 * in design and options. The function accepts a variable number of parameters
 * that serve as menu options, as long as they are configured in the first parameter.
 * The function can return a user's choice among the options provided in the menu,
 * or just print a common menu of options, without interacting with the user
 * and giving them a choice.
 *
 * @param config - Used to configure title, design, argument quantity and return.
 * @param ... - Variable number of string arguments.
 * @return The function may return the user's choice among the menu options,
 * or may not return a valid value. 
 * It depends on the value_return flag in the config parameter.
 */
int menu_options(config_table config, ...);



/**
 * @brief Function used to print a player ranking table.
 * 
 * This function was created for the ranking module server, it produces a table
 * interface to print the players' ranking. It has three parameters,
 * a pointer to a struct ranking array, the number of elements in this array
 * and the value that represents the current ranking of the first player present
 * in the first parameter.
 *
 * @param UserRanking - A pointer to an array of a struct of type ranking.
 * @param CountUser - The number of elements present in the ranking array.
 * @param RankUser - A value that represents the ranking of the first player
 * present in the UserRanking argument.
 *
 * @dependencies
 * - @ref ranking is defined in utils.h
 */
void menu_print_ranking(ranking* UserRanking, int CountUser, int *RankUser);



/**
 * @brief Function used to print the match score between two players.
 *
 * The function takes two arguments, the first is struct placar, which contains data
 * about the confrontation between two players, such as wins, losses,
 * draws, number of matches and identifiers. The second argument is a flag that
 * indicates whether the function will print a confrontation history
 * or the current match between the players.
 *
 * @param placar_da_partida - A pointer to the struct placar.
 * @param flag - A flag used to inform the type of scoreboard to be printed.
 *
 * @dependencies
 * - @ref placar is defined in utils.h
 */
void menu_print_placar(placar *placar_da_partida, flag_print_placar flag);

#endif
