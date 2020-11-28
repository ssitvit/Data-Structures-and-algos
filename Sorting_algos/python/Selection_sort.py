def selection(a, n):
    for i in range(0, n):
        imin = i
        for j in range(i+1, n):
            if(a[j]<a[imin]):
                imin=j
        
        a[i], a[imin] = a[imin], a[i]
    return a

n=int(input())
l=list(map(int, input().strip().split()))[:n]
print(selection(l,n))