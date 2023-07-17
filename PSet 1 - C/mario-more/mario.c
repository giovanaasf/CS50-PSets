#include <cs50.h>
#include <stdio.h>

void pyramids(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    pyramids(n);

}

void pyramids(int n)
{

    for (int i = 0; i < n; i++)
    {
        //left
        //spaces before #
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }
        //#
        for (int k = i + 1; k > 0; k--)
        {
            printf("#");
        }

        //space between pyramids
        printf("  ");

        //right
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }

}