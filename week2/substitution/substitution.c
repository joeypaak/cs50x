#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string plaintext, string key);
string lowercase_key(string s);
bool valid_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (!valid_key(argv[1]))
        return 1;
    string key = lowercase_key(argv[1]);
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
}

string encrypt(string plaintext, string key)
{
    // A ~ Z: 65 ~ 90
    // a ~ z: 97 ~ 122
    int text_length = strlen(plaintext);
    string ciphertext = plaintext;
    for (int i = 0; i < text_length; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            if (isupper(c))
                ciphertext[i] = key[c - 65] - 32;
            else
                ciphertext[i] = key[c - 97];
        }
    }
    return ciphertext;
}

string lowercase_key(string s)
{
    string key = s;
    for (int i = 0; i < 26; i++)
        key[i] = tolower(key[i]);
    return key;
}

bool valid_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    for (int i = 0; i < 26; i++)
    {
        char c = tolower(key[i]);
        // check if character is invalid
        if (!isalpha(c))
        {
            printf("Invalid characters!\n");
            return false;
        }
        // check if there are duplicate characters
        for (int j = i + 1; j < 26; j++)
            if (c == tolower(key[j]))
            {
                printf("Duplicate characters!\n");
                return false;
            }
    }
    return true;
}
