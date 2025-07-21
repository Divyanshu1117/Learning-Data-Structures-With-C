/* Program of queue using linked list */
#include <stdio.h>
#include <stdlib.h> // malloc and exit ke liye

struct node
{
    int info;
    struct node *link;
} *front = NULL, *rear = NULL;

void insert();
void del();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

void insert()
{
    struct node *tmp;
    int added_item;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Input the element for adding in queue: ");
    scanf("%d", &added_item);
    tmp->info = added_item;
    tmp->link = NULL;

    if (front == NULL) // Queue is empty
        front = tmp;
    else
        rear->link = tmp;
    rear = tmp;
}

void del()
{
    struct node *tmp;
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    tmp = front;
    printf("Deleted element is %d\n", tmp->info);
    front = front->link;
    if (front == NULL) // Queue became empty
        rear = NULL;
    free(tmp);
}

void display()
{
    struct node *ptr = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}