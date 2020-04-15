k = 1
n = 10
lastK = 0
temp = 0

for i in range(1, n + 1):

    if i % 2 == 0:
        for j in range(1, i + 1):
            print(k, end=" ")
            temp = k
            k += 1
    else:
        for j in range(i, 0, -1):
            print(j + lastK, end=" ")
            temp = k
            k += 1
    lastK = temp
    print("")
