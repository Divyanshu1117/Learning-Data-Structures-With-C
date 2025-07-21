#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
void substr(char *string, int s, int n);

int main() {
    char string[30];
    int n, s;

    printf("Enter the string : ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';  // Remove newline

    printf("Enter the position from where substring starts : ");
    scanf("%d", &s);

    printf("Enter number of characters in the substring : ");
    scanf("%d", &n);

    substr(string, s, n);
    printf("\n");

    return 0;
} /*End of main()*/

void substr(char *string, int s, int n) {
    int i;

    // Move pointer to starting position
    for (i = 0; i < s - 1; i++) {
        string++;
        if (*string == '\0') {
            printf("There are less than %d characters in string\n", s);
            exit(1);
        }
    }

    // Print n characters
    for (i = 1; i <= n; i++) {
        if (*string == '\0')
            break;
        printf("%c", *string);
        string++;
    }
} /*End of substr()*/