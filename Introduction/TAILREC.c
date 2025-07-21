/* Find the factorial of any number with the use of tail recursion */
#include <stdio.h>

// Function prototype
int factorial(int n, int fact);

int main() {
    int n, value;
    printf("Enter the number : ");
    scanf("%d", &n);

    if (n < 0)
        printf("No factorial of negative number\n");
    else if (n == 0)
        printf("Factorial of zero is 1\n");
    else {
        value = factorial(n, 1); /* Tail recursive factorial */
        printf("Factorial of %d = %d\n", n, value);
    }

    return 0;
}

int factorial(int n, int fact) {
    if (n == 1)
        return fact;
    else
        return factorial(n - 1, n * fact);
}