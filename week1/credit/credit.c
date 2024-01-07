#include <cs50.h>
#include <stdio.h>

int get_digits(long n);
bool luhn(long n, int d);
void print(string str);
string company(long n, int d);

string AMEX = "AMEX";
string MASTERCARD = "MASTERCARD";
string VISA = "VISA";
string INVALID = "INVALID";

int main(void)
{
    long number = get_long("Number: ");
    int digits = get_digits(number);
    if (!luhn(number, digits))
        print(INVALID);
    else
        print(company(number, digits));
}

int get_digits(long n)
{
    int i = 0;
    while (n > 0)
    {
        n /= 10;
        i++;
    }
    return i;
}

bool luhn(long n, int d)
{
    int array[d];
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < d; i++)
    {
        array[i] = n % 10;
        n /= 10;
    }
    for (int i = 1; i < d; i += 2)
    {
        int multiplied = array[i] * 2;
        if (multiplied > 9)
        {
            sum1 += multiplied % 10;
            sum1 += multiplied / 10;
        }
        else
        {
            sum1 += multiplied;
        }
    }
    for (int i = 0; i < d; i += 2)
    {
        sum2 += array[i];
    }
    if ((sum1 + sum2) % 10 == 0)
        return true;
    return false;
}

void print(string str)
{
    printf("%s\n", str);
}

string company(long n, int d)
{
    for (int i = 0; i < d - 2; i++)
    {
        n /= 10;
    }
    int second_digit = n / 10;
    int first_digit = n - second_digit * 10;
    if ((n == 34 || n == 37) && d == 15)
        return AMEX;
    else if (second_digit == 4 && (d == 13 || d == 16))
        return VISA;
    else if (second_digit == 5 && d == 16)
    {
        if (first_digit > 0 && first_digit < 6)
            return MASTERCARD;
    }
    return INVALID;
}
