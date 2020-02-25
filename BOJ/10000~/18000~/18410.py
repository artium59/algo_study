n, m = map(int, input().split())
arr = [int(a) for a in input().split()]
brr = [int(a) for a in input().split()]

n = m = 0

while n < len(arr) and m < len(brr):
    if arr[n] < brr[m]:
        print(arr[n])
        n += 1
    else:
        print(brr[m])
        m += 1

while n < len(arr):
    print(arr[n])
    n += 1

while m < len(brr):
    print(brr[m])
    m += 1
