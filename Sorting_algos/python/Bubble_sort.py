def bubble(arr, n):
    for k in range(1, n):
        flag=0
        for i in range(0, n-k):
            if(arr[i]>arr[i+1]):
                arr[i], arr[i+1] = arr[i+1], arr[i]
                flag=1
        if flag==0:
            break
    return arr

n = int(input())
l=list(map(int, input().strip().split()))[:n]
print(bubble(l, n))