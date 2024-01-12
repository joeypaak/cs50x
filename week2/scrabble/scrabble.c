#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string s);
void compare(string p1_word, string p2_word);

int SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
    compare(p1, p2);
}

int get_score(string s)
{
    int score = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (isalpha(s[i]))
        {
            score += SCORES[(int) toupper(s[i]) - 65];
        }
    }
    return score;
}

void compare(string p1_word, string p2_word)
{
    int p1 = get_score(p1_word);
    int p2 = get_score(p2_word);
    if (p1 > p2)
        printf("Player 1 wins!\n");
    else if (p1 < p2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}
