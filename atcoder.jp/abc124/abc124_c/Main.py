s = input()
lists = []
for i in s:
    lists.append(i)

preword = lists[0]
count = 0
for i in range(1,len(lists)):
    if lists[i] == preword:
        count += 1
        if lists[i] == "0":
            preword = "1"
        else:
            preword = "0"
    else:
        preword = lists[i]

print(count)