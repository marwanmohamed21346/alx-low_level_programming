#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to add two strings of arbitrary length
char *add_strings(char *a, char *b)
{
    // Find the lengths of the strings
    int len_a = strlen(a);
    int len_b = strlen(b);

    // Allocate memory for the result string
    int len_res = len_a > len_b ? len_a + 1 : len_b + 1;
    char *res = malloc(len_res + 1);

    // Initialize the result string with zeros
    memset(res, '0', len_res);
    res[len_res] = '\0';

    // Add the strings from right to left, keeping track of the carry
    int i = len_a - 1;
    int j = len_b - 1;
    int k = len_res - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        // Get the digits from the strings, or zero if out of bounds
        int digit_a = i >= 0 ? a[i] - '0' : 0;
        int digit_b = j >= 0 ? b[j] - '0' : 0;

        // Add the digits and the carry
        int sum = digit_a + digit_b + carry;

        // Update the result string, the carry, and the indices
        res[k] = (sum % 10) + '0';
        carry = sum / 10;
        i--;
        j--;
        k--;
    }

    // Return the result string
    return res;
}

// A function to print the first n Fibonacci numbers
void print_fibonacci(int n)
{
    // Check if n is valid
    if (n < 1)
    {
        printf("Invalid input\n");
        return;
    }

    // Initialize the first two Fibonacci numbers as strings
    char *a = "1";
    char *b = "2";

    // Print the first Fibonacci number
    printf("%s", a);

    // Loop from the second to the nth Fibonacci number
    for (int i = 2; i <= n; i++)
    {
        // Print a comma and a space before each number
        printf(", ");

        // Print the current Fibonacci number
        printf("%s", b);

        // Update the next Fibonacci number by adding the previous two
        char *c = add_strings(a, b);

        // Free the memory of the previous Fibonacci number
        free(a);

        // Update the pointers for the next iteration
        a = b;
        b = c;
    }

    // Print a new line at the end
    printf("\n");
}

// The main function
int main(void)
{
    // Call the print_fibonacci function with 98 as argument
    print_fibonacci(98);

    // Return 0 to indicate success
    return 0;
}
