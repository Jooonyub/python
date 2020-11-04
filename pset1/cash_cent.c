// Pset1 - cash
#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_float(string prompt);

int main(void)
{
    float change = get_positive_float("Change owed: ");
    int money = round(change * 100);

    int q = round(money / 25);              //qaurters - q
    money = money - 25 * q;

    int d = floor(money  / 10);             //dimes - d
    money = money - 10 * d;

    int n = floor(money / 5);              //nickels - n
    money = money - 5 * n;

    int p = money;        //pennies - p

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