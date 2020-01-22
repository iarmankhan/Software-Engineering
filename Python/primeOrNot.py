def isPrime(n):
    flag = True
    div = 2
    while(div < n):
        if(n % 2 == 0):
            flag = False
        div += 1
    return flag

n = 3
s = isPrime(n)

if(s):
    print("Prime number")
else:
    print("Not a prime")