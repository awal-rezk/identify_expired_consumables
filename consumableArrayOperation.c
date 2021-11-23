/* consumableArrayOperation.c is a C source file used to add names of consumables along with their expiration/sell by dates to an array of structures.
Each structure contains the name of a consumable along with the month and year that it expires or sells by.*/

/* Global variables */
// Each entry in the consumable array will take this form
typedef struct consumableArrayEntry{
    int month;
    int year;
    char* nameOfConsumable;
}consumableEntry;

// Array of structures will be dynamically allocated because the size of the array is not known until realtimeCount is assigned at the end of user entry session
consumableEntry* consumableArray;

/* Function Definitions */

/* addToStructArray() takes the month, year, and consumable name passed in and assigns them to the month, year, and nameOfConsumable members of the structure at index. */
void addToStructArray(char* string, int monthEntry, int yearEntry, int index){
    consumableArray[index].month = monthEntry;
    consumableArray[index].year = yearEntry;
    consumableArray[index].nameOfConsumable = string;
}
