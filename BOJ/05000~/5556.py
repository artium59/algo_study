n = int(input())
k = int(input())

for _ in range(k):
    a, b = map(int, input().split())
    m = min(a, b, n-a+1, n-b+1) % 3
    print(m if m != 0 else 3)
