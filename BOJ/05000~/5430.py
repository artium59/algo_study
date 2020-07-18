from collections import deque

def solution():
    front = True
    for a in p:
        if a == 'R':
            front = not front
        else:
            if len(x) > 0:
                if front:
                    x.popleft()
                else:
                    x.pop()
            else:
                print('error')
                return

    if not front:
        x.reverse()

    print('[', end='')
    for i in range(len(x)):
        print(x[i], end='')
        if i+1 != len(x):
            print(',', end='')
    print(']')

t = int(input())
for _ in range(t):
    p = input()
    n = int(input())
    x = input()[1:-1]

    if ',' in x:
        x = list(map(int, x.split(',')))
    else:
        if n > 0:
            x = [int(x)]
        else:
            x = []
    x = deque(x)
    solution()
