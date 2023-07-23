#include "helpers.h"
#include <math.h>

int capped255(int sepiaC);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    /*"we can take the average of the red, green, and blue values to
    determine what shade of grey to make the new pixel."*/

    // andando pelas linhas de pixels
    for (int l = 0; l < height; l++)
    {
        // andando pelas colunas de pixels
        for (int c = 0; c < width; c++)
        {
            // struct RGBTRIPLE -> bmp.h
            int red = image[l][c].rgbtRed;
            int blue = image[l][c].rgbtBlue;
            int green = image[l][c].rgbtGreen;

            int avgC = round((red + blue + green) / 3.0);

            image[l][c].rgbtRed = avgC;
            image[l][c].rgbtBlue = avgC;
            image[l][c].rgbtGreen = avgC;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int l = 0; l < height; l++)
    {
        for (int c = 0; c < width; c++)
        {
            int originalRed = image[l][c].rgbtRed;
            int originalBlue = image[l][c].rgbtBlue;
            int originalGreen = image[l][c].rgbtGreen;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            /*"It’s also possible that the result of the formula is a number greater than 255, the maximum value for an 8-bit color value. In that case, the red,
            green, and blue values should be capped at 255."*/

            image[l][c].rgbtRed = capped255(sepiaRed);
            image[l][c].rgbtBlue = capped255(sepiaBlue);
            image[l][c].rgbtGreen = capped255(sepiaGreen);
        }
    }
}

int capped255(int sepiaC)
{
    if (sepiaC <= 255)
    {
        return sepiaC;
    }
    else
    {
        return 255;
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int l = 0; l < height; l++)
    {
        for (int c = 0; c < width / 2; c++)
        {
            RGBTRIPLE temp = image[l][c];
            image[l][c] = image[l][width - 1 - c];
            image[l][width - 1 - c] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    /*"taking each pixel and, for each color value,
    giving it a new value by averaging the color values
    of neighboring pixels."*/

    // temporary image to store the blurred result
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumBlue = 0;
            int sumGreen = 0;
            int count = 0;

            // 3x3 box centered at the current pixel (i, j)
            for (int row = i - 1; row <= i + 1; row++)
            {
                for (int col = j - 1; col <= j + 1; col++)
                {
                    // if the current neighbor pixel is within the image boundaries
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        // Accumulate the color values of the neighboring pixels
                        sumRed += image[row][col].rgbtRed;
                        sumBlue += image[row][col].rgbtBlue;
                        sumGreen += image[row][col].rgbtGreen;
                        count++;
                    }
                }
            }

            //  average color values and store in the temporary image
            temp[i][j].rgbtRed = round((float)sumRed / count);
            temp[i][j].rgbtBlue = round((float)sumBlue / count);
            temp[i][j].rgbtGreen = round((float)sumGreen / count);
        }
    }

    // copy the blurred image from the temporary image back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

