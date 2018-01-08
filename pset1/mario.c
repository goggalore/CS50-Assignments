#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Enter the height of the desired pyramid:\n");
        height = get_int();
        if (height <= 0 || height >= 23)
        {
            printf("Invalid input! Please enter an interger between 1 and 23.\n");
        }
    }
    while (height <= 0 || height >= 23);

    for (int rows = 0; rows < height; rows++)
    {
        for (int column = 0; column < height - rows - 1; column++)
        {
            printf(" ");
        }
        for (int column2 = 0; column2 < rows + 2; column2++)
        {
            printf("#");
        }
        for (int column3 = 0; column3 < 2; column3++)
        {
            printf(" ");
        }
        for (int column4 = 0; column4 < rows + 2; column4++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}
