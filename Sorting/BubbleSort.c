/*Sort an array using bubble sort from smallest to largest.
Change the sign to make it from largest to smallest*/

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
	int n, i, j, swapped;
	scanf("%d", &n);
	int *arr = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < n; i++)
	{
		swapped = 0;
		for(j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				swapped = 1;
			}
		}
		if(!swapped)
		{
			break;
		}
	}
	for(i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if(i == n-1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}
