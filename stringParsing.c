/* stringParsing.c is a C source file used to take names of consumables along with the months and years of their expiration/sell by dates and add those entities to several arrays of C strings.
This C source file also takes the current month and year and adds them to an array of C strings.*/

// Used for NULL
#include <stdio.h>
// Used for malloc(), atoi()
#include <stdlib.h>
// Used for strcmp(), strtok(), strcpy(), strlen()
#include <string.h>

/* Global variables */
int realtimeCount;

/* Function Definitions */

void processUserEntry(char** entryArray, int entryLen){
    // Counter to keep track of how many entries are actually entered by the user
    realtimeCount = 0;
    // Initialized to 1 so that the while loop will be entered for the first iteration
    int checkExit = 1;

    while(realtimeCount < 5 && checkExit != 0){
        // If checkExit == 0, then, the user DID type in "EXIT"

        // String with size 99 + null terminator (\0) --> 99 + 1 = 100 --> entrySize = 100
        entryArray[realtimeCount] = (char*)malloc(entryLen*sizeof(char));
        scanf("%s", entryArray[realtimeCount]);

        // Compare the user's entry with "EXIT"
        checkExit = strcmp(entryArray[realtimeCount], "EXIT");

        if(checkExit != 0){
            // Increment realtimeCount for each new entry
            realtimeCount = realtimeCount + 1;
        }else{
            entryArray[realtimeCount] = NULL;
        }
    }
}

void separateString(char** dateArray, char* dateString, char delimiter){
    char* timePeriodPtr;
    // Use forward slash as a delimiter to make C string
    char forwardSlash[2] = {delimiter, '\0'};

    // Separate the "dateString" C string based upon the delimiter to separate the month from the year
    timePeriodPtr = strtok(dateString, forwardSlash);

    // Count number of tokens (starting from 0)
    int tokenCounter = 0;

    int timePeriodStringLen;

    while(timePeriodPtr != NULL){
        // Size of timePeriodPtr string
        timePeriodStringLen = strlen(timePeriodPtr);
        dateArray[tokenCounter] = (char*)malloc(timePeriodStringLen*sizeof(char));
        // Move the timePeriodPtr contents to dateArray[tokenCounter]
        strcpy(dateArray[tokenCounter], timePeriodPtr);
        // Increment tokenCounter
        tokenCounter = tokenCounter + 1;

        timePeriodPtr = strtok(NULL, forwardSlash);
    }
}

void acceptTodaysDate(char** dateArray, char delimiter){
    // 8 was chosen for the size of the char array because the format in the line above uses 7 characters (2 for month, 4 for year, and forward slash) + the null terminator (\0)
    char date[8];
    scanf("%s", date);

    char* datePtr = date;

    separateString(dateArray, datePtr, delimiter);

}

