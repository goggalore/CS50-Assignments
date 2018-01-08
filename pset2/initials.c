#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//Program asks user for their name and prints out the initials even if input is imperfect with spaces in capital letters

int main(void)
{
    printf("What is your name?\n");
    string name = get_string();
    
    //prints out the first char if no space or punct
    //if (isalpha(name[0]))
    if (name[0] != ' ')
        {
            printf("%c", toupper(name[0]));
        }
    
    //look for spaces and punctuation
    for(int i = 0; i < strlen(name); i++)
    {
        //if (isspace(name[i]) && isalpha(name[i + 1]))
        if (name[i] == ' ' && name[i + 1] != ' ')
        {
            printf("%c", toupper(name[i + 1]));
        }
        else if(ispunct(name[i]) && isalpha(name[i + 1]))
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}