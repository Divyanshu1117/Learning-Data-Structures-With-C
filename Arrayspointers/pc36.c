/* Program to understand pointer to structure */
#include <stdio.h>
#include <stdlib.h>

struct rec {
    char name[10];
    int age;
    int sal;
};

int main() {
    struct rec *ptr;

    // Memory allocation
    ptr = (struct rec *)malloc(sizeof(struct rec));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the name: ");
    scanf("%9s", ptr->name);  // %9s to prevent buffer overflow

    printf("Enter the age: ");
    scanf("%d", &ptr->age);

    printf("Enter the salary: ");
    scanf("%d", &ptr->sal);

    printf("\nName: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    printf("Salary: %d\n", ptr->sal);

    free(ptr); // Always free allocated memory
    return 0;
}