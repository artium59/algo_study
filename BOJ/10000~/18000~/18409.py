a = int(input())
str = input()
ans=0

for s in "aeiou":
    ans += str.count(s)

print(ans)
