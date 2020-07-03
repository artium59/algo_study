t = int(input())
for _ in range(t):
    g, c, e = map(int, input().split())
    print(max(0, (e-c)*(2*g-1)))
