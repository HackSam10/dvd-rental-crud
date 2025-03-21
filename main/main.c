/**
 * @file main.c
 * @brief This file is the main module of the software.
 * 
 * This file contains the main function, which is responsible for driving the
 * software flow, consuming the functions of internal modules, and creating a
 * main interface with the user.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "main.h"



/**
 * @brief This is the main function, it is the entry point of the software.
 * 
 * The main function is responsible for driving the software flow, consuming
 * the functions of internal modules, and creating a main interface with the
 * user.
 *
 * @return It is the program's exit code. Returns 0 for success and a non-0
 * value for error.
 */

int main(void){

config_table menu_config = {0};
bool software_on = true;

//set a menu_config for the menu_options function of the interface module.
menu_config.table_margin = 35;
menu_config.table_size = 54;
menu_config.args_count = 7;
menu_config.title = message_main[MAIN_TITLE];
menu_config.value_return = true;

//main interaction loop with the user.
do{
system("clear");
header_menu();

//calling the interface module's menu_options function.
main_pick_user pick_user = menu_options(menu_config,
                             message_main[MAIN_OPTION_DVD],
                             message_main[MAIN_OPTION_USER],
                             message_main[MAIN_OPTION_RENT_DVD],
                             message_main[MAIN_OPTION_PRINT_REPORT],
                             message_main[MAIN_OPTION_EXIT]);

//using the return value to consume the internal modules
switch(pick_user){

    
    case DVD: {
                 if(true){
                      //puts(); 
                      sleep(2);
                     }
                 break;
                }

    case USER: {
                 if(true){
                      //puts(); 
                      sleep(2);
                     }
                 break;
                }

    case RENT_DVD: {
                 if(true){
                      //puts(); 
                      sleep(2);
                     }
                 break;
                }

    case PRINT_REPORT: {
                 if(true){
                      //puts(); 
                      sleep(2);
                     }
                 break;
                }

    case EXIT: {
            software_on = false;
            system("clear");
            break;
            }

    default : {
    puts(message_main[MAIN_DEFAULT_OPTION]);
    puts(message_main[MAIN_WAIT]);
    sleep(2);
    break;
    }

}

}while(software_on);



    
return 0;
}
