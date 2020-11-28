def insertion(arr, n):
    for i in range(1,n):
        min_ind = arr[i]
        j=i-1
        while(j>=0 and arr[j]>min_ind):
            arr[j+1] = arr[j]
            j=j-1
        arr[j+1] = min_ind
    return arr
n=int(input())
l=list(map(int, input().strip().split()))[:n]
print(insertion(l,n))