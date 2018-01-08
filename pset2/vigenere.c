#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*Given a key, the program encrypts a message from the user while preserving 
capitalization, spaces, and punctuation using Vigenere's Cipher*/

void checkIfAlpha();
void notAlpha();
string getMessage();
void encryptMessage();
void printMessage();
void encryptLetters();
void upperCase();
void lowerCase();

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string keyword = argv[1];
        //int key = atoi(keyword);
        checkIfAlpha(keyword);
        
        string message = getMessage();
        printf("Encrypted message: ");
        encryptMessage(keyword, message);
        return 0;
    }
    else
    {
        printf("Error: Invalid number of command line arguments.\n");
        return 1;
    }
}

void checkIfAlpha(string keyword)
{
    for(int i = 0; i < strlen(keyword); i++) 
    {
        notAlpha(i, keyword);
    }
}

void notAlpha(int i, string keyword)
{
    if (!(isalpha(keyword[i])))
    {
        printf("Error: Invalid input. ");
        printf("Please enter an argument containing only alphabetical letters\n");
        exit(!(isalpha(keyword[i])));
    }
}

string getMessage()
{
    printf("What is the message you would like to encrypt?: ");
    string plaintext = get_string();
    return plaintext;
}

void encryptMessage(string keyword, string message)
{
    int counter = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        printMessage(i, counter, keyword, message);
        if(isalpha(message[i]))
        {
            counter++;
        }
    }
    printf("\n");
}

void printMessage(int i, int counter, string keyword, string message)
{
    if (isalpha(message[i]))
    {
        int key = toupper(keyword[counter % strlen(keyword)]);
        key = key - 65;
        encryptLetters(i, key, message);
    }
    else
    {
        printf("%c", message[i]);
    }
}

void encryptLetters(int i, int key, string message)
{
    if (isupper(message[i]))
    {
        upperCase(i, key, message);
    }
    else if(islower(message[i]))
    {
        lowerCase(i, key, message);
    }
}

void upperCase(int i, int key, string message)
{
    int letter = message[i];
    letter -= 'A';
    int cipher = (letter + key) % 26;
    cipher += 'A';
    printf("%c", (char) cipher);
}

void lowerCase(int i, int key, string message)
{
    int letter = message[i];
    letter -= 'a';
    int cipher = (letter + key) % 26;
    cipher += 'a';
    printf("%c", (char) cipher);
}