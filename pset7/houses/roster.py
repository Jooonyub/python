
import sqlite3
from sys import argv, exit

if len(argv) != 2 :
    print("error")
    exit()

conn = sqlite3.connect("/Users/joonyubkim/workspace/python/pset7/houses/students.db")
db = conn.cursor()

find_house = argv[1]

house = db.execute("""
SELECT DISTINCT house FROM students
""")

'''
for word in house :
    print(word)
'''

conn.commit()





