#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int l = 0; l < height; l++)
    {
        for (int c = 0; c < width; c++)
        {
            // 0x00 -> black
            if (image[l][c].rgbtRed == 0x00 && image[l][c].rgbtGreen == 0x00 && image[l][c].rgbtBlue == 0x00)
            {
                image[l][c].rgbtGreen = 0xff;
            }
        }
    }
}
