/******************************************************************************
 * Main function here is used to integrate all the sections of the program
 * including main menu,about us,timer,history,exit program
 * ***************************************************************************/

#include <stdio.h>
#include "utils.h"
#include "timer.h"
#include "history.h"
#include "about-us.h"

int main() {
    bool exitProgram = false;// boolean variable whose value is used to exit program
    int menuOption = 0;
    /*variable whose value is used to decide
     * whether to display menu,show about us,start timer,display history or exit program*/

    // loop to run switch statement until end of program
    while (!exitProgram) {
        /*switch statement to check menu option variable value again and again
         * and decide based on its value whether to display menu,show about us,start timer,display history or exit program*/
        switch (menuOption) {
            case 0:// Main menu section
                printMainMenu();
                printCurrentDateTime();
                scanf("%d", &menuOption);
                continue;
                /* to skip this iteration and go to next iteration of loop
                 * and again check value of exit program and menu option */

            case 1://  About us section
                printf("*********************** \n");
                printf(" About Us \n");
                writeAboutUs();
                readAboutUsFile();
                printf("\n********************** \n");
                printMainMenu();
                scanf("%d", &menuOption);
                continue;
                /* to skip this iteration and go to next iteration of loop
                 * and again check value of exit program and menu option */

            case 2:// Timer section
                printf("*********************** \n");
                printf(" Time Section \n");
                startTimerSection();
                printf("\n*********************** \n");
                printMainMenu();
                scanf("%d", &menuOption);
                continue;
                /* to skip this iteration and go to next iteration of loop
                 * and again check value of exit program and menu option */

            case 3:// History section
                printf("*********************** \n");
                printf("History \n");
                readHistoryFile();
                printf("\n*********************** \n");
                printMainMenu();
                scanf("%d", &menuOption);
                continue;
                /* to skip this iteration and go to next iteration of loop
                 * and again check value of exit program and menu option */

            case 4:// Exit program
                printf("*********************** \n");
                printf("\nExiting ... \n");
                exitProgram = true; // make exit program variable value true and exit the loop & the program
                break;// to exit switch statement

            default:
                exitProgram = true;// make exit program variable value true and exit the loop & the program
                break;// to exit switch statement
        }
    }
    return 0;
}



