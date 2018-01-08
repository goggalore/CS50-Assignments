import cs50

def main():
    
    while True:
        print("Enter the height of the desired pyramid: ", end="")
        height = cs50.get_int()
        
        if height < 1 or height > 23:
            print("Invalid input! Please enter an interger between 1 and 23.")
            
        if height > 0 and height <= 23:
            break
    
    PrintPyramid(height)

    
def PrintPyramid(height):
    for row in range(height):
        PrintSpaces(height, row)
        PrintHashes(row)
        print("  ", end="")
        PrintHashes(row)
        print("")
        
def PrintSpaces(height, row):
    for column in range(height - row - 1):
        print(" ", end="")
    return
    
def PrintHashes(row):
    for column in range(row + 2):
        print("#", end="")
    return

if __name__ == "__main__":
    main()
    
