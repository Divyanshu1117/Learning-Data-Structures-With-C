#include <stdio.h>
#include <string.h>

// Function prototype
int Length(char *str);

int main() {
    char str[25];
    int length;

    printf("Enter the string : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character

    length = Length(str);
    printf("Length of string is %d\n", length);

    return 0;
} /*End of main()*/

int Length(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
} /*End of Length()*/