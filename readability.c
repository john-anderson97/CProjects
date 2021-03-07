#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");
    int num_words, num_sentences, num_letters;
    num_words = num_sentences = num_letters = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i])) /* determines number of letters */
        {
            num_letters++;
        }
        if ((i == 0 && s[i] != ' ') || (i != len - 1 && s[i + 1] == ' ')) /* determines number of words */
        {
            num_words++;
        }
        if (s[i] == '.' || s[i] == '?' || s[i] == '!') /* determines number of setences */
        {
            num_sentences++;
        }
    }
    float L = (num_letters / (float) num_words) * 100; /* determines L */
    float S = (num_sentences / (float) num_words) * 100; /* determines S */
    int index = round(0.0588 * L - 0.296 * S - 15.8); /* calculates grade index */
    if (index < 1) /* condition for below grade 1 */
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16) /* condition for level 16 or above*/
    {
        printf("Grade 16+\n");
    }
    else /* condition for remaining grades */
    {
        printf("Grade %i\n", index);
    }
}
