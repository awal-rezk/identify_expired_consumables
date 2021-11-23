#include <stdio.h>
// Used for malloc(), atoi()
#include <stdlib.h>
// Used for booleans
#include <stdbool.h>

#include "stringParsing.h"
#include "consumableArrayOperation.h"

// NUM_TIME_PERIODS set to 2 because each expiration/sell by date only has two entities: month and year
#define NUM_TIME_PERIODS 2

int main (int argc, char *argv[]) {
    int numEntries = 5;
    int entrySize = 100;

    /* Allow the user to enter the names of consumables */
    printf("Please enter the names of up to 5 consumables in the following format:\n");
    printf("\n");
    printf("       <name of consumable> \n");
    printf("       <name of consumable> \n");
    printf("                . \n");
    printf("                . \n");
    printf("                . \n");
    printf("\n");
    printf("When you are finished, please type 'EXIT' in all uppercase letters.\n");

    char** entries = (char**)malloc(numEntries*sizeof(char*));

    processUserEntry(*(&entries), entrySize);

    /* Allow the user to enter the expiration/sell by dates of the same consumables */
    printf("Please enter expiration/sell by dates of each of the consumables entered, respectively.  Please use the following format:\n");
    printf("\n");
    printf("       <expiration/sell by date in format MM/YYYY> \n");
    printf("       <expiration/sell by date in format MM/YYYY> \n");
    printf("                . \n");
    printf("                . \n");
    printf("                . \n");
    printf("\n");
    printf("When you are finished, please type 'EXIT' in all uppercase letters.\n");


    char** expiration = (char**)malloc(numEntries*sizeof(char*));

    // Each entry in the consumableDict has the size of consumableDictEntry and there are "realtimeCount" entries to the "consumableArray"
    consumableArray = (consumableEntry*)malloc(realtimeCount*sizeof(consumableEntry));

    processUserEntry(*(&expiration), entrySize);

    char slash = '/';

    // Get today's date from the user
    printf("Please enter today's date in the following format: \n");
    printf("                <MM/YYYY>\n");


    char** timePeriodArray = (char**)malloc(NUM_TIME_PERIODS*sizeof(char*));
    acceptTodaysDate(*(&timePeriodArray), slash);

    char** userDates = (char**)malloc(NUM_TIME_PERIODS*sizeof(char*));
    int f = 0;
    // Boolean to indicate whether or not a consumable has expired
    bool needToDispose = false;
    // Flag to indicate whether ANY consumables have expired or not
    int expiredItemFlag = 0;
    while(expiration[f] != NULL){
        separateString(*(&userDates), expiration[f], slash);
        // Convert the month and year C strings to integer type before adding those members to the struct consumableDict[f]
        addToStructArray(entries[f], atoi(userDates[0]), atoi(userDates[1]), f);
        // Consumable concerned expired before this year
        if(consumableArray[f].year < atoi(timePeriodArray[1])){
            needToDispose = true;
        }else if(consumableArray[f].year == atoi(timePeriodArray[1])){
            // Consumable concerned expires this year
            if(consumableArray[f].month < atoi(timePeriodArray[0])){
                // Consumable concerned expired in an earlier month this year
                needToDispose = true;
            }
        }

        if(needToDispose){
            printf("Please dispose of the following consumable since it has already expired: %s.\n", consumableArray[f].nameOfConsumable);
            // Reset the boolean to false for next iteration of while loop
            needToDispose = false;
            expiredItemFlag = 1;
        }

        f = f + 1;

        if((expiration[f] == NULL) && (expiredItemFlag == 0)){
            printf("None of the consumables have expired. Have a good day.\n");
        }
    }

    /* Deallocate arrays of C strings and the array of structures */
    int x;
    for(x = 0; x < numEntries; x = x + 1){
        free(entries[x]);
    }
    free(entries);

    int e;
    for(e = 0; e < numEntries; e = e + 1){
        free(expiration[e]);
    }
    free(expiration);

    free(consumableArray);

    int h;
    for(h = 0; h < NUM_TIME_PERIODS; h = h + 1){
        free(timePeriodArray[h]);
    }
    free(timePeriodArray);

    int r;
    for(r = 0; r < NUM_TIME_PERIODS; r = r + 1){
        free(userDates[r]);
    }
    free(userDates);

    return 0;
}
