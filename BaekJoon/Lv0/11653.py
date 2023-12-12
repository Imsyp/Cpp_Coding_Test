def primeFac(N):
    div = 2
    while(div <= N):
        while(N % div == 0):
            N /= div
            print(div)
        div += 1

N = int(input())

primeFac(N)