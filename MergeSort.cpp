#include<bits/stdc++.h>
using namespace std;

void merge(int* left, int lenLeft, int* right, int lenRight, int* arr){
    int i=0;
    int j=0;
    int k=0;
    while(i<lenLeft && j<lenRight){
        if (left[i]<=right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<lenLeft){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<lenRight){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void mergeSort(int* Array, int lenArray){
    if(lenArray<2)
    return;
    
    int mid=lenArray/2;
    int left[mid];
    int right[lenArray-mid];
    
    for (int i=0; i<mid; i++)
        left[i]=Array[i];
    for (int i=mid; i<lenArray; i++)
        right[i-mid]=Array[i];
        
    mergeSort(left, mid);
    mergeSort(right, lenArray-mid);
    merge(left, mid, right, lenArray-mid, Array);
}

void print(int arr[], int l){
    for (int i=0; i<l; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
	int n;
	cout<<"Enter the number of element:: ";
	cin>>n;
    int arr[n];
    for (int i=0; i<n; i++)
    cin>>arr[i];
    print(arr, n);
    mergeSort(arr, n);
    print(arr, n);
    
    int xyz;
    cin>>xyz;
    return 0;
}
