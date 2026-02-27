// radix sort by using array format//
# include<stdio.h>
void countsort(int a[],int n,int place)
{
	int count[10]={0};int temp[n];
	for(int i=0;i<n;i++)
	{
		count[(a[i]/place)%10]++;
	}
	for(int i=1;i<10;i++)
	{
	count[i]=count[i]+count[i-1];
	}
	for( int i=n-1;i>=0;i--)
	{
	 temp[--count[(a[i]/place)%10]]=a[i];
	}
for(int i=0;i<n;i++)
{
	a[i]= temp[i];
}
}
void radixsort(int a[],int n)
{  int	max= a[0];
	for(int i=1;i<n;i++)
	{
	if(a[i]>max)
	{   
	max=a[i];
	}
	}
   for(int pos=1;max/pos>0;pos=pos*10)
	{
 countsort( a,n,pos);
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
	radixsort(a,n);
	printf("\nThe Array after sorting is : \n");
	for( int i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	return 0;
}
