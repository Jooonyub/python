// Pset1 - cash
#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_float(string prompt);

int main(void)
{
    float change = get_positive_float("Change owed: ");

    int q = round(change / 0.25);              //qaurters - q
    change = change - 0.25*q;

    int d = floor(change  / 0.10);             //dimes - d
    change = change - 0.10*d;

    int n = floor(change / 0.05);              //nickels - n
    change = change - 0.05*n;

    int p = floor(change / 0.01);              //pennies - p

    int sum = q + d + n + p;
    printf("%i\n", sum);

    return 0;
}


float get_positive_float(string prompt)
{
    float cash;
    do
    {
        cash = get_float("%s", prompt);
    }
    while (cash < 0);
    return cash;
}