c, a = 0, 0
music = input().split('|')
for m in music:
    if m[0] in ['C', 'F', 'G']:
        c += 1
    elif m[0] in ['A', 'D', 'E']:
        a += 1

if c > a:
    print('C-major')
elif c < a:
    print('A-minor')
else:
    if music[-1][-1] in ['C', 'F', 'G']:
        print('C-major')
    elif music[-1][-1] in ['A', 'D', 'E']:
        print('A-minor')
