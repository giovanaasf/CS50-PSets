#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void bytes(string message);
void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");

    bytes(message);
}


void bytes(string message)
{

    int ascii[strlen(message)];
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int count = 0, atual, bit;
        ascii[i] = message[i];
        atual = ascii[i];
        int bits[BITS_IN_BYTE];

        do
        {
            bit = atual % 2;
            bits[count] = bit;
            atual = atual / 2;
            count++;
        }
        while (count < BITS_IN_BYTE);

        for (int a = BITS_IN_BYTE; a >= 0; a--)
        {
            print_bulb(bits[a]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
