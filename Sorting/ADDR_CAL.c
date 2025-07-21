/* Program of sorting using address calculation sort */
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct node
{
    int info;
    struct node *link;
};
struct node *head[10];
int n, arr[MAX];

void addr_sort();
void insert(int num, int addr);
int large_dig();
int hash_fn(int number, int k);

int main()
{
    int i;
    printf("Enter the number of elements in the list : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Unsorted list is :\n");
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");

    addr_sort();

    printf("Sorted list is :\n");
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");

    return 0;
}

void addr_sort()
{
    int i, k;
    struct node *p;
    int addr;

    k = large_dig();

    for (i = 0; i <= 9; i++)
        head[i] = NULL;

    for (i = 0; i < n; i++)
    {
        addr = hash_fn(arr[i], k);
        insert(arr[i], addr);
    }

    for (i = 0; i <= 9; i++)
    {
        printf("head(%d) -> ", i);
        p = head[i];
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->link;
        }
        printf("\n");
    }

    /*Taking the elements of linked lists in array*/
    i = 0;
    for (k = 0; k <= 9; k++)
    {
        p = head[k];
        while (p != NULL)
        {
            arr[i++] = p->info;
            p = p->link;
        }
    }
}

void insert(int num, int addr)
{
    struct node *q, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = num;

    if (head[addr] == NULL || num < head[addr]->info)
    {
        tmp->link = head[addr];
        head[addr] = tmp;
        return;
    }
    else
    {
        q = head[addr];
        while (q->link != NULL && q->link->info < num)
            q = q->link;
        tmp->link = q->link;
        q->link = tmp;
    }
}

int large_dig()
{
    int i, large = 0, ndig = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] > large)
            large = arr[i];
    }
    printf("Largest Element is %d , ", large);
    while (large != 0)
    {
        ndig++;
        large = large / 10;
    }

    printf("Number of digits in it are %d\n", ndig);
    return (ndig);
}

int hash_fn(int number, int k)
{
    int digit = 0, addr = 0, i;
    for (i = 1; i <= k; i++)
    {
        digit = number % 10;
        number = number / 10;
    }
    addr = digit;
    return (addr);
}