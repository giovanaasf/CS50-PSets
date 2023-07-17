#include <cs50.h>
#include <stdio.h>
#define ALL4 34
#define ALL7 37
#define MASTER1 51
#define MASTER2 52
#define MASTER3 53
#define MASTER4 54
#define MASTER5 55
#define VISA 4

int Luhns(long);

int main(void)
{
    int firsts;
    int bank = 0;
    int result = 0;
    int digits = 0;


    long card = get_long("Number: ");
    long cash = card;

    while (cash > 0)
    {
        digits++;
        //decreasing one number at a time
        cash = cash / 10;
    }

    //finding out which bank it belongs to
    //visa = 1
    //all = 2
    //master = 3
    if (digits == 13)
    {
        firsts = card / 1000000000000;
        if (firsts == VISA)
        {
            bank = 1;
        }
    }
    else if (digits == 15)
    {
        firsts = card / 10000000000000;
        if (firsts == ALL4 || firsts == ALL7)
        {
            bank = 2;
        }
    }
    else if (digits == 16)
    {
        firsts = card / 1000000000000000;
        int twos = card / 100000000000000;
        if (firsts == VISA)
        {
            bank = 1;
        }
        else if (twos == MASTER1 || twos == MASTER2 || twos == MASTER3 || twos == MASTER4 || twos == MASTER5)
        {
            bank = 3;
        }
    }

    //if bank exists, is valid?
    if (bank != 0)
    {
        result = Luhns(card);
    }
    else
    {
        printf("INVALID\n");
    }

    if (result == 0)
    {
        switch (bank)
        {
            case 1:
                printf("VISA\n");
                break;
            case 2:
                printf("AMEX\n");
                break;
            case 3:
                printf("MASTERCARD\n");
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

int Luhns(long card)
{
    int sumL = 0;
    int doubled;
    int sum = 0;
    while (card > 0)
    {
        //picks the sum of the last number every time
        sumL += card % 10;

        //eliminates the number adds in sumL
        card = card / 10;

        doubled = (card % 10) * 2;

        if (doubled > 9)
        {
            //12 -> 1 + 2 = 3
            sum += doubled / 10 + doubled % 10;
        }
        else
        {
            sum += doubled;
        }

        //eliminates last number again
        card = card / 10;
    }

    //if sumL + sum end in 0
    if ((sumL + sum) % 10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}
