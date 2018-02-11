#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long cc = get_long_long("Please enter a valid credit card number");
    int k=0, add_num=0, check_num=0, aggregate=0,aggregate2=0,card_id=0;
    while(cc != 0)
    {

        if (k % 2 != 0)
        {
            check_num = (cc % 10);
            check_num = check_num*2;
            if (check_num >= 10)
            {
                add_num = (check_num % 10) + (check_num/10)%10;
            }
            else add_num = check_num;
            aggregate = aggregate + add_num;
        }
        else if (k % 2 == 0)
        {
            aggregate2 = aggregate2 + cc%10;
        }
        cc=cc/10;
        k++;
        if (cc > 9 && cc < 100)
        {
            card_id = cc;
        }
    }
    int sum, checksum;
    sum = aggregate + aggregate2;
    checksum = sum%10;
   /* printf("number of digits is %i",k);
    printf("sum is %i and checksum is %i\n",sum,checksum);
    printf("aggregate is %i\n", aggregate);
    printf("aggregate2 is %i\n",aggregate2);
    printf("card_id is %i\n",card_id); */
    if (checksum == 0)
    {
        if ((card_id == 34 || card_id == 37) && k == 15)
        {
            printf("AMEX\n");
        }
        else if (card_id >= 51 && card_id <= 55 && k == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (card_id /10 == 4 && (k ==13 || k == 16))
        {
            printf("VISA\n");
        }
        else printf("INVALID\n");
    }
    else printf("INVALID\n");

}