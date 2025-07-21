/* Program of sorting using quick sort through recursion */
#include <stdio.h>
#define MAX 30

void quick(int arr[], int low, int up);
void display(int arr[], int low, int up);

int main()
{
    int array[MAX], n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Unsorted list is :\n");
    display(array, 0, n - 1);

    quick(array, 0, n - 1);

    printf("Sorted list is :\n");
    display(array, 0, n - 1);

    return 0;
} /* End of main() */

void quick(int arr[], int low, int up)
{
    int piv, temp, left, right;
    int pivot_placed = 0; // FALSE
    left = low;
    right = up;
    piv = low; // Take the first element as pivot

    if (low >= up)
        return;

    printf("Sublist : ");
    display(arr, low, up);

    /* Loop till pivot is placed at proper place */
    while (!pivot_placed)
    {
        /* Compare from right to left */
        while (arr[piv] <= arr[right] && piv != right)
            right--;
        if (piv == right)
            pivot_placed = 1; // TRUE
        if (arr[piv] > arr[right])
        {
            temp = arr[piv];
            arr[piv] = arr[right];
            arr[right] = temp;
            piv = right;
        }

        /* Compare from left to right */
        while (arr[piv] >= arr[left] && left != piv)
            left++;
        if (piv == left)
            pivot_placed = 1;
        if (arr[piv] < arr[left])
        {
            temp = arr[piv];
            arr[piv] = arr[left];
            arr[left] = temp;
            piv = left;
        }
    } /* End of while */

    printf("-> Pivot Placed is %d -> ", arr[piv]);
    display(arr, low, up);

    quick(arr, low, piv - 1);
    quick(arr, piv + 1, up);
} /* End of quick() */

void display(int arr[], int low, int up)
{
    int i;
    for (i = low; i <= up; i++)
        printf("%d ", arr[i]);
    printf("\n");
} /* End of display() */