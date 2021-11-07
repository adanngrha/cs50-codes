# import get_float function from cs50 library
from cs50 import get_float

# reprompting the user
while True:
    dollars = get_float("Change owed: ")
    if dollars > 0.00:
        break

# convert dollars to cents
cents = round(dollars * 100)
coins = 0

while cents >= 25:
    cents = cents - 25
    coins += 1

while cents >= 10:
    cents = cents - 10
    coins += 1

while cents >= 5:
    cents = cents - 5
    coins += 1

while cents >= 1:
    cents = cents - 1
    coins += 1

# print sum of the coins
print(coins)