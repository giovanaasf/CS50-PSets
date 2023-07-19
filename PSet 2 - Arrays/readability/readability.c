#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void coleman_liau(int lett, int w, int set);

int main(void)
{
    string text = get_string("Text: ");

    int letters =  count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    printf("%i letters\n", letters);
    printf("%i words\n", words);
    printf("%i sentences\n", sentences);

    coleman_liau(letters, words, sentences);



}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int words = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //"-" or "'"
        if ((text[i] == 45 && isalpha(text[i - 1])) || (text[i] == 39 && isalpha(text[i - 1])))
        {}
        else if ((!isalpha(text[i]) && isalpha(text[i - 1])))
        {
            words ++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}

void coleman_liau(int lett, int w, int set)
{
    int index;
    float L = (float) lett / ((float) w / 100);
    float S = (float) set / ((float) w / 100);

    index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

