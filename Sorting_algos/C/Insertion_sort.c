/* C program for Insertion Sort */
#include<stdio.h>

int main()
{
	int arr[10], i, j;
	int n, min;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	}	
	for(i=1;i<n;i++)
	{
		min = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>min)
		{
			arr[j+1] = arr[j];
			j=j-1;
		}
		
		arr[j+1]=min;
	}
	
	for(i=0;i<n;i++)
		printf("%d  ", arr[i]);
	
return 0;
}
