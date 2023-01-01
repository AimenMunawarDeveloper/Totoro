/**********************************************************************************************************
 * This part of code deals with History section
 * It reads the pomodoro and break history stored in history.txt file and displaying it to user
**********************************************************************************************************/

void readHistoryFile(){
    // ../ is used as the executable is created in cmake-build-debug folder
    // so first come out of it them read history.txt
    FILE *fp = fopen("../history.txt", "r");// opening file in read mode
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
