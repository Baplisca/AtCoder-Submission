import math
n = int(input())
lists = [int(input()) for i in range(5)]

print(math.ceil(n/min(lists)) + 4)