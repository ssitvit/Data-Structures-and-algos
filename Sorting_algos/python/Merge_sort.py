def merge(arr):
    if len(arr)>1:

        m = len(arr)//2
        l = arr[:m]
        r = arr[m:]

        merge(l)
        merge(r)
        i=0
        j=0
        k=0
        while(i<len(l) and j<len(r)):
            if(l[i]<r[j]):
                arr[k]=l[i]
                i+=1
            else:
                arr[k] = r[j]
                j+=1
            k+=1
        
        while(i<len(l)):
            arr[k] = l[i]
            i+=1
            k+=1
        while(j<len(r)):
            arr[k] = r[j]
            j+=1
            k+=1
    return arr
n=int(input())
l=list(map(int, input().strip().split()))[:n]
print(merge(l))