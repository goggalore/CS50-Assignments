#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes;
    int ounces = 192;
    int bottle = 16;
    do
    {
        printf("How many minutes was your last shower?\n");
        minutes = get_int();
        if (minutes < 0)
        {
        printf("You picked a negative number! Please input a positive number.\n");
        }
    }
    while (minutes < 0);
    
    int totalOunces = minutes * ounces;
    int bottlesUsed = totalOunces/bottle;
    printf("Minutes showered: %i\nBottles of water used: %i\n", minutes, bottlesUsed);
    
    
    // //ask user for input
    // printf("How many minutes was your last shower?\n");
    // int minutes = get_int();
    // //analyze user's input
    // if (minutes > 0)
    // {
    //     int ounces = 192;
    //     int bottle = 16;
    //     int totalOunces = minutes * ounces;
    //     int bottlesUsed = totalOunces/bottle;
    //     printf("You used %i bottles of water while showering.\n", bottlesUsed);
    // }
    // else
    // {
    //     printf("You picked a negative number! Please input a positive number.\n");
    // }
}