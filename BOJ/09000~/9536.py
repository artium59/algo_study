tc = int(input())
for _ in range(tc):
    lst = input().split()
    check = [True] * len(lst)

    while True:
        call = input().split()
        if len(call) == 5:
            break

        for i in range(len(lst)):
            if lst[i] == call[-1]:
                check[i] = False

    for i in range(len(lst)):
        if check[i]:
            print(lst[i], end=' ')
