#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) //check for proper number of arguments
    {
        printf("You did not enter the correct number of arguments.");
        return 1;
    }
    string key = argv[1];
    int key_len = strlen(key); // find length of key
    for (int i = 0; i < key_len; i++) //verify feasibility of key
    {
        key[i] = toupper(key[i]);  // capitalize key
        if(!isalpha(key[i]))
        {
            printf("Please enter a key using only letters");
            return 1;
        }
    }
        string plain = get_string("Plaintext:");  //get text to be encoded
        string cipher = plain;
        for (int i = 0, j = 0; plain[i] != '\0'; i++) //encrypt text
        {
            if (isalpha(plain[i]) && islower(plain[i])) // encrypt lowercase chars
            {
                cipher[i] = ((plain[i] - 97) + (key[j%key_len]-65))%26;
                cipher[i] += 97;
                j++;
            }
            if (isalpha(plain[i]) && isupper(plain[i])) // encrypt uppercase chars
            {
                cipher[i] = ((plain[i] - 65) + (key[j%key_len]-65))%26;
                cipher[i] += 65;
                j++;
            }
            else cipher[i] = plain[i]; //passthrough non-alpha chars

        }
    printf("ciphertext: %s\n", cipher); // print ciphertext
    return 0;

}