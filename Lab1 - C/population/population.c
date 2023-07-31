#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int population, end, years = 0;
    do
    {
        population = get_int("Start size: ");
    }
    while (population < 9);

    // TODO: Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < population);

    // TODO: Calculate number of years until we reach threshold
    while (population < end)
    {
        population = population + (population / 3) - (population / 4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
