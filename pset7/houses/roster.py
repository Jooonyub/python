
import sqlite3
from sys import argv, exit

if len(argv) != 2 :
    print("error")
    exit()

conn = sqlite3.connect("/Users/joonyubkim/workspace/python/pset7/houses/students.db")
db = conn.cursor()

find_house = argv[1]

query = f'SELECT first, middle, last, birth FROM students WHERE house = {argv[1]}'
db.execute(query)

result = fetchall()

for row in result :
    if row.middle == '\\N':
        fullname = f'{first} {last}'
    else:
        fullname = f'{first} {middle} {last}'
    sentence = f"{name}, born {birth} "
    print(sentence)
'''
fullname = first + middle + last
print()
'''
'''
for word in house :
    print(word)
'''

conn.commit()





