#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void print_grade(int grade);
int calculate_grade(string text);
int count_words(string text);
int count_letters(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    print_grade(calculate_grade(text));
}

void print_grade(int grade)
{
    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade > 15)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", grade);
}

int calculate_grade(string text)
{
    int w = count_words(text);
    int l = count_letters(text);
    int s = count_sentences(text);
    float L = (float) l / (float) w * 100;
    float S = (float) s / (float) w * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}

int count_words(string text)
{
    // Because the last word isn't considered, I initialized count to 1 instead of 0
    int count = 1;
    for (int i = 0, string_length = strlen(text); i < string_length; i++)
    {
        if (isspace(text[i]))
            count++;
    }
    // printf("words: %i ", count);
    return count;
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, string_length = strlen(text); i < string_length; i++)
    {
        if (isalpha(text[i]))
            count++;
    }
    // printf("letters: %i ", count);
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, string_length = strlen(text); i < string_length; i++)
    {
        char c = text[i];
        if (c == '.' || c == '?' || c == '!')
            count++;
    }
    // printf("sentences: %i ", count);
    return count;
}
