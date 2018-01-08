import sys, cs50

def main():
    
    if len(sys.argv) != 2:
        print("Usage: vigenere.py keyword")
        exit(1)
    
    keyword = sys.argv[1]
    while not keyword.isalpha():
        print("Invalid keyword, please enter only alphabetical characters.")
        keyword = cs50.get_string()
    keyword = keyword.upper()
    
    print("What is the message you would like to encrypt?")
    message = cs50.get_string()
    
    EncryptMessage(message, keyword)
    
def EncryptMessage(message, keyword):
    counter = 0 
    for i in range(len(message)):
        PrintMessage(i, counter, message, keyword)
        if message[i].isalpha():
            counter += 1
    print("")

def PrintMessage(i, counter, message, keyword):
    if message[i].isalpha():
        key = keyword[counter % len(keyword)]
        key = ord(key) - ord('A')
        EncryptLetters(i, key, message)
    else:
        print("{}".format(message[i]), end="")
        
def EncryptLetters(i, key, message):
    if message[i].isupper():
        EncryptUpper(i, key, message)
    elif message[i].islower():
        EncryptLower(i, key, message)
            
def EncryptUpper(i, key, message):
    letter = ord(message[i]) - ord('A')
    cipher = (letter + key) % 26
    cipher += ord('A')
    print("{}".format(chr(cipher)), end="")
    
def EncryptLower(i, key, message):
    letter = ord(message[i]) - ord('a')
    cipher = (letter + key) % 26
    cipher += ord('a')
    print("{}".format(chr(cipher)), end="")
    
if __name__ == "__main__":
    main()