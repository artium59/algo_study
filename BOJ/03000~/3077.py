n, t, ans = int(input()), 0, {}
for i, s in enumerate(input().split()):
    ans[s] = i

student = input().split()

for i in range(len(student)):
    for j in range(i+1, len(student)):
        if ans[student[i]] < ans[student[j]]:
            t += 1

print('{}/{}'.format(t, n*(n-1)//2))
