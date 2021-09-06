#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main(void)
{
    int n, index;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n - 1; i++)
    {
        index = i;
        for(int j = i; j < n; j++)
        {
            if(arr[j] < arr[index])
            {
                index = j;
            }
        }
        if(index != i)
        {
            swap(arr, i, index);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(i != n - 1)
        {
            printf("%d ", arr[i]);
        }
        else
        {
            printf("%d\n", arr[i]);
        }
    }
}