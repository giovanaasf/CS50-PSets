#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        //spaces
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }
        //#
        for (int k = i + 1; k > 0; k--)
        {
            printf("#");
        }

        printf("\n");
    }
}