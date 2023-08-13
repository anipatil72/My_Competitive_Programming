# ॥ श्री गणेशाय नमः ॥
import math
from itertools import permutations

def next_permutation(arr):
    arr = list(arr)
    n = len(arr)
    
    for i in range(n - 2, -1, -1):
        if arr[i] < arr[i+1]:
            break
    else:
        # If no such element is found, arr is the last permutation
        return None
    
    for j in range(n - 1, i, -1):
        if arr[j] > arr[i]:
            arr[i], arr[j] = arr[j], arr[i]
            arr[i+1:] = reversed(arr[i+1:])
            return arr

def findMaxScore(arr):
    n = len(arr)

    mad = 0

    while arr:
        # print(arr)

        des = 0 


        for i in range(1, n+1):
            des+=(arr[i - 1]*i)

        mad = max(mad, des)

        arr = next_permutation(arr)

    # print("This is the maximum value for n = ", n, " value is : ",mad)
    return mad==(n*(n+1)*(2*n+1)/6)







# Example usage
arr = []

for i in range(1, 251):
    tem = [j for j in range(1, i+1)]

    # print(tem)

    ans = findMaxScore(tem)

    if ans:
        print("Yeah! it works!")
    else:
        print("Doesn't Work!")

# print(arr[0])

# for i in arr:
#     print(i)


# for i in range(1,13, 3):
#     print(i)


# ॥ जय श्री राम जय श्री कृष्ण ॥