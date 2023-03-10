# ॥ श्री गणेशाय नमः ॥
def minimize_difference(a, m):
    prof = [0] * (m + 1)
    for i in range(len(a)):
        for j in range(1, m + 1):
            if a[i] % j == 0:
                prof[j] += 1
    min_diff = float('inf')
    team = []
    for i in range(len(a)):
        flag = True
        for j in range(1, m + 1):
            if prof[j] <= 0:
                flag = False
                break
        if flag:
            team.append(a[i])
            for j in range(1, m + 1):
                if a[i] % j == 0:
                    prof[j] -= 1
        if len(team) == m:
            min_diff = min(min_diff, max(team) - min(team))
            team.pop(0)
    return min_diff


t = int(input())

for i in range(0, t):
    # print(i)
    n = int(input())
    c = str(input())
    m = int(input())

    a = [0]*(n)

    for j in range(0, n):
        d = int(input())

        a[j] = d


print(minimize_difference(a, m))

# ॥ जय श्री राम जय श्री कृष्ण ॥
