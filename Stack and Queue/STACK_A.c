#include <stdio.h>
#include <stdlib.h>  // for exit()

#define MAX 5

int top = -1;
int stack_arr[MAX];

void push();
void pop();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);  // exit safely
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

void push()
{
    int pushed_item;
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter the item to be pushed in stack : ");
        scanf("%d", &pushed_item);
        stack_arr[++top] = pushed_item;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped element is : %d\n", stack_arr[top--]);
}

void display()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements :\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack_arr[i]);
    }
}