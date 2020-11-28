/* C program for Quick Sort */
#include<stdio.h> 

 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 


int partition (int arr[], int low, int high) 
{ 
	int j;	
	int pivot = arr[high];  
	int i = (low - 1);  

	for (j = low; j <= high- 1; j++) 
	{ 
	
		if (arr[j] < pivot) 
		{ 
			i++;  
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quick(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
	
		int pi = partition(arr, low, high);  
		quick(arr, low, pi - 1); 
		quick(arr, pi + 1, high); 
	} 
} 


void print(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
 
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
	
	quick(arr, 0, n-1); 
	print(arr, n); 
	return 0; 
} 

