#include <stdio.h>
#include <stdlib.h>

void maxheap(int a[],int n,int i)
{
	int largest=i;
	int l=(2*i)+1;
	int r=(2*i)+2;
	int temp;
	
	while(l<n && a[l]>a[largest] )
	{		
		largest=l;
	}
	while(r<n && a[r]>a[largest])
	{
		largest=r;
	}
	if(largest != i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxheap(a,n,largest);				
	}
}

void heapsort(int a[],int n)
{
	int i,temp;
	for( i=n/2 -1;i>=0;i--)
	{
		maxheap(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		maxheap(a,i,0);
	}
}

int main()
{
	int n;
	printf("Enter value of n");
	scanf("%d",&n);
	int i,a[n];
	printf("Enter array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	heapsort(a,n);
	
	printf("sorted array:");
	
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);	
	}
}

