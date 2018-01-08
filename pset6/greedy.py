import cs50

def main():
    
    while True:
        print("How much change is needed? ", end="")
        change = cs50.get_float()
        
        if change < 0:
            print("A negative amount of change cannot be given! Please enter a positive value")
            
        
        if change >= 0:
            break
        
    cents = 100 * change   
    CalculateChange(cents)

def CalculateChange(cents):
    
    counter = 0 
    
    while cents >= 25:
        counter += 1
        cents -= 25
        
    while cents >= 10:
        counter += 1 
        cents -= 10
        
    while cents >= 5:
        counter += 1 
        cents -= 5 
        
    while cents >= 1:
        counter += 1 
        cents -= 1
        
    print("Total amount of coins used: {}".format(counter))
    
if __name__ == "__main__":
    main()