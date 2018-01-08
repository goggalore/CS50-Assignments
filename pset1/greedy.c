#include <stdio.h>
#include <cs50.h>


int main(void)
{
    float change;
    int counter = 0;
    do
    {
        printf("How much change is owed?\n");
        change = get_float();
        if (change < 0)
        {
            printf("A negative amount of change cannot be given! Please enter a positive value:\n");
        }
        
    }
    while (change < 0);
    
    int cents = 100 * change;
    //printf("%i\n", cents);
    
    while(cents >= 25)
    {
        counter = counter + 1;
        //cents = cents - 25;
        cents -= 25;
    }
    
    //printf("%i , %i\n", counter, cents);
    
    while(cents >= 10)
    {
        counter = counter + 1;
        cents = cents - 10;
    }
    
    while(cents >= 5)
    {
        counter = counter + 1;
        cents = cents - 5;
    }
    
    while(cents >= 1)
    {
        counter = counter + 1;
        cents = cents - 1;
    }
    
    printf("Total amount of coins used: %i\n", counter);
    
}

//in the future, try program that prints all different ways to distribute change