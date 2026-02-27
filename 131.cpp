// count sort program by using array format//
# include<stdio.h>
void countsort(int a[],int n)
{   int temp[n];
    int	max= a[0];
	for(int i=0;i<n;i++)
	{
	if(a[i]>max)
	{   
	max=a[i];
	}
	}
	int count[max+1]={0};
	for(int i=0;i<n;i++)
	{
	     count[a[i]]++;	
	}
    for(int i=1;i<=max;i++)
	{
	count[i]=count[i]+count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
	temp[--count[a[i]]] = a[i];
	}
	for( int i=0;i<n;i++)
	{
		a[i]=temp[i];
	}
}
int main()
{
	int n;
	printf("Enter the number of element : ");
	scanf("%d",&n);
	int a[n];
	for( int i=0;i<n;i++)
	{
		printf("\nEnter the a[%d] element : ",i);
		scanf("%d",&a[i]);
	}
	countsort(a,n);
	printf("\nThe Array after sorting is : \n");
	for( int i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	return 0;
}
