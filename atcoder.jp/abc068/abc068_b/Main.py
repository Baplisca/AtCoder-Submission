n = int(input())
count = 0
for i in range(1,n+1):
    count1 = 0
    while i % 2 == 0 and i >= 2:
        count1 += 1
        i = i//2
    count = max(count,count1)
print(2**count)