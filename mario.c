#include <stdio.h>
#include <cs50.h>

int n;

int main(void)
{
    do // get height of the tower
    {
        n = get_int("Please enter the height of the tower, a positive integer under 24:");
    }
    while (n < 0 || n >= 24); // check to make sure height is within range

    // printf("height is %i\n",n);  This kills check50

    for (int i = 0; i < n; i++) // outer loop to print rows
    {
        for (int j = 0; j <= n; j++) // inner loop to print columns
        {
            if ((j + i + 1) < n) //decide to print a space or a 'block'
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

}