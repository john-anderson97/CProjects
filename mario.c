#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter a number between 1-8.\n");
    } 
    while (n < 1 || n > 8); /* only allows selected numbers 1-8 */
    

    for (int i = 0; i < n; i++) /* selects the row */
    {
        for (int j = 0; j < n; j++) /* selects the column */
        {
            if (i + j < n - 1) /* selects the blank sections */
            {
                printf(" ");
            }
            else /* selectes the draw sections */
            {
                printf("#");
            }
            
        }
       
        printf("\n"); /* end of loop to move to next line */
    }
    
}
