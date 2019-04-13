a,b = map(int,input().split())
c,d = (a-1,b-1)
lists = [a,b,c,d]
lists.sort(reverse=True)
print(sum(lists[0:2]))