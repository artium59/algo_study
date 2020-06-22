n = int(input())
arr = [int(i) for i in input().split()]
ans = []
l = -1e9

for a in arr:
    if l < a:
        ans.append(a)
        l = a

print(len(ans))
for a in ans:
    print(a, end=' ')
