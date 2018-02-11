#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i;
    float change_f;
    do // get change owed to customer
    {
        change_f = get_float("Please enter the amount of change owed, a number greater than 0:\n");
    }
    while (change_f < 0);
    change_f = (change_f * 100) + .5; // convert float to an integer and round the decimal
    int change = (int) change_f;
    for (i=0; change>0; i++) //count amount of coins owed
    {
        if (change >= 25)
        {
            change -= 25;
        }
        else if (change < 25 && change >= 10)
        {
            change -= 10;
        }
        else if (change < 10 && change >= 5)
        {
            change -= 5;
        }
        else if (change < 5 && change  > 0)
        {
            change -= 1;
        }
    }
    printf("%i\n", i);
}