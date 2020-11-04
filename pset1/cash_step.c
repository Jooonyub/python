// Pset1 - cash

#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_float(string prompt);

int main(void)
{
    float change = get_positive_float("Change owed: ");

    float q = floor(change / 0.25);              //qaurters - q
    change = change - 0.25*q;
    printf("q: %.0f / change = %f\n", q, change);

    float d = floor(change  / 0.10);             //dimes - d
    change = change - 0.10*d;
    printf("d: %.0f / change = %f\n", d, change);

    float n = floor(change / 0.05);              //nickels - n
    change = change - 0.05*n;
    printf("n: %.0f / change = %f\n", n, change);

    float p = change / 0.01;              //pennies - p
    printf("p: %.0f / change = %f\n", p, change);

    float sum = q + d + n + p;
    printf(" qaurters - q: %.0f\n dimes - d: %.0f\n nickels - n: %i\n pennies - p: %.0f\n", q, d, n, p);
    printf("%.0f\n", sum);

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