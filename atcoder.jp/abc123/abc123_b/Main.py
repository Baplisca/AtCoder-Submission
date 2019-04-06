list = [int(input()) for i in range(5)]
kList = []
for j in range(0,10):
    for i in list:
         if (i+j) % 10 == 0:
            if len(kList) < 4:
                kList.append(i+j)
            else:
                kList.append(i)
print(sum(kList))