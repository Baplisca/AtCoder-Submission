n = int(input())
bunshi = 1
bunbo = 1
for i in range(11):
    bunshi *= n - i - 1
for i in range(11):
    bunbo *= i+1
print(bunshi//bunbo)