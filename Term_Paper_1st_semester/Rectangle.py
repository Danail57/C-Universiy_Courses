import matplotlib.pyplot as plt
import matplotlib.patches as patches

while True:
    try:
        x = float(input('Enter a number for x: '))
        y = float(input('Enter a number for y: '))
        A = float(input('Enter a number for A (>0): '))
        B = float(input('Enter a number for B (<0): '))

        if A <= 0:
            print("A must be greater than 0!")
            continue
        if B >= 0:
            print("B must be less than 0!")
            continue

        if x == 0 or x == A or y == 0 or y == B:
            print("The point is on the rectangle")
            color = 'green'
        else:
            print("The point is not on the rectangle")
            color = 'red'

        break

    except ValueError:
        print("Invalid input! Please enter numbers only.")

fig, ax = plt.subplots()
rect = patches.Rectangle((0, B), A, -B, linewidth=2, edgecolor='blue', facecolor='none')
ax.add_patch(rect)

plt.scatter(x, y, color=color, s=100, label='Point')

plt.axhline(0, color='black', linewidth=0.8)
plt.axvline(0, color='black', linewidth=0.8)
plt.grid(True)

plt.legend()
plt.title("Point relative to rectangle")

plt.xlabel("X")
plt.ylabel("Y")

plt.show()
