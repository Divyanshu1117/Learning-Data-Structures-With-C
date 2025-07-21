/* Find the factorial of any number */
#include <stdio.h>

// Function prototype
int factorial(int k);

int main() {
    int n, value;
    printf("Enter the number : ");
    scanf("%d", &n);

    if (n < 0)
        printf("No factorial of negative number\n");
    else if (n == 0)
        printf("Factorial of zero is 1\n");
    else {
        value = factorial(n); /* Function for factorial of number */
        printf("Factorial of %d = %d\n", n, value);
    }
    return 0;
} /* End of main() */

int factorial(int k) {
    if (k <= 1)
        return 1;
    return k * factorial(k - 1); /* Recursive function call */
}