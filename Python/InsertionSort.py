def insertionSort(arr, n):
    for i in range(0, n):
        j = n - 1
        while j > i:
            if arr[j] > arr[i]:
                arr[i], arr[j] = arr[j], arr[i]
            j -= 1

    for i in arr:
        print(i)


arr = [12, 11, 13, 5, 6]
n = len(arr)

insertionSort(arr, n)