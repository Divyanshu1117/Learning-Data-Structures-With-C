#include <stdio.h>
#include <string.h>

// Function prototype
void CopyString(char *str1, char *str2);

int main() {
    char str1[30], str2[30];

    printf("Enter the first string : ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline

    printf("Enter the second string : ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline

    CopyString(str1, str2);

    printf("Now the first string is same as the second string \n");
    printf("First string is %s \n", str1);
    printf("Second string is %s \n", str2);

    return 0;
} /* End of main() */

void CopyString(char *str1, char *str2) {
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
} /* End of CopyString */