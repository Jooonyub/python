// Function exercise

// includes
#include <cs50.h>
#include <stdio.h>

// declare function
int add_two_ints(int a, int b);


int main(void)
{
    // ask user for input
    printf("Give me an integer: \n");
    int x = get_int();
    printf("Give me an integer: \n");
    int y = get_int();

    // add the numbers together via a function call
    int z = add_two_ints(x, y);

    printf("The sum of %i and %i is %i. \n", x, y, z);
}


int add_two_ints(int a, int b)
{
    int sum;    // declare variable
    sum = a + b;  // calculate the sum
    return sum; // give result back
}