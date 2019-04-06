list = [int(input()) for i in range(5)]
k = int(input())
n=False

for i in range(5):
    for j in range(5):
        if(abs(list[i] - list[j]) > k):
            print(":(")
            n=True
            break
    if n:
        break

if not n:
    print("Yay!")
