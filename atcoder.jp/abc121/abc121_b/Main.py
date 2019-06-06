n,m,c = map(int,input().split())
b = list(map(int,input().split()))
count = 0
for i in range(n):
    a = list(map(int,input().split()))
    p = c
    for j in range(m):
        p += a[j]*b[j]
    if p > 0:
        count += 1
print(count)