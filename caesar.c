#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool check_valid_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !check_valid_key(argv[1])) /* checks that a valid key has been entered in the terminal */
    {
        printf("Usage: ./caeser key \n");
        return 1;
    }
    int key = atoi(argv[1]);
    
    string  plaintext = get_string("plaintext: "); /* asks user for text */
    
    printf("ciphertext: ");
    
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i]; /* selects that character based on the index i */
        if (isalpha(c)) /*checks that the character is in the alphabet (all others will be ignored) */
        {
            char m = 'A';
            if (islower(c)) /* mathematical change for capital and lower case characters. */
            {
                m = 'a';
            }
            printf("%c", (c - m + key) % 26 + m);
        }
        else
        {
            printf("%c", c);
        }
           
    }
    printf("\n");
}

bool check_valid_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    { 
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
