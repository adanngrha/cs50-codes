from cs50 import get_int

# reprompt the user for positive int
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for i in range(height):
    # print spaces
    for j in range(height - 1, i, -1):
        print(" ", end="")
    # print hastags
    for k in range(0, i + 1, 1):
        print("#", end="")
    # print a new line
    print()