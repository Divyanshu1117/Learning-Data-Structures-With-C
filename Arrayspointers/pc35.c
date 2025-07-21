/* Program to understand the use of realloc function */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *ptr;

    // Allocate 6 bytes (5 characters + '\0')
    ptr = (char *)malloc(6);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(ptr, "ankit");  // Copy "ankit" into allocated memory
    printf("%s is in memory block\n", ptr);

    // Reallocate memory to 8 bytes (7 characters + '\0')
    ptr = (char *)realloc(ptr, 8);
    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    printf("%s is in memory block\n", ptr);

    // Copy new string (within 8 bytes)
    strcpy(ptr, "rishabh");
    printf("Now %s is in memory block\n", ptr);

    free(ptr); // Always free allocated memory
    return 0;
}