/**
 * @file interface.c
 * @brief This file implements interface module functions.
 * 
 * This file contains the implementation of the functions offered by
 * the interface module, its objective is to offer a "graphical" 
 * communication interface between software users and this module's clients.
 */

#include <stdio.h>
#include <stdarg.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/interface/interface.h"
#include "interface_internal.h"


/**
 * @struct config_cells
 * @brief Structure used to provide configuration arguments for the print_cells function.
 */
typedef struct config_cells{
    int cells_margin; /**< Sets the margin from the terminal to the first cell. */
    int cells_size; /**< Sets the size of each cell. */
    int cells_count; /**< Sets the number of cells. */
    char *control_string; /**< control string that informs the types and which arguments will be printed. */
}config_cells;


/**
 * @struct string_center
 * @brief Struct used as a return from the CenterString function.
 */
typedef struct string_center{
    int start; /**< Initial space offset to start of string. */
    int end; /**< Offset from the end of the string to the end of the space. */
}string_center;


static void printchar_menu(int margem, char first_char, char caractere, int quantidade, char last_char);

static string_center CenterString(const char *string, int space);

static void print_table(int tamanho_da_tabela);

static bool print_cells(config_cells config, ...);

static int check_matches(const char *buffer, const char **matches, int num_matches);





//Public functions.

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
void chat_box(box_config config, ...){

const char char_h = '_', char_v = '|', char_void = ' ';
va_list args = {0};
const char *string = NULL;
int index = 0;
string_center center = {0};

va_start(args, config);


printchar_menu(config.box_margin, char_void, char_h, config.box_horizontal_size, char_void);

for(index = 0; index < config.box_vertical_size; index++){
printchar_menu(config.box_margin, char_v , char_void, config.box_horizontal_size, char_v);
}

for(index = 0; index < config.args_count; index++){
 
string = va_arg(args, const char *);
center = CenterString(string, config.box_horizontal_size);
printf("%*c%*s%*c\n", config.box_margin, char_v,
                      center.start, string,
                      center.end, char_v);
}

for(index = 0; index < (config.box_vertical_size - 1); index++){
printchar_menu(config.box_margin, char_v , char_void, config.box_horizontal_size, char_v);
}

printchar_menu(config.box_margin, char_v, char_h, config.box_horizontal_size, char_v);
}




/**
 * @brief This function prints a header message.
 *
 * This is a procedure, which neither receives nor returns values.
 * Its purpose is to print a main header in the graphical interface.
 */
void header_menu(void){

box_config config = {0};

config.box_margin = 10;
config.box_horizontal_size = 100;
config.box_vertical_size = 1;
config.args_count = 1;

chat_box(config, message_interface[INTERFACE_HEADER_MENSAGEM]);
putchar(10);    
}


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
int menu_options(config_table config, ...){

int option = 0;
int index = 0, margin_start = 0, margin_end = 0, options_margin_start = 0, options_margin_end = 0;
const char *string = NULL;
string_center margin = {0};
va_list list = {0};


margin_start = config.table_size / 6; 
margin_end = margin_start * 5; 

va_start(list, config);

margin = CenterString(config.title, config.table_size);

printchar_menu(config.table_margin, ' ', '_', config.table_size, ' ');
printchar_menu(config.table_margin, '|' , ' ', config.table_size, '|');

printf("%*c%*s%*c\n", config.table_margin, '|',
                      margin.start, config.title,
                      margin.end, '|');

printchar_menu(config.table_margin, '|' , '_', config.table_size, '|');
printchar_menu(config.table_margin, '|' , ' ', config.table_size, '|');


for(index = 0; index < config.args_count; index++){

string = va_arg(list, const char *);

options_margin_start = margin_start + strlen(string);
options_margin_end = margin_end - strlen(string);

printf("%*c%*s%*c\n", config.table_margin, '|',
                     options_margin_start, string,
                     options_margin_end, '|');

}

va_end(list);
printchar_menu(config.table_margin, '|' , '_', config.table_size, '|');

if(config.value_return){
printf(message_interface[INTERFACE_SELECTION_USER]);

scanf("%d", &option);
ClearTerminal();
return option;
    }

return -1;
}









//Private functions

/**
 * @brief This is an helper function of the interface module,
 * used to print a number of characters.
 *
 * The function prints a varied number of characters from a certain position.
 * This function can be used to draw a table line, for example.
 *
 * @param margem The distance to the first character.
 * @param first_char The first character.
 * @param caractere The character to be printed.
 * @param quantidade The number of characters to be printed.
 * @param last_char The last character.
 */
static void printchar_menu(int margem, char first_char, char caractere, int quantidade, char last_char){
int i = 0;

printf("%*c", margem, first_char);
for(i = 0; i < quantidade - 1; i++){
printf("%c", caractere);
}
printf("%c\n", last_char);
}




/**
 * @brief This is a helper function of the interface module, it defines offsets
 * to center a string.
 *
 * This function sets a start and end offset to center a string in a given space.
 *
 * @param string A pointer to the string to be referenced.
 * @param space The total size of the space in which the string will be centered.
 * @return returns the type string_center, containing the initial and final offsets.
 */
static string_center CenterString(const char *string, int space){

int size_string = 0;    
string_center retorno = {0};

size_string = strlen(string);

if(size_string % 2) size_string++;


retorno.end = (space - size_string) / 2;
retorno.start = (retorno.end + size_string);


return retorno;
}




/**
 * @brief This is a helper function of the interface module,
 * it helps in building table structures.
 *
 * The function prints a variable amount of
 * the character '_' followed by the character '|' at the end.
 *
 * @param tamanho_da_tabela size of underlines to be printed.
 */
static void print_table(int tamanho_da_tabela){

register int i = 0;

for(i = 0; i < tamanho_da_tabela; i++){

putchar('_');
}

putchar('|');
}




/**
 * @brief Auxiliary function of the interface module, prints tables
 * in matrix format of different types.
 *
 * The function builds a table of cells horizontally, each cell
 * can contain one of 3 different types of data, integers and void. 
 * The table configuration is done through the config_cells struct,
 * where the margin, size and number of cells must be informed. 
 * The user must configure a control string to inform the type of data
 * that will be passed to each cell, example #i for integer, #s for string
 * and #v for void.
 * The function accepts a variable number of arguments based on the control string.
 *
 * If the function is called repeatedly, it is possible to build a matrix
 * simply and quickly.
 *
 * @param Config used to configure the size, quantity and content of cells.
 * @param ... Varied arguments based on control string.
 * @return The function returns 0 for success and non-0 for error.
 */
static bool print_cells(config_cells config, ...){

const char *reg_string = "#i|#s|#v";
const char *matches[] = {"#i", "#s", "#v"};

char match_buffer[3] = {0}, *string_regexec = NULL, *string_start_offset = NULL;
char char_v = '|';
int char_count = 0, offset_control_string = 0, token_matches = 0, index = 0, counter = 0;
regex_t cmp = {0};
regmatch_t offset = {0};
va_list args = {0};
int int_value = 0, int_margin = 0;
char *string_arg = NULL;
string_center string_margin = {0};

enum matches_token{
    TOKEN_INT = 1, TOKEN_STRING, TOKEN_VOID
};


if(regcomp(&cmp, reg_string, REG_EXTENDED)) return 1;

va_start(args, config);
int_margin = config.cells_size / 2;



for(counter = 0; counter < 2; counter++){
printf("%*c", config.cells_margin, char_v);
for(index = 0; index < config.cells_count; index++){
    printf("%*c", config.cells_size, char_v);
}
putchar(10);
}

string_regexec = config.control_string;

printf("%*c", config.cells_margin, char_v);

while(!(regexec(&cmp, string_regexec, 1, &offset, 0))){

    string_start_offset = string_regexec + offset.rm_so;
    char_count = offset.rm_eo - offset.rm_so;

    strncpy(match_buffer, string_start_offset, char_count);

    offset_control_string += offset.rm_eo;
    string_regexec = config.control_string + offset_control_string;

   token_matches = check_matches(match_buffer, matches, 3);

   switch(token_matches){

       case TOKEN_INT:{
                      int_value = va_arg(args, int);
                      printf("%*i%*c", int_margin, int_value, int_margin, char_v);
                      break;
                      }
       case TOKEN_STRING: {
                          string_arg = va_arg(args, char *);
                          string_margin = CenterString(string_arg, config.cells_size);
                          printf("%*s%*c", string_margin.start, string_arg,
                                 string_margin.end, char_v);
                          break;    
                          }

       case TOKEN_VOID:{
                       printf("%*c", config.cells_size, char_v);
                       break;    
                       }

       default: {
                regfree(&cmp);
                va_end(args);    
                return 1;
                }


           }
    }

putchar(10);
printf("%*c", config.cells_margin, char_v);
for(index = 0; index < config.cells_count; index++){
    printf("%*c", config.cells_size, char_v);
}

putchar(10);
printf("%*c", config.cells_margin, char_v);
for(index = 0; index < config.cells_count; index++){
    print_table(config.cells_size - 1);
}
putchar(10);


va_end(args);    
regfree(&cmp);
return 0;
};


/**
 * @brief This function is a helper of the print_cells function,
 * its objective is to identify which match was found.
 *
 * It loops through an array of valid matches and compares them with the match found
 * by the print_cells function in the control string.
 * Its objective is to identify which match is found in relation
 * to the matches parameter and return its offset.
 *
 * @param buffer - A pointer to the match to be analyzed.
 * @param matches - A pointer to the array of valid matches.
 * @param num_matches - The number of arrays present in the matches parameter.
 * @return returns the offset of the valid match, or -1 for errors.
 */
static int check_matches(const char *buffer, const char **matches, int num_matches){

int offset_matches = 0;


for(offset_matches = 0; offset_matches < num_matches; offset_matches++){

    if(!(strcmp(buffer, matches[offset_matches]))) return offset_matches + 1;

    }


return -1;
}
