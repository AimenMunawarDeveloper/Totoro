/*********************************************************************************************************************************************
 * This code deals with timer section
 * It contains basic customTimer ,25min,30min,5min timer functions
 * It contains wait function to add 1 second time delay in our timers
 * It contains StartTimerSelectionFunction to select timer type and run timers accordingly
 * It contains writeShortBreak,writeLongBreak,writeDefaultPomodoro,writeCustomPomodoro function to write pomodoro and breaks in history file
 * It contains completeTimerFunction to run at end of each timer to change timer type and call pomodoro,breaks writing functions
 ********************************************************************************************************************************************/

#include <stdio.h>
#include <time.h>

int PomodoroCounter = 0;// To start 30 mins break after 4 pomodoro
int endTimerSection = 0;// To check whether user wants to continue timer or not
int currentTimerType = 0;// To keep check of the timer currently being excecuted
/* Numbers assigned to each pomodoro are:
 * 0 = 25 mins;
 * 1 = 30 mins;
 * 2 = 5 mins;*/

// Function to write 30 mins break
void writeLongBreak() {
    FILE *filePtr = fopen("../history.txt", "a");
    /* ../ is used as the executable is created in cmake-build-debug folder
     * so first come out of it them read history.txt
     * Opening the history.txt file in append mode*/
    if (filePtr == NULL) {// to check if file was able to open properly or not
        printf("Error!Cant open the file");
    }
    fprintf(filePtr, "Long Break,30 min,0 sec\n");// Write data in file
    fclose(filePtr);// Close file
}

// Function to write 5 mins break
void writeShortBreak() {
    FILE *filePtr = fopen("../history.txt", "a");
    /* ../ is used as the executable is created in cmake-build-debug folder
     * so first come out of it them read history.txt
     * Opening the history.txt file in append mode*/
    if (filePtr == NULL) {// to check if file was able to open properly or not
        printf("Error!Cant open the file");
    }
    fprintf(filePtr, "Small Break,5 min,0 sec\n");// Write data in file
    fclose(filePtr);// Close file
}

// Function to write 25 mins pomodoro
void writeDefaultPomodoro() {
    FILE *filePtr = fopen("../history.txt", "a");
    /* ../ is used as the executable is created in cmake-build-debug folder
     * so first come out of it them read history.txt
     * Opening the history.txt file in append mode*/
    if (filePtr == NULL) {// to check if file was able to open properly or not
        printf("Error!Cant open the file");
    }
    fprintf(filePtr, "Pomodoro,25 min,0 sec\n");// Write data in file
    fclose(filePtr);// Close file
}

// Function to write custom  pomodoro
void writeCustomPomodoro(int minute) {
    FILE *filePtr = fopen("../history.txt", "a");
    /* ../ is used as the executable is created in cmake-build-debug folder
     * so first come out of it them read history.txt
     * Opening the history.txt file in append mode*/
    if (filePtr == NULL) {// to check if file was able to open properly or not
        printf("Error!Cant open the file");
    }
    fprintf(filePtr, "CustomPomodoro,%d min,0 sec\n", minute);// Write data in file
    fclose(filePtr);// Close file
}

/* Function to run at end of each timer to change timer type
 * and write pomodoro and break in history.txt file */
void completeTimer() {
    if (PomodoroCounter == 4) {
        // if 4 pomodoro complete reset pomodoro counter start 30 minute break
        printf("Time's over - time for a long break !!!");
        PomodoroCounter = 0;
        currentTimerType = 1;// 1 denotes 30 mins break
    } else {
        if (currentTimerType == 0) {
            writeDefaultPomodoro();// to write 25 mins pomodoro in history.txt
            // if 25 min work pomodoro complete start break 5 minutes timer
            printf("Time's over - time for a 5 minute break!!!");
            PomodoroCounter++;// to indicate one pomodoro completed
            currentTimerType = 2;// 2 denotes 5 min break
            return;
        }
        else if (currentTimerType == 1) {
            writeLongBreak();// to write 30 mins break in history.txt
            currentTimerType = 0;// 0 denotes 25 mins pomodoro
            return;
        } else if (currentTimerType == 2) {
            writeShortBreak();// to write 5 mins break in history.txt
            // if 5 minutes break finished then pomodoro start of work 25 minutes
            printf("Time's over - time for a 25 minute work!!!");
            currentTimerType = 0;// 0 denotes 25 mins pomodoro
            return;
        }
    }
}

