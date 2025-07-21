/* Program of sorted linked list */

#include <stdio.h>
#include <stdlib.h>  // malloc, exit ke liye

struct node
{
    int info;
    struct node *link;
} *start = NULL;

void insert(int num);
void del(int num);
void display();

int main()
{
    int choice, m;

    while (1)
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &m);
            insert(m);
            break;
        case 2:
            printf("Enter the element to be deleted : ");
            scanf("%d", &m);
            del(m);
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

void insert(int num)
{
    struct node *q, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = num;
    tmp->link = NULL;

    /* list empty or item to be added in beginning */
    if (start == NULL || num < start->info)
    {
        tmp->link = start;
        start = tmp;
        return;
    }
    else
    {
        q = start;
        while (q->link != NULL && q->link->info < num)
            q = q->link;
        tmp->link = q->link;
        q->link = tmp;
    }
}

void del(int num)
{
    struct node *tmp, *q;

    if (start == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return;
    }

    /* first element delete */
    if (start->info == num)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        printf("%d deleted\n", num);
        return;
    }

    q = start;
    while (q->link != NULL && q->link->info != num)
        q = q->link;

    if (q->link == NULL)
    {
        printf("Element %d not found\n", num);
        return;
    }

    tmp = q->link;
    q->link = tmp->link;
    free(tmp);
    printf("%d deleted\n", num);
}

void display()
{
    struct node *q;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    q = start;
    printf("List is :\n");
    while (q != NULL)
    {
        printf("%d ", q->info);
        q = q->link;
    }
    printf("\n");
}