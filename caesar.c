#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
        //string cipher = NULL, plain = NULL;
        int key = atoi(argv[1]);
        string plain = get_string("plaintext:");
        for (int i=0; plain[i]!= '\0'; i++)
            {
                if (plain[i] >= 65 && plain[i] <= 90) //Cipher Uppercase chr's
                {
                    plain[i] -= 65;
                    plain[i] = (plain[i]+key)%26;
                    plain[i] += 65;
                }
                else if (plain[i] >= 97 && plain[i] <= 122) //Cipher Lowercase chr's
                {
                    plain[i] -= 97;
                    plain[i] = (plain[i]+key)%26;
                    plain[i] += 97;
                }
            }
        printf ("ciphertext:%s\n",plain);
 //   else printf("you did not enter a key");
 return 0;
}