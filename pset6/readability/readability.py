from cs50 import get_string

text = get_string("Text : ")

# letter, word, sentence 각각 count해야.(2020.09.24 @투썸플레이스 광화문)

letter = word = sentence = 0

for i in range(len(text)):
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letter += 1
    elif text[i] == ' ':
        word += 1
    elif text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentence += 1
word += 1


#print (f"letter : {letter}, word : {word}, sentence : {sentence}\n")

L = (letter / word) * 100
S = (sentence / word) * 100

grade = (0.0588 * L - 0.296 * S - 15.8)
print(f"grade : {grade}\n")
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade : {round(grade)}")


#L : the average number of letters per 100 words in the text
#S : the average number of sentences per 100 words in the text