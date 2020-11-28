#include<stdio.h>

void bubble(int arr[], int n)
{
	int k, i;
	for(k=0;k<n-1;k++)
	{
		int flag=0;
		for(i=0;i<n-k-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				int temp = arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
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
	bubble(arr, n);
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
return 0;
}
