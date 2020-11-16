from cs50 import get_string
#text = input("Text : ")
text = get_string("Text : ")
letter = word = sentence = 0

print(f"length is {len(text)}\n")

for i in range(len(text)) :
#    if (int(text[i]) >= 65 and int(text[i]) <= 90) or (int(text[i]) >= 97 and int(text[i]) <= 122):
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letter += 1
    elif text[i] == ' ':
        word += 1
    elif text[i] == '.':
        word += 1
        sentence += 1

print (f"letter : {letter}, word : {word}, sentence : {sentence}\n")