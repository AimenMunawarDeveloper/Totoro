/*************************************************************************************************
 * This part of program contains some basic functions
 * **********************************************************************************************/

#include "string.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

// This function displays main menu
void printMainMenu() {
    printf("*********************** \n");
    printf("Welcome to Totoro! \n");
    printf("Enter 0 to get to the main menu \n");
    printf("Enter 1 to see About Us \n");
    printf("Enter 2 to Go to Timer \n");
    printf("Enter 3 to see history \n");
    printf("Enter 4 to exit \n");
    printf("********************** \n");
}

// Function to display current date,time
char printCurrentDateTime() {
    time_t t;// t an object of type time_t
    time(&t);
    /* time function returns time since january 1,1970 in seconds .
     * It takes pointer to time_t type object as argument
     * Here, &t is the pointer to an object(t) of type time_t
     * where the seconds value will be stored */
    printf("\nThe current date,time is: %s", ctime(&t));
    /* The ctime() function returns the string representing the localtime
     * It takes a pointer to a time_t object that contains a calendar time as input
     * The format of the string returned by it is:
     * Www Mmm dd hh:mm:ss yyyy
     * Www is the weekday
     * Mmm the month in letters
     * dd the day of the month
     * hh:mm:ss the time
     * yyyy the year*/
}




