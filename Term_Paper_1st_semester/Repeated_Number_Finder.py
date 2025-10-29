N = int(input("Enter a number between 1 and 999: "))

seen_numbers = set()

while True:
    if N in seen_numbers:
        print(N)
        print("First repeated number:", N)
        break

    print(N, end=" → ")
    seen_numbers.add(N)
    digits = [int(d) for d in str(N)]
    N = sum(d * d for d in digits)
