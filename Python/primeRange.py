def printPrime():
    n = int(input("Enter Limit: \n"))
    prime = [True] * (n+1)

    divisor = 2
    while((divisor * divisor) <= n):
        
        if(prime[divisor]):
            i = 2 * divisor
            while(i<=n):
                prime[i] = False
                i += divisor
        
        divisor += 1

    j = 2

    while j <= n:
        if(prime[j]):
            print(j)
        j += 1


printPrime()

