/*************************************************************************************************
 * This part of program contains some basic functions
 * **********************************************************************************************/

#include "string.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

// This function reads About us file
void readAboutUsFile() {
    /* ../ is used as the executable is created in cmake-build-debug folder
     * so first come out of it them read history.txt*/
    FILE *fp = fopen("../aboutus.txt", "r");// opening file in read mode
    if (fp == NULL) {// if file pointer has NULL value there is some error in opening file
        printf("Unable to read the file");
    }
    char buffer[150];// Buffer is a char array or chunk of memory where the characters fetched are stored.
    while (fgets(buffer, 150, fp)) {
        /*The functions fgets() will read up to 149 characters from the input stream referenced by fp.
         * It copies the read string into the buffer named buffer, appending a null character to terminate the string.*/
        printf("%s", buffer);
    }
    fclose(fp);// closing the file
}

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




