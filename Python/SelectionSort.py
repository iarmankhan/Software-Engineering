def selectionSort(arr, n):
    for i in range(0, n):
        min_index = i

        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        arr[min_index], arr[i] = arr[i], arr[min_index]

    for i in arr:
        print(i, end='\t')

    print('')

arr = [3, 1, 2, 4, 6]
n = len(arr)

selectionSort(arr, n)