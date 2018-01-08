/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int lowerbound = 0;
    int upperbound = n;
    while(lowerbound <= upperbound)
    {
        int middle = (lowerbound + upperbound)/2;
        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] < value)
        {
            lowerbound = middle + 1;
        }
        else if (values[middle] > value)
        {
            upperbound = middle - 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // //compare two elements on a list
    // //once run through once, the final element does not need to be checked
    // //bubblesort
    // do
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         if(values[j + 1] < values[j])
    //         {
    //             int greaterval = values[j];
    //             values[j] = values[j + 1];
    //             values[j + 1] = greaterval;
    //         }
    //     }
    // n--;    
    // }
    // while(n > 0); //while elements have been switched
    // return;
    
    //counting sort
    int reference[65537] = {0};
    int slot = 0;
    for(int j = 0; j < n; j++)
    {
        //increments (counts like a tally) the corresponding slots in reference[] to values in values[].
        reference[values[j]]++; 
    }
    for(int k = 0; k < 65537; k++)
    {
        for(int l = 0; l < reference[k]; l++)
        {
            values[slot] = k;
            slot++;
        }
    }
    return;
}
