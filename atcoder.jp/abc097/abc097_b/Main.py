n = int(input())
c = 1
for i in range(1,n):
    for j in range(2,n):
        if i**j <= n:
            c = max(c,i**j)
        else:
            break
print(c)