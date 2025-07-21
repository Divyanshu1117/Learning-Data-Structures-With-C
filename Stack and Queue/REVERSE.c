#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char item);
char pop();

int main()
{
    char str[MAX];
    int i, len;

    printf("Enter the string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    len = strlen(str);

    // Push all characters on stack
    for (i = 0; i < len; i++)
        push(str[i]);

    // Pop characters back into string
    for (i = 0; i < len; i++)
        str[i] = pop();

    printf("Reversed string is: %s\n", str);

    return 0;
}

void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
        stack[++top] = item;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
        return stack[top--];
}