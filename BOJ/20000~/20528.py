n = int(input())
lst = input().split()

for l in lst:
    if l[-1] != lst[0][0]:
        print(0)
        exit(0)
print(1)
