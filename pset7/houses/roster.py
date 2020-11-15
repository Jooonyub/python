# -*- coding: UTF-8 -*-
import sqlite3
from sys import argv, exit

if len(argv) != 2 :
    print("error")
    exit()

conn = sqlite3.connect("/Users/joonyubkim/workspace/python/pset7/houses/students.db")
db = conn.cursor()

find_house = argv[1]
db.execute("select DISTINCT house FROM students")
houses = db.fetchall()
#print(result)
for house_name in houses:
    #house_name의 종류가 몇가지 있고, 그중에 argv[1]과 일치하는 house가 있는지 찾아보는 루
    if argv[1] in house_name :
        house = argv[1]
        #print(house) #이름 확인을 위한 출력


if house == "Slytherin":
    db.execute("SELECT first, middle, last, birth FROM students WHERE house = 'Slytherin'")
elif house == "Ravenclaw":
    db.execute("SELECT first, middle, last, birth FROM students WHERE house = 'Ravenclaw'")
elif house == "Hufflepuff":
    db.execute("SELECT first, middle, last, birth FROM students WHERE house = 'Hufflepuff'")
elif house == "Gryffindor":
    db.execute("SELECT first, middle, last, birth FROM students WHERE house = 'Gryffindor'")

result = db.fetchall()

for row in result:
    if row[1] == '\\N':
        name = row[0] +''+ row[2]
    else :
        name = row[0] +''+ row[1] +''+ row[2]
    print(name)

    '''
    if row.middle == '\\\N':
        print(first)
        print(last)
        #fullname = first + last
    else:
        print(first)
        print(middle)
        print(last)
        #fullname = f"{'first'} {'middle'} {'last'}"
    '''
    #sentence = f"{'name'}, born {'birth'}"
    #print(sentence)

'''
query = f"SELECT first, middle, last, birth FROM students WHERE house = {'argv[1]'}"
db.execute(query,find_house)

result = db.fetchall()

for row in result:
    if row.middle == '\\N':
        print(first)
        print(last)
        #fullname = first + last
    else:
        print(first)
        print(middle)
        print(last)
        #fullname = f"{'first'} {'middle'} {'last'}"
    #sentence = f"{'name'}, born {'birth'}"
    #print(sentence)
'''
'''
fullname = first + middle + last
print()
'''
'''
for word in house :
    print(word)
'''

conn.commit()





