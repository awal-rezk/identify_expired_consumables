/* consumableArrayOperation.h is the header file for consumableArrayOperation.c */

/* Global variables */

// Each entry in the consumable array will take this form
typedef struct consumableArrayEntry{
    int month;
    int year;
    char* nameOfConsumable;
}consumableEntry;

// Array of structures will be dynamically allocated because the size of the array is not known until realtimeCount is assigned at the end of user entry session
extern consumableEntry* consumableArray;

/* Function Headers */
void addToStructArray(char* string, int monthEntry, int yearEntry, int index);
