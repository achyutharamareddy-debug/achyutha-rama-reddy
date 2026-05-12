//Radix Sort
#include<stdio.h>
void countsort(int a[],int n,int place)
{
	int c[10]={0},temp[n],i;
	for(i=0;i<n;i++)
	{
		c[(a[i]/place)%10]++;
	}
	for(i=1;i<10;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		temp[--c[(a[i]/place)%10]] = a[i];
	}
	for(i=0;i<n;i++)
	{
		a[i]=temp[i];
	}
}
void radixsort(int a[],int n)
{
	int max = a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	for(int pos=1;max/pos>0;pos*=10)
	{
		countsort(a,n,pos);
	}
}
int main()
{
	int n,i=0;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the array : ");
	for(i=0;i<n;i++)
	{
		printf("\nEnter element - %d : ",i+1);
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
	printf("\nAfter sorting, the array is :\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	return 0;
}
