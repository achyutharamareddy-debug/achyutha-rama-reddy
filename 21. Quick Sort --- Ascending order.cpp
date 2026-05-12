//Quick Sort --- Ascending order
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition( int a[],int low,int high)
{
	int pivot= a[low];
	int start=low;
	int end=high;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(&a[start],&a[end]);
		}
	}
	swap(&a[end],&a[low]);
	return end;
}
void quicksort(int a[],int low, int high)
{
	if(low<high)
	{
		int location = partition( a,low,high);
		quicksort(a,low,location-1);
		quicksort(a,location+1,high);
	}
}
int main()
{
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter %d value : ",i+1);
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("\nSorted array in Ascending order : \n");
	for(int i=0;i<n;i++)
	{
		printf("\t %d",a[i]);
	}
}
