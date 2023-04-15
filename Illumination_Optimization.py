def get_lights(b, loc, m, r):
    if loc >= m:
        return 0
    if len(b) == 0:
        return 1
 
    i = 0
    while i < len(b) and b[i] <= loc+r:
        i += 1
    i -= 1
 
    return 1 + get_lights(b[i+1:], b[i]+r, m, r)
 
 
for _ in range(int(input())):
    print('Case #{}:'.format(_+1), end=' ')
 
    m, r, n = map(int, input().split())
    a = list(map(int, input().split()))
 
    b = [0-r] + a + [m+r]
    ok = True
    for i in range(len(b)-1):
        if b[i+1]-b[i] > 2*r:
            ok = False
            break
 
    if not ok:
        print('IMPOSSIBLE')
        continue
 
    print(get_lights(a, 0, m, r))