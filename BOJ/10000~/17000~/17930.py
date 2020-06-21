l, x = map(int, input().split())
cur, ans = 0, 0

for _ in range(x):
    e, i = input().split()
    i = int(i)
    if e == 'enter':
        if cur+i <= l:
            cur += i
        else:
            ans += 1
    elif e == 'leave':
        cur -= i

print(ans)
