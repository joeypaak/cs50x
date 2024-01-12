#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
string encrypt(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
}

bool only_digits(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}

string encrypt(string plaintext, int key)
{
    int text_length = strlen(plaintext);
    string ciphertext = plaintext;
    for (int i = 0; i < text_length; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            if (isupper(c))
                ciphertext[i] = (c - 65 + key) % 26 + 65;
            else
                ciphertext[i] = (c - 97 + key) % 26 + 97;
        }
    }
    return ciphertext;
}
