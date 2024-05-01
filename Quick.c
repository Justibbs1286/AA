
#include <stdio.h>
#include <stdlib.h>

int partition(int arr[],int lb,int ub)
{
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	int temp;
	while(start<end)
	{
		while(arr[start]<=pivot)
		{
			start++;
		}
		while(arr[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			temp=arr[start];
			arr[start]=arr[end];
			arr[end]=temp;
		}
	}
	temp=arr[lb];
	arr[lb]=arr[end];
	arr[end]=temp;
	
	return end;
}

void quicksort(int arr[],int lb,int ub)
{
	if(lb<ub)
	{
		int loc=partition(arr,lb,ub);
		quicksort(arr,lb,loc-1);
		quicksort(arr,loc+1,ub);
	}
}

int main()
{
	int i,arr[5];
	printf("Enter the array");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,4);
	printf("Soreted array:");
	for(i=0;i<5;i++)
	{
		printf("%d",arr[i]);
	}
}
