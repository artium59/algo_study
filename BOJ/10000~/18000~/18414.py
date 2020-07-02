x, l, r = [int(x) for x in input().split()]
ans = 10000000

for i in range(l, r+1):
    ans = i if abs(ans-x) > abs(i-x) else ans

print(ans)
