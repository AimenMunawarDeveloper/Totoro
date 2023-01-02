/******************************************************************************
 * This part of code is used to write data in aboutus.txt file
 * ***************************************************************************/


void writeAboutUs(){
    FILE *filePtr = fopen("../aboutus.txt", "w");
    if(filePtr==NULL){// if file pointer has NULL value then file could not be opened properly
        printf("Error!Cant open the file");
    }
    // to open about us file in write mode and write about us information
    /* ../ is used as the executable is created in cmake-build-debug folder
     * so first come out of it them read aboutus.txt*/
    fprintf(filePtr, "# Totoro timer\n"// writing in file using file pointer
                     "A pomodoro app in C\n"
                     "### Introduction:\n"
                     "Francesco Cirillo created the Pomodoro Technique as a time-management technique in the late 1980s. It divides the task into intervals that are typically 25 minutes long and are separated by brief breaks using a kitchen timer.\n"
                     "The initial method consists of six steps:\n"
                     "* Select the task to be completed.\n"
                     "* Establish the pomodoro timer (typically for 25 minutes).\n"
                     "* Complete the task.\n"
                     "* Finish your task when the timer goes off and grab a short break (typically 5–10 minutes).\n"
                     "* If you have completed fewer than three Pomodoro, repeat Step 2 until you have completed all three.\n"
                     "* After the third and fourth Pomodoro are finished, take a long break (typically 20 to 30 minutes). After the long break is finished return to step 2\n"
                     "### Explaining the project:\n"
                     "Totoro Time is a simple program to help you stay focused and productive by sequentially scheduling work and rest times. Traditionally, there are four straight 25-minute focus periods, five-minute breaks, and then a lengthier 30-minute rest. This program accurately applies the Pomodoro technique and indicates when to work and when to take a brief break. The fundamental features of this program are as follows:\n"
                     "* Select from the main menu whether you want to see about-us,start timer,see history or exit program.\n"
                     "* The about us section will print information related to the project.\n"
                     "* The timer section will allow user to choose between default,custom timer.\n"
                     "* If user selects default timer it will start 25 min work timer then 5 min short break timer and 30 min long break timer after four 25 min timer.\n"
                     "* If user selects custom timer it will ask user about the total no.of minutes and start the timer.\n"
                     "* The history section will display all the pomodoro and their duration in minutes,seconds.\n");
    fclose(filePtr);// closing file
}

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