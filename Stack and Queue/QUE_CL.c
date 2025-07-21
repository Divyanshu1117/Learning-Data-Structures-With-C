/* Program of queue using circular linked list */
#include <stdio.h>
#include <stdlib.h> // malloc & exit ke liye

struct node
{
    int info;
    struct node *link;
} *rear = NULL;

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
    int num;
    struct node *tmp;
    printf("Enter the element for insertion: ");
    scanf("%d", &num);
    tmp = (struct node *)malloc(sizeof(struct node));

    if (tmp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    tmp->info = num;

    if (rear == NULL) /*If queue is empty */
    {
        rear = tmp;
        rear->link = rear;
    }
    else
    {
        tmp->link = rear->link;
        rear->link = tmp;
        rear = tmp;
    }
}

void del()
{
    struct node *tmp;
    if (rear == NULL)
    {
        printf("Queue underflow\n");
        return;
    }

    if (rear->link == rear) /*If only one element*/
    {
        printf("Deleted element is %d\n", rear->info);
        free(rear);
        rear = NULL;
    }
    else
    {
        tmp = rear->link;
        rear->link = tmp->link;
        printf("Deleted element is %d\n", tmp->info);
        free(tmp);
    }
}

void display()
{
    struct node *q;
    if (rear == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    q = rear->link;
    printf("Queue is: ");
    do
    {
        printf("%d ", q->info);
        q = q->link;
    } while (q != rear->link);
    printf("\n");
}