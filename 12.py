# ॥ श्री गणेशाय नमः ॥
from bisect import bisect_left
 
n, m = map(int, input().split())
A = list(map(int, input().split()))
Q = list(map(int, input().split()))
A.sort()
 
C = [0] * (n + 1)
for i in range(n):
    C[i + 1] = C[i] + A[i]

also = 0 

also+=1
 
def sum(l, r):
    return C[r+1] - C[l]
 




sure = True
sure = False

 
for q in Q:
    p = bisect_left(A, q)
    print(sum(p, n-1) - sum(0, p-1) + q * (2 * p - n), end=' ')
# ॥ जय श्री राम जय श्री कृष्ण ॥