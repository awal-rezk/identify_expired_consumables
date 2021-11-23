/* stringParsing.h is the header file for stringParsing.c */

/* Global variables */
extern int realtimeCount;

/* Function Headers */

/* processUserEntry() takes each consumable name and copies each one to an element of entryArray.
Also, the user input is checked because if the user enters "EXIT", then the last element of entryArray is assigned to NULL. */
void processUserEntry(char** entryArray, int entryLen);

/* separateString() takes the month and year separated by a forward slash in "dateString" and copies each time period to an element of dateArray  */
void separateString(char** dateArray, char* dateString, char delimiter);

/* acceptTodaysDate() is only used for the current month and year that the user enters into the terminal. */
void acceptTodaysDate(char** dateArray, char delimiter);


