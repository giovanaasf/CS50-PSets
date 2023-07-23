#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILENAME_LENGTH 8 // 3 digits + .jpg + \0

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // if the program is executed with exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s image.ram\n", argv[0]);
        return 1;
    }

    // open the forensic image
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    //tracking file number and filename
    int file_number = 0;
    char filename[FILENAME_LENGTH];

    //read the image data
    BYTE buffer[BLOCK_SIZE];

    //output file pointer
    FILE *output_file = NULL;

    //data from the forensic image and recover JPEGs
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        //if the block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //close the previous output file, if open
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            //generate the filename for the new JPEG
            sprintf(filename, "%03i.jpg", file_number);

            //new output file
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                printf("Could not create %s.\n", filename);
                fclose(raw_file);
                return 1;
            }

            //file number for the next JPEG
            file_number++;
        }

        //write the data to the output file if it is open
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
        }
    }

    //close the forensic image file
    fclose(raw_file);

    //close the last output file, if open
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    return 0;
}
