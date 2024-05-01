
#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for ( i = 1; i < n; i++) 
	{	
        if (arr[i] > max) 
		{
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int pos) {
    int b[n];
    int count[10] = {0};
	int i;
    for ( i = 0; i < n; i++) {
        count[(arr[i] / pos) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] =count[i]+count[i - 1];
    }

    for ( i = n - 1; i >= 0; i--) {
        b[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }

    for ( i = 0; i < n; i++) {
        arr[i] = b[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    int pos;
    for ( pos = 1; max / pos > 0; pos=pos* 10) {
        countSort(arr, n, pos);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the arr: ");
    scanf("%d", &n);
    int i;
    int arr[n];
    
    printf("Enter the elements of the arr: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original arr: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    radixSort(arr, n);
    
    printf("Sorted arr: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}