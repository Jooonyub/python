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
        #print(house) #이름 확인을 위한 출


if house == "Slytherin":
    db.execute("SELECT first, middle, last, birth FROM students WHERE house = 'Slytherin' ORDER BY last, first")
elif house == "Ravenclaw":
    db.execute("SELECT first, middle, last, birth FROM students WHERE house = 'Ravenclaw' ORDER BY last, first")
elif house == "Hufflepuff":
    db.execute("SELECT first, middle, last, birth FROM students WHERE house = 'Hufflepuff' ORDER BY last, first")
elif house == "Gryffindor":
    db.execute("SELECT first, middle, last, birth FROM students WHERE house = 'Gryffindor' ORDER BY last, first")

result = db.fetchall()

for row in result:
    birth = row[3]
    if row[1] == "NULL":
        #name = row[0] +' '+ row[2]
        first = row[0]
        last = row[2]
        print("{} {}, born {}".format(first, last, birth))
    else :
        #name = row[0] +' '+ row[1] +' '+ row[2]
        first = row[0]
        middle = row[1]
        last = row[2]
        print("{} {} {}, born {}".format(first, middle, last, birth))
    #print("{}, born {}".format(name, birth))

conn.commit()





