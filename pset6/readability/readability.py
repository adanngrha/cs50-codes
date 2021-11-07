# import get_string from cs50 library
from cs50 import get_string

# prompt the user for text
text = get_string("Text: ")

# initialize the three variables
letters = 0
words = 0
sentences = 0

# iterate trough all of the character of the string
for a in range(0, len(text), 1):
    if text[a].isalnum() is True:
        letters += 1
    elif text[a] == " ":
        words += 1
    elif text[a] == "." or text[a] == "?" or text[a] == "!":
        sentences += 1
        
# some formula for the index/grade
L = float(letters) * 100 / (float(words) + 1)
S = float(sentences) * 100 / (float(words) + 1)
index = 0.0588 * L - 0.296 * S - 15.8
index = round(index)

# conditions 
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")