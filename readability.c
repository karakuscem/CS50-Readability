#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float letter = (float)letters / (float)words * 100;
    float sentence = (float)sentences / (float)words * 100;
    float index = 0.0588 * (float)letter - 0.296 * (float)sentence - 15.8;
    int result = (int) round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}

int count_letters(string text)
{
    int lcounter = 0;
    int l = strlen(text);
    for (int i = 0; i < l; i++)
    {
        if (isalnum(text[i]))
        {
            lcounter++;
        }
        else
        {
            ;
        }
    }
    return lcounter;
}

int count_words(string text)
{
    int wcounter = 0;
    int w = strlen(text);
    for (int i = 0; i < w; i++)
    {
        if (isalnum(text[i]))
        {
            ;
        }
        else if (text[i] == '-')
        {
            ;
        }
        else if (ispunct(text[i]))
        {
            ;
        }
        else
        {
            wcounter++;
        }
    }
    return wcounter + 1;
}

int count_sentences(string text)
{
    int scounter = 0;
    int s = strlen(text);
    for (int i = 0; i < s; i++)
    {
        if (text[i] == '.')
        {
            scounter++;
        }
        else if (text[i] == '!')
        {
            scounter++;
        }
        else if (text[i] == '?')
        {
            scounter++;
        }
        else
        {
            ;
        }
    }
    return scounter;
}