// Time delay function
void wait(int seconds) {
    clock_t endWait;// Creating an object end_wait of type clock_t
    endWait = clock() + seconds * CLK_TCK;
    /* Getting the current clock using clock() and adding the required delay(Here 1 sec)
     * multiplied by CLK_TCK(a macro, which indicates the number of clock ticks in a second)
     * and storing the result in end_wait */
    while (clock() < endWait) {// Till current clock is less than required clock run an empty loop

    }
}

// custom timer
int Custom_timer(void) {
    int secs, s;
    int min;
    time_t t;// time_t is the  data type used to represent simple calendar time
    struct tm *tm;
    /* to create a structure pointer (tm) to a structure named (tm) present in time.h header file
    * A structure pointer is defined as the pointer which points to the address of the memory block that stores a structure.*/
    tm = localtime(&t);
    /* The localtime function is used to fill the struct (tm) with values that represents corresponding  local time\
     * &t is a pointer to a time_t value representing a calendar time.*/
    printf("Enter the number of minutes:\n");// Input the total number of minutes
    scanf("%d", &min);
    secs = min * 60;// to convert no.of minutes to seconds
    s = secs;

    while (secs > 0) {

        tm->tm_min = s / 60;
        // Arrow operator here is used to access element (tm_min) of the structure (tm) in time.h header file
        tm->tm_sec = s - (tm->tm_min * 60);
        /* Arrow operator here is used to access element (tm_min,tm_sec) of the structure (tm) in time.h header file
        *  subtract seconds that are multiples of 60 and the remaining seconds are the seconds part of time*/

        mktime(tm);
        /* mktime function takes a structure pointer as input
         * and converts the values of that structure into time_t values according to local time zone*/

        printf("%02d:%02d\n", tm->tm_min, tm->tm_sec);// to print current minutes and seconds
        s--;
        secs--;
        wait(1);// to call time delay function

    }
    writeCustomPomodoro(min);// to call custom timer writing function
    printf("Time's over");
    return 0;
}

// timer for 25 min
int t_25min() {
    int secs = 1500, sec;
    time_t t;// time_t is the  data type used to represent simple calendar time
    struct tm *tm;
    /* to create a structure pointer (tm) to a structure named (tm) present in time.h header file
    * A structure pointer is defined as the pointer which points to the address of the memory block that stores a structure.*/
    tm = localtime(&t);
    /* The localtime function is used to fill the struct (tm) with values that represents corresponding  local time\
     * &t is a pointer to a time_t value representing a calendar time.*/
    sec = secs;
    while (secs > 0) {


        tm->tm_min = sec / 60;
        // Arrow operator here is used to access element (tm_min) of the structure (tm) in time.h header file
        tm->tm_sec = sec - (tm->tm_min * 60);
        /* Arrow operator here is used to access element (tm_min,tm_sec) of the structure (tm) in time.h header file
        *  subtract seconds that are multiples of 60 and the remaining seconds are the seconds part of time*/

        mktime(tm);
        /* mktime function takes a structure pointer as input
         * and converts the values of that structure into time_t values according to local time zone*/

        printf("%02d:%02d\n", tm->tm_min, tm->tm_sec);// to print current minutes and seconds
        sec--;
        secs--;
        wait(1);// to call time delay function
    }
    completeTimer();
    return 0;
}

