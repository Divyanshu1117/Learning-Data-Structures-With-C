/* Program of double linked list */
#include <stdio.h>
#include <stdlib.h>  // For malloc and exit()

struct node
{
    struct node *prev;
    int info;
    struct node *next;
} *start;

void create_list(int num);
void addatbeg(int num);
void addafter(int num, int pos);
void del(int num);
void display();
void count();
void rev();

int main()
{
    int choice, n, m, po, i;
    start = NULL;
    while (1)
    {
        printf("\n1.Create List\n");
        printf("2.Add at beginning\n");
        printf("3.Add after\n");
        printf("4.Delete\n");
        printf("5.Display\n");
        printf("6.Count\n");
        printf("7.Reverse\n");
        printf("8.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("How many nodes you want : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter the element : ");
                scanf("%d", &m);
                create_list(m);
            }
            break;
        case 2:
            printf("Enter the element : ");
            scanf("%d", &m);
            addatbeg(m);
            break;
        case 3:
            printf("Enter the element : ");
            scanf("%d", &m);
            printf("Enter the position after which this element is inserted : ");
            scanf("%d", &po);
            addafter(m, po);
            break;
        case 4:
            printf("Enter the element for deletion : ");
            scanf("%d", &m);
            del(m);
            break;
        case 5:
            display();
            break;
        case 6:
            count();
            break;
        case 7:
            rev();
            break;
        case 8:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

/* Create list by adding at the end */
void create_list(int num)
{
    struct node *q, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = num;
    tmp->next = NULL;

    if (start == NULL)
    {
        tmp->prev = NULL;
        start = tmp;
    }
    else
    {
        q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = tmp;
        tmp->prev = q;
    }
}

void addatbeg(int num)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = num;
    tmp->prev = NULL;

    if (start == NULL)
    {
        tmp->next = NULL;
        start = tmp;
    }
    else
    {
        tmp->next = start;
        start->prev = tmp;
        start = tmp;
    }
}

void addafter(int num, int c)
{
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0; i < c - 1; i++)
    {
        if (q == NULL)
        {
            printf("There are less than %d elements\n", c);
            return;
        }
        q = q->next;
    }
    if (q == NULL)
    {
        printf("Position not found\n");
        return;
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = num;
    tmp->next = q->next;
    if (q->next != NULL)
        q->next->prev = tmp;
    tmp->prev = q;
    q->next = tmp;
}

void del(int num)
{
    struct node *tmp = start;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (start->info == num)
    {
        tmp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->info != num)
        tmp = tmp->next;
    if (tmp == NULL)
    {
        printf("Element %d not found\n", num);
        return;
    }
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    free(tmp);
}

void display()
{
    struct node *q = start;
    if (q == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List is : ");
    while (q != NULL)
    {
        printf("%d ", q->info);
        q = q->next;
    }
    printf("\n");
}

void count()
{
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    printf("Number of elements are %d\n", cnt);
}

void rev()
{
    struct node *p1, *p2;
    if (start == NULL)
        return;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
}