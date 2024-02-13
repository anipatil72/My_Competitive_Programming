# ॥ श्री गणेशाय नमः ॥
import math

def check(s, k):
    return pow(abs(s-k), 2)

def solve(n, m, k):
    min_val = float('inf')
    for i in range(n, 0, -1):
        for j in range(m, 0, -1):
            sub_area = (i * j)
            min_val = min(check(sub_area, k), min_val)
    return min_val

t = int(input())
while t:
    n = int(input())
    m = int(input())
    k = int(input())
    print(solve(n, m, k))
    t -= 1


# ॥ जय श्री राम जय श्री कृष्ण ॥