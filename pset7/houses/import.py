# -*- coding: UTF-8 -*-
#2020.10.31(토) @스타벅스 잠실대교 남단 리저브

import sqlite3
from sys import argv, exit
import csv


if (len(argv) != 2):
    print("error")
    exit()


#for i in range(argv):
print(argv[0])
print(argv[1])
#print(argv[2])

conn = sqlite3.connect("/Users/joonyubkim/workspace/python/pset7/houses/students.db")
db = conn.cursor()
#db = SQL("sqlite:///students.db")
#db.execute("Query 명령문 여기에 입력하")

db.execute("DROP TABLE students")
db.execute("CREATE TABLE students (id INT, first TEXT, middle TEXT, last TEXT, house TEXT, birth INT, PRIMARY KEY(id))")

with open(argv[1], "r") as characters: #terminal에 입력하는 python argument는 아예 카운트에서 제외된다.
    reader = csv.DictReader(characters)
    id = 0
    for row in reader:
        #한줄씩 입력받는 값들을 여기서부터 구분하여서 받을 수 있다면?(firstname, middlename, last name)
        id =+ 1
        print(row)
        house = row["house"]
        birth = int(row["birth"])
        name = row["name"]
        #이름을 단어별로 나눈다(공백에 따라 나누기)
        space_count = 0
        for i in name:
            i = name.split(' ')
            space_count =+ 1
        if space_count == 1 : #middle name이 없는 경
            first = name[0]
            middle = '\0'
            last = name[1]
        else :
            first = name[0]
            middle = name[1]
            last = name[2]

        #print(f"house is {house}, name is {name}, birth is {birth}.")
        #student = (id, first, middle, last, house, birth)
        #db.execute("INSERT INTO students(id, first, middle, last, house, birth) VALUES (?,?,?,?,?,?)", id, first, middle, last, house, birth)
    #print(f"INSERT INTO students _ id:{id}, first:{first}, middle:{middle}, last:{last}, house:{house}, birth:{birth}")
    print(id, first, middle, last, house, birth)
        #for key in row :
            #print(key
        #db.execute("Query 명령문 여기에 입력하")
    #db.commit()