#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check if argc not equal to 2
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    else
    {
        // open file using pointer
        FILE *file = fopen(argv[1], "r");
        // error if the file is NULL
        if (file == NULL)
        {
            printf("Error: cannot open %s\n", file);
            return 2;
        }
        
        // initialise variables
        BYTE buffer[512];
        int count = 0;
        FILE *img = NULL;
        char filename[8]; // ###.jpg\0

        // repeat until end of card:
        while (fread(&buffer, 512, 1, file) == 1)
        {
            // if start of a new jpeg (0xff 0xd8 0xff 0xe*):
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // if not first jpeg, close previous
                if (!(count == 0))
                {
                    fclose(img);
                }
                // initialise file
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                count++;
            }
            // if jpeg has been found, write to file
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, img);
            }
        }

        // close all files
        fclose(file);
        fclose(img);

        return 0;
    }
}