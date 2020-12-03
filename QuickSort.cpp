#include<bits/stdc++.h>
using namespace std;

void swap(int *arr, int i, int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int Partition(int *arr, int start, int end){
	int i= start-1;
	int pivot=arr[end];
	for(int j=start; j<end; j++){
		if(arr[j]<pivot){
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i+1, end);
	return i+1;
}

void QuickSort(int* arr, int start, int end){
	if(start<end){
		int part=Partition(arr, start, end);
		QuickSort(arr, start, part-1);
		QuickSort(arr, part+1, end);
	}
}

void print(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={1,8,3,9,4,5,7};
	QuickSort(arr, 0, 6);
	print(arr, 7);
	
	int xyz;
	cin>>xyz;
	return 0;
}
