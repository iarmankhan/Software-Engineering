# Naive solution
def hasPairWithSumNaive(arr, sumX):

    for i in range(0, len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] + arr[j] == sumX:
                return True
    
    return False

def hasPairWithSumBetter(arr, sumX):
    mySet = {}

    for i in range(len(arr)):
        if arr[i] in mySet:
            return True
        mySet[sumX - arr[i]] = True
    return False


arr = [1, 2, 9, 8, 5, 3, 363]
sumX = 8

print(hasPairWithSumBetter(arr, sumX))
