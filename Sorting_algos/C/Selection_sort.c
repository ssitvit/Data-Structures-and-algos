/* C program for Selection sort*/
#include<stdio.h>

void selection(int arr[], int n)
{
	int i, min,j;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		int temp = arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

int main()
{
	int n;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selection(arr, n);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
return 0;
}
