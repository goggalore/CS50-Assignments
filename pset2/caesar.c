#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Given a key, the program encrypts a message from the user while preserving capitalization, spaces, and punctuation.

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string userin = argv[1];
        int key = atoi(userin);
        
        //printf("%i and %s\n", key, userin);
        printf("What is the message you wish to encrypt?: ");
        string plaintext = get_string();
        
        printf("Encrypted message: ");
        for(int i = 0; i < strlen(plaintext); i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    int letter = plaintext[i];
                    letter -= 65;
                    int cipher = (letter + key)%26;
                    cipher += 65;
                    printf("%c", (char) cipher);
                }
                else if(islower(plaintext[i]))
                {
                    int letter = plaintext[i];
                    letter -= 97;
                    int cipher = (letter + key)%26;
                    cipher += 97;
                    printf("%c", (char) cipher);
                }
            } 
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
    else 
    {
        printf("Error: Invalid number of command line arguments.\n");
    }
}