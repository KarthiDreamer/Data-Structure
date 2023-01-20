#include <stdio.h>
#define MAX_SIZE 10

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void getArray(int array[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d :", i + 1);
        scanf("%d", &array[i]);
    }
}

void dispArray(int array[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int n, array[50];

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    getArray(array, n);

    printf("The given array is ");
    dispArray(array, n);

    heapSort(array, n);
    printf("\nThe Sorted array is ");
    dispArray(array,n);

    return 0;
}
