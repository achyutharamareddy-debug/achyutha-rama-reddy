// Merge sort program by using array format//
# include<stdio.h>
void merge(int a[],int low,int mid,int high);
void mergesort(int a[],int low, int high)
{
	if(low<high)
	{
	int	mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);	
	}
}
void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=0;
	int temp[high-low+1];
	while(i<=mid && j<=high)
	{
			if(a[i]<+a[j])
	{
	temp[k]=a[i];
	i++;
	k++;	
	}
	else
	{
		temp[k]=a[j];
		j++;
		k++;
	}
	}
	if(j>high)
{
	while(i<=mid )
	{
		temp[k]=a[i];
		i++;
		k++;
	}
	}
	else
	{
		while(j<=high)
		{
			temp[k]=a[j];
			j++;
			k++;
		}
		}
	for(i=low,k=0;i<=high;i++,k++)
{
	a[i]=temp[k];
}
}
int main()
{
	int n;
	printf("Enter the number of element : ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the a[%d] element : ",i);
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("\nThe Array after sorting is : \n");
	for(int i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	return 0;
}
