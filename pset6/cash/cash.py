from cs50 import get_float

coins = 0
while True:
    change = get_float("Change owed: ")
    if change >= 0:

        coins += int(change / 0.25)
        change = round(change % 0.25, 2)

        coins += int(change / 0.10)
        change = round(change % 0.10, 2)

        coins += int(change / 0.05)
        change = round(change % 0.05, 2)

        coins += int(change / 0.01)

        print(f"{coins}")
        break