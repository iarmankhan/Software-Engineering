def binarySearch(l_list, item):
    low = 0
    high = len(l_list) - 1
    
    while low <= high:
        mid = (low + high) // 2
        guess = l_list[mid]

        if guess == item:
            print("Item Found at postion", mid)
            return
        if guess > item:
            high = mid - 1
        else:
            low = mid + 1

    print("Item not found")
    return


a = [1, 2, 4, 6, 10, 30, 33, 34, 55, 100]
binarySearch(a, 11)

