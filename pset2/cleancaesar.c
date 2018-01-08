#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*Given a key, the program encrypts a message from the user while preserving 
capitalization, spaces, and punctuation.*/

string GetMessage();
void EncryptMessage();
void PrintMessage();
void EncryptLetters();
void UpperCase();
void LowerCase();

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string userin = argv[1];
        int key = atoi(userin);
        
        string text = GetMessage();
        printf("Encyrpted message: ");
        EncryptMessage(text, key);
    }
    else
    {
        printf("Error: Invalid number of command line arguments.\n");
    }
}

string GetMessage(void)
{
    string plaintext;
    printf("What is the message you wish to encrypt?: ");
    plaintext = get_string();
    return plaintext;
}

void EncryptMessage(string text, int key)
{
    for(int i = 0; i < strlen(text); i++)
        {
            PrintMessage(i, text, key);
        }
    printf("\n");    
}

void PrintMessage(int i, string text, int key)
{
    if (isalpha(text[i]))
    {
        EncryptLetters(i, text, key);
    }
    else
    {
        printf("%c", text[i]);
    }
}

void EncryptLetters(int i, string text, int key)
{
    if (isupper(text[i]))
    {
        UpperCase(i, text, key);
    }
    else if(islower(text[i]))
    {
        LowerCase(i, text, key);
    }
}

void UpperCase(int i, string text, int key)
{
    int letter = text[i];
    letter -= 65;
    int cipher = (letter + key) % 26;
    cipher += 65;
    printf("%c", (char) cipher);
}

void LowerCase(int i, string text, int key)
{
    int letter = text[i];
    letter -= 97;
    int cipher = (letter + key) % 26;
    cipher += 97;
    printf("%c", (char) cipher);
}