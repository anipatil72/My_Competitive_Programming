t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    if k % 2 == 1:
        if n % 2 == 0 and n >= 2 * k:
            print("YES")
        else:
            print("NO")
    else:
        if n % 2 == 1:
            print("NO")
        elif n >= 2 * k:
            x = n // 2
            y = 0
            while x % k != 0:
                x -= 2
                y += 1
            if x < 0 or y > n // 2:
                print("NO")
            else:
                print("YES")
        else:
            print("NO")
