transform = {'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14,
             'C': 1, 'D': 2, 'S': 3, 'H': 4}


def input_card():
    lst = []
    cards = input().split()
    for card in cards:
        s = 0
        for c in card:
            s = s * 10 + (transform.get(c) or int(c))
        lst.append(s)

    return sorted(lst)


n = int(input())
for _ in range(n):
    k = int(input())
    adam = input_card()
    eve = input_card()
    ans = 0

    for a in adam:
        for i in range(len(eve)):
            if a < eve[i]:
                ans += 1
                eve[i] = -1
                break
    print(ans)
