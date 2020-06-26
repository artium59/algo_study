MOD = 1e9+7
n, k = map(int, input().split())
lst, check = [0] * (50*1500+1), {}
cnt, ans = 0, 0

for i in range(n):
    aa = input().split()

    for big in aa:
        if big not in check:
            check[big] = cnt
            cnt += 1

        if i == 0:
            lst[check[big]] += 1
            continue

        for small in [big[1:], big[:-1]]:
            if small in check:
                lst[check[big]] = (lst[check[big]] + lst[check[small]]) % MOD
            if big[1:] == big[:-1]:
                break

    if i == n-1:
        for big in aa:
            if check[big] == -1:
                continue

            ans = (ans + lst[check[big]]) % MOD
            check[big] = -1

print(int(ans))
