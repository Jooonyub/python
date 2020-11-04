#CS50 2020 _ pset6 _ dna _ 2020.10.03

from sys import argv, exit
import csv
from collections import OrderedDict

if not len(argv) == 3: # 만약 4일 경우 command line의 가장 처음 쓰게되는 'python'이라는 argument는 count되지 않으므로 주의하도록 한다!
    print("Usage: python dna.py data.csv sequence.txt")
STRs = []
index = []

#load database
with open(argv[1], "r") as csv_file: #python에서는 commandline 입력값의 첫 argument인 python이 카운트 되지 않기 때문에, 파일명인 ㅇㅇㅇ.py가 0번째 index가 된다!    #with as 구문으로 열면 맨 끝에 .close를 하지 않아도 된다!!(조건문처럼 :와 indetation이 적용됨)
### 여기서 첫줄 next(csv_reader)로 firstline을 불러들임. 그렇다면 그 후로 나머지 csv_reader를 가지고 for loop를 만든다면? 사람과 각 염기서열에 관한 정보만 가져올 수 있지 않을까?
    csv_reader = csv.reader(csv_file)
    index = next(csv_reader)
    STRs = index[1:]
    ##### 이로써 STR이라는 list에 database로부터 각각의 염기서열을 저장함

s = []
#load sequences
with open(argv[2], "r") as csv_file: #python에서는 commandline 입력값의 첫 argument인 python이 카운트 되지 않기 때문에, 파일명인 ㅇㅇㅇ.py가 0번째 index가 된다!    #with as 구문으로 열면 맨 끝에 .close를 하지 않아도 된다!!(조건문처럼 :와 indetation이 적용됨)
    sequence = csv_file.read()
    #print(sequence)
#sequence로부터 load된 변수들
#print(sequence)

#count STR in sequence
txtSTRs = {}
for i in range(len(STRs)): # i는 각 STR을 가지고 sequence에 대조하기 위한 iteration
    max_count = 0
    j = 0
    continuity = 0
    while (j <= len(sequence)):
        if (sequence[j:j+len(STRs[i])] == STRs[i]) and (j+len(STRs[i]) <= len(sequence)):
            #print(f"\t{STRs[i]}")
            if continuity == 0:
                count = 1
            elif continuity == 1:
                count += 1
            continuity = 1
            j += len(STRs[i])
        else:
            if continuity == 0:
                count = 0
            elif continuity == 1:
                if max_count <= count:
                    max_count = count
                count = 0
            continuity = 0
            j += 1
    txtSTRs[STRs[i]] = max_count
#print(f"\t{txtSTRs}")

with open(argv[1], "r") as csv_file:
    csv_dict = csv.DictReader(csv_file) # csv_dict _ <class 'csv.DictReader'>
    for personalSTR in csv_dict:
        match = 0
        #print(personalSTR)
        for key in personalSTR:
            #del(personalSTR[0])
            if key == index[0]:
                pass
            elif int(personalSTR[key]) == int(txtSTRs[key]):
                match += 1
                #print(match)
        if match == len(STRs):
            print(personalSTR[index[0]])
            exit()
    print("No match")
