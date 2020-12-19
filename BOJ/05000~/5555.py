s, ans = input(), 0
n = int(input())

for _ in range(n):
    ring = input() * 2
    for i in range(10):
        if ring[i:i+len(s)] == s:
            ans += 1
            break
print(ans)
