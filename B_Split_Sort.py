t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    
    if p[0] == 1 and p[-1] == n:
        print(0)
    elif p[0] == n and p[-1] == 1:
        print(3)
    elif p[0] == 1 or p[-1] == n:
        # Check for an out-of-place segment inside the sequence
        transitions = sum([1 for i in range(1, n) if p[i-1] > p[i]])
        if transitions > 0:
            print(2)
        else:
            print(1)
    else:
        print(2)
