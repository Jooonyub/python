# -*- coding: UTF-8 -*-
#2020.10.31(토) @스타벅스 잠실대교 남단 리저브

import sqlite3
from sys import argv, exit
import csv

'''
if (len(argv) != 3) :
    print("error")
    exit()
'''

#db = SQL("sqlite:///students.db")
#db.execute("Query 명령문 여기에 입력하")


#for i in range(argv):
print(argv[0])
print(argv[1])
#print(argv[2])


with open(argv[1], "r") as characters: #terminal에 입력하는 python argument는 아예 카운트에서 제외된다.
    reader = csv.DictReader(characters)
    for row in reader:
        #한줄씩 입력받는 값들을 여기서부터 구분하여서 받을 수 있다면?(firstname, middlename, last name)
        print(row)
