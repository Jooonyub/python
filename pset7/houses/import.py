# -*- coding: UTF-8 -*-
import sqlite3
from sys import argv, exit
import csv


if (len(argv) != 2):
    print("error")
    exit()


#for i in range(argv):
#print(argv[0])
#print(argv[1])
#print(argv[2])  #Linux command에 처음 입력하는 python이라는 단어는 argument로 인식되지 않는다.

conn = sqlite3.connect("/Users/joonyubkim/workspace/python/pset7/houses/students.db")
db = conn.cursor()
'''
아래의 두 줄은 cs50.ide에서나 쓸 수 있는 application method같다.
#db = SQL("sqlite:///students.db")
#db.execute("Query 명령문 여기에 입력하")
'''

#delete preseted TABLE 'students', and create it newly
db.execute("DROP TABLE students")
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth INT)")

with open(argv[1], "r") as characters: #terminal에 입력하는 python argument는 아예 카운트에서 제외된다.
    reader = csv.DictReader(characters)
    #id = 0
    for row in reader:
        #한줄씩 입력받는 값들을 여기서부터 구분하여서 받을 수 있다면?(firstname, middlename, last name)
        #id =+ 1
        #print(row)
        house = str(row["house"])
        birth = int(row["birth"])
        name = str(row["name"])
        #이름을 단어별로 나눈다(공백에 따라 나누기)
        #space_count = 0
        name_split = name.split(' ')
        if len(name_split) == 2 :
            for i in name_split :
                first = name_split[0]
                middle = "NULL"
                last = name_split[1]
        else :
            first = name_split[0]
            middle = name_split[1]
            last = name_split[2]

        #print(f"house is {house}, name is {name}, birth is {birth}.")
        #student = (id, first, middle, last, house, birth)
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)",
                   (first, middle, last, house, birth))
    conn.commit()
        #print(f"INSERT INTO students _ id:{id}, first:{first}, middle:{middle}, last:{last}, house:{house}, birth:{birth}")
        #print(first, middle, last, house, birth)
        #for key in row :
            #print(key
        #db.execute("Query 명령문 여기에 입력하")
    #db.commit()