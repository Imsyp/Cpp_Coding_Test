def Sigma(n):
    sum = 0
    for i in range(1, int(n**(1/2) + 1)):
        if(n % i == 0):
            sum += i
            if(i**2 != n):
                sum += n//i
    return sum

def isEven(m):
    numOfEven = 0
    for i in range(1, m + 1):
        if(Sigma(i) % 2 != 0):
            numOfEven += 1
    return numOfEven

m = int(input())

isEven(m)