//timer for 5 min
int t_5min() {
    int secs = 300, sec;
    time_t t;// time_t is the  data type used to represent simple calendar time
    struct tm *tm;
    /* to create a structure pointer (tm) to a structure named (tm) present in time.h header file
    * A structure pointer is defined as the pointer which points to the address of the memory block that stores a structure.*/
    tm = localtime(&t);
    /* The localtime function is used to fill the struct (tm) with values that represents corresponding  local time\
     * &t is a pointer to a time_t value representing a calendar time.*/
    sec = secs;
    while (secs > 0) {


        tm->tm_min = sec / 60;
        // Arrow operator here is used to access element (tm_min) of the structure (tm) in time.h header file
        tm->tm_sec = sec - (tm->tm_min * 60);
        /* Arrow operator here is used to access element (tm_min,tm_sec) of the structure (tm) in time.h header file
        *  subtract seconds that are multiples of 60 and the remaining seconds are the seconds part of time*/

        mktime(tm);
        /* mktime function takes a structure pointer as input
         * and converts the values of that structure into time_t values according to local time zone*/

        printf("%02d:%02d\n", tm->tm_min, tm->tm_sec);// to print current minutes and seconds
        sec--;
        secs--;
        wait(1);// to call time delay function
    }
    completeTimer();
    return 0;
}

// timer for 30 min
int t_30min() {
    int secs = 1800, sec;
    time_t t;// time_t is the  data type used to represent simple calendar time
    struct tm *tm;
    /* to create a structure pointer (tm) to a structure named (tm) present in time.h header file
    * A structure pointer is defined as the pointer which points to the address of the memory block that stores a structure.*/
    tm = localtime(&t);
    /* The localtime function is used to fill the struct (tm) with values that represents corresponding  local time\
     * &t is a pointer to a time_t value representing a calendar time.*/
    sec = secs;
    while (secs > 0) {


        tm->tm_min = sec / 60;
        // Arrow operator here is used to access element (tm_min) of the structure (tm) in time.h header file
        tm->tm_sec = sec- (tm->tm_min * 60);
        /* Arrow operator here is used to access element (tm_min,tm_sec) of the structure (tm) in time.h header file
        *  subtract seconds that are multiples of 60 and the remaining seconds are the seconds part of time*/

        mktime(tm);
        /* mktime function takes a structure pointer as input
         * and converts the values of that structure into time_t values according to local time zone*/

        printf("%02d:%02d\n", tm->tm_min, tm->tm_sec);// to print current minutes and seconds
        sec--;
        secs--;
        wait(1);// to call time delay function
    }
    completeTimer();
    return 0;
}

// Timer type selection
int startTimerSection() {
    PomodoroCounter = 0;
    endTimerSection = 0;
    int timerType = 1;
    printf("Enter Timer Type \n");
    printf("Enter 1 for default timer \n");
    printf("Enter 2 for custom timer \n");
    scanf("%d", &timerType);
    while (endTimerSection == 0) {// to check whether user wants to continue timer or not
        if (timerType == 1) {
            switch (currentTimerType) {
                case 0:
                    t_25min();// to call 25-min timer function
                    printf("\nEnter any number other than 0 if you want to end timer");
                    scanf("%d", &endTimerSection);
                    break;
                case 1:
                    t_30min();// to call 30-min timer function
                    printf("\nEnter any number other than 0 if you want to end timer");
                    scanf("%d", &endTimerSection);
                    break;
                case 2:
                    t_5min();// to call 5-min function
                    printf("\nEnter any number other than 0 if you want to end timer");
                    scanf("%d", &endTimerSection);
                    break;
            }
        } else if (timerType == 2) {
            Custom_timer();// to call custom-timer function
            printf("\nEnter any number other than 0 if you want to end timer");
            scanf("%d", &endTimerSection);
            break;
        } else {
            printf("Enter valid data");// to handle incorrect input
        }
    }
    return 0;
}




