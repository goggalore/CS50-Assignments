#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename.raw");
        return 1;
    }
    
    // remember filenames
    char *infile = argv[1];
    
    // open card file
    FILE *card = fopen(infile, "r");
    if (card == NULL)
    {
        fprintf(stderr, "Could not open %s. \n", infile);
        return 2;
    }
    
    FILE *img = NULL;
    uint8_t buffer[512];
    char filename[8];
    int counter = 0; // to keep track of how many JPEGs have been opened
    int signature;
    
    while(fread(&buffer, 512, 1 , card) == 1)
    {
        signature = 0;
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0x0ff && 
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(img);
                return 3; 
            }
            
            fwrite(&buffer, 512, 1, img);
            counter++;
            signature = 1;
        }
        if (counter != 0 && signature == 0)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }
    
    if(img != NULL)
    {
        fclose(img);
    }

    //close card
    fclose(card);
    
    // success
    return 0;
    
}