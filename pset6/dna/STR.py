from sys import argv
import csv

if not len(argv) == 4:
    print("Usage: python STR.py data.csv sequence.txt")

#load database
with open(argv[1], "r") as csv_file: #CSV파일 열기
    '''
    readline = csv.reader(csv_file)
    print(readline)
    for line in readline:
        print(line[2])
    '''
    readline = csv.reader(csv_file)
    first = next(readline)
    print(first)
    print(first[1:])
    STR = first[1:]
    for i in range(len(STR)):
        print(STR[i])

