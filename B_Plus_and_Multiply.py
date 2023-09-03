def is_in_set(n, a, b):
    if n == 1:
        return True
    if a == 1:
        return (n - 1) % b == 0
    x = 1
    while x <= n:
        if x == n:
            return True
        if (n - x) % a == 0:
            return True
        x *= a
        x += b
    return False

# Input
t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    if is_in_set(n, a, b):
        print("Yes")
    else:
        print("No")
