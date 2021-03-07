#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    do
    {
        n = get_float("How much change do you have?.\n");
    }
    while (n < 0); /* checks that the amount of change is positive */
    
    int cents = round(n * 100);  /* rounds the amount and converts to cents */
    int coin = 0;
    while (cents >= 25) /*counts 25 cents*/
    {
        cents -= 25;
        coin++;
    }
    while (cents >= 10) /*counts 10 cents*/
    {
        cents -= 10;
        coin++;
    }
    while (cents >= 5) /*counts 5 cents*/
    {
        cents -= 5;
        coin++;
    }
    while (cents >= 1) /*counts 1 cents*/
    {
        cents -= 1;
        coin++;
    }
    printf("The minimum number of coins for change is: %i\n", coin);
}
