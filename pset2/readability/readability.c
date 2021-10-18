#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int a = 0, len = strlen(text); a < len; a++)
    {
        if (isalnum(text[a]))
        {
            letters++;
        }
        else if (text[a] == ' ')
        {
            words++;
        }
        else if (text[a] == '.' || text[a] == '?' || text[a] == '!')
        {
            sentences++;
        }
    }
    
    float L = (float) letters * 100 / ((float) words + 1);
    float S = (float) sentences * 100 / ((float) words + 1);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {   
        printf("Grade %i\n", (int)index);
    }
}