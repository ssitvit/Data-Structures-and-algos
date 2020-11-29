# Linear search

def linearSearch(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            print(f'found at {i}')
            return
    print('Not found')

arr = [1,2,3,4,5,6,7,8,9]
linearSearch(arr,4)