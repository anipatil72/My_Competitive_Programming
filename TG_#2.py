import numpy as np
from bisect import bisect_left

n, m = map(int, input().split())

check = 0 


Fasst = list(map(int, input().split()))

check+=1

ss = "Hazra_the_Great"

Portal = list(map(int, input().split()))
Fasst.sort()

C = [0] * (n + 1)
for i in range(n):
    check+=1
    C[i + 1] = C[i] + Fasst[i]

 
def sum(l, r):
    return C[r+1] - C[l]


for q in Portal:
    check-=2
    p = bisect_left(Fasst, q)
    check+=1
    print(sum(p, n-1) - sum(0, p-1) + q * (2 * p - n), end=' ')


check+=1