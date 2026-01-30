x = 1.5
s = 0
for i in range(7):
    if i <= 3:
        continue
    s += i * x
print(s)
