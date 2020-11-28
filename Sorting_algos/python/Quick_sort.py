def partition(arr, start, end):
    pivot = arr[end]
    p_index=start
    for i in range(start, end):
        if(arr[i]<pivot):
            arr[i], arr[p_index] = arr[p_index], arr[i]
            p_index+=1
    arr[p_index], arr[end] = arr[end], arr[p_index]
    return p_index

def quicks(arr, start, end):
    if(start<end):
        p = partition(arr, start, end)
        quicks(arr, start, p-1)
        quicks(arr, p+1, end)

    return arr

n=int(input())
l=list(map(int, input().strip().split()))[:n]
print(quicks(l,0, n-1))
