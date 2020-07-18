from collections import deque

def bfs():
    ret, q = 1e9, deque()
    yrr, xrr = [-1, 1, 0, 0], [0, 0, -1, 1]

    q.append((0, 0, 0))
    while q:
        y, x, time = q.popleft()

        if castle[y][x] == 2 and time + n+m-y-x-2 <= t:
            ret = min(ret, time + n+m-y-x-2)

        if y == n-1 and x == m-1:
            ret = min(ret, time)
            continue

        for yi, xi in zip(yrr, xrr):
            dy, dx = y + yi, x + xi

            if 0<=dy<n and 0<=dx<m:
                if castle[dy][dx] == 1 or time+1 > t:
                    continue
                if castle[dy][dx] == 0:
                    castle[dy][dx] = 1
                q.append((dy, dx, time+1))

    return ret

n, m, t = map(int, input().split())
castle = []
for _ in range(n):
    lst = list(map(int, input().split()))
    castle.append(lst)

t = bfs()
if t == 1e9:
    print('Fail')
else:
    print(t)
