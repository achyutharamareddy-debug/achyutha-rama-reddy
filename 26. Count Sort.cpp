//Count Sort
#include<stdio.h>
void countsort(int a[],int n)
{
	int i=0,temp[n];
	int max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	int c[max+1]={0};
	for(i=0;i<n;i++)
	{
		c[a[i]]++;
	}
	for(i=1;i<max+1;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		temp[--c[a[i]]]=a[i];
	}
	for(i=0;i<n;i++)
	{
		a[i]=temp[i];
	}
}
int main()
{
	int n,i=0,max;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the array : ");
	for(i=0;i<n;i++)
	{
		printf("\nEnter element - %d : ",i+1);
		scanf("%d",&a[i]);
	}
	countsort(a,n);
	printf("\nAfter sorting, the array is :\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	return 0;
}
