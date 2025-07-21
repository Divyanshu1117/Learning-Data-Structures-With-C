/* Program of sorting through heapsort */
#include <stdio.h>

int arr[20], n;

void display();
void create_heap();
void insert(int num, int loc);
void heap_sort();
void del_root(int last);

int main()
{
    int i;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Entered list is :\n");
    display();

    create_heap();

    printf("Heap is :\n");
    display();

    heap_sort();
    printf("Sorted list is :\n");
    display();

    return 0;
} /* End of main() */

void display()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
} /* End of display() */

void create_heap()
{
    int i;
    for (i = 0; i < n; i++)
        insert(arr[i], i);
} /* End of create_heap() */

void insert(int num, int loc)
{
    int par;
    while (loc > 0)
    {
        par = (loc - 1) / 2;
        if (num <= arr[par])
        {
            arr[loc] = num;
            return;
        }
        arr[loc] = arr[par];
        loc = par;
    }
    arr[0] = num;
} /* End of insert() */

void heap_sort()
{
    int last;
    for (last = n - 1; last > 0; last--)
        del_root(last);
} /* End of heap_sort() */

void del_root(int last)
{
    int left, right, i, temp;
    i = 0; /* Replace root with last element */

    /* Exchange last element with the root */
    temp = arr[i];
    arr[i] = arr[last];
    arr[last] = temp;

    left = 2 * i + 1;  /* left child of root */
    right = 2 * i + 2; /* right child of root */

    while (right < last)
    {
        if (arr[i] >= arr[left] && arr[i] >= arr[right])
            return;
        if (arr[right] <= arr[left])
        {
            temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            i = left;
        }
        else
        {
            temp = arr[i];
            arr[i] = arr[right];
            arr[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == last - 1 && arr[i] < arr[left])
    {
        temp = arr[i];
        arr[i] = arr[left];
        arr[left] = temp;
    }
} /* End of del_root() */