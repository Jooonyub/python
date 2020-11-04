'''
In a file called dna.py in ~/pset6/dna/, implement a program that identifies to whom a sequence of DNA belongs.

its first command-line argument _ the name of a CSV file
    containing the STR counts for a list of individuals
its second command-line argument _ the name of a text file
    containing the DNA sequence to identify.

If your program is executed with the incorrect number of command-line arguments, your program should print an error message of your choice (with print). If the correct number of arguments are provided, you may assume that the first argument is indeed the filename of a valid CSV file, and that the second argument is the filename of a valid text file.
Your program should open the CSV file and read its contents into memory.
You may assume that the first row of the CSV file will be the column names. The first column will be the word name and the remaining columns will be the STR sequences themselves.
Your program should open the DNA sequence and read its contents into memory.
For each of the STRs (from the first line of the CSV file), your program should compute the longest run of consecutive repeats of the STR in the DNA sequence to identify.
If the STR counts match exactly with any of the individuals in the CSV file, your program should print out the name of the matching individual.
You may assume that the STR counts will not match more than one individual.
If the STR counts do not match exactly with any of the individuals in the CSV file, your program should print "No match".
'''

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
    print(type(index))
    print(list(index))
    STRs = index[1:]
    ##### 이로써 STR이라는 list에 database로부터 각각의 염기서열을 저장함
#l = len(index)
#print (STRs)
s = []
#load sequences
with open(argv[2], "r") as csv_file: #python에서는 commandline 입력값의 첫 argument인 python이 카운트 되지 않기 때문에, 파일명인 ㅇㅇㅇ.py가 0번째 index가 된다!    #with as 구문으로 열면 맨 끝에 .close를 하지 않아도 된다!!(조건문처럼 :와 indetation이 적용됨)
    sequence = csv_file.read()
    print(sequence)
    #s = sequence 굳이 이렇게 s로 변환하지 않아도 처음부터 변환되어있음
#sequence로부터 load된 변수들
#print(sequence)


#count STR in sequence
txtSTRs = {}
for i in range(len(STRs)): # i는 각 STR을 가지고 sequence에 대조하기 위한 iteration
    max_count = 0
    j = 0
    continuity = 0
    while (j <= len(sequence)):
        #print(f"  비교들어갈 단어 : {sequence[j:j+len(STRs[i])]}, STR : {STRs[i]}")
        #print(STR[i])
        if (sequence[j:j+len(STRs[i])] == STRs[i]) and (j+len(STRs[i]) <= len(sequence)):
            print(f"\t{STRs[i]}")
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
print(f"\t{txtSTRs}")



with open(argv[1], "r") as csv_file:
    csv_dict = csv.DictReader(csv_file) # csv_dict _ <class 'csv.DictReader'>
    #print(type(csv_dict))       # >>> <class 'csv.DictReader'>
    #print(list(csv_dict))       # >>> [OrderedDict([('name', 'Alice'), ('AGATC', '2'), ('AATG', '8'), ('TATC', '3')]), OrderedDict([('name', 'Bob'), ('AGATC', '4'), ('AATG', '1'), ('TATC', '5')]), OrderedDict([('name', 'Charlie'), ('AGATC', '3'), ('AATG', '2'), ('TATC', '5')])]
    '''
    ## 한줄씩 OrderedDict가 잘 출력되는지를 확인하기 위한 for loop
    for personalSTR in csv_dict: #STRinfo _ <class 'collections.OrderedDict'>
        print(personalSTR)     # >>> OrderedDict([('name', 'Alice'), ('AGATC', '2'), ('AATG', '8'), ('TATC', '3')])
    '''
    '''
    for personalSTR in csv_dict:
        match = 0
        for i in range(1,len(personalSTR)):
            if personalSTR[i].value == txtSTRs[i-1].value:
            #if int(personalSTR[i].value) == int(txtSTRs[i-1].value):
                match += 1
        if match == len(STRs):
            print(personalSTR[0].value)
            exit()
    print("No match")
    '''
    for personalSTR in csv_dict:
        match = 0
        #print(personalSTR)
        for key in personalSTR:
            #del(personalSTR[0])
            if key == index[0]:
                pass
            elif int(personalSTR[key]) == int(txtSTRs[key]):
                print(f"personalSTR[key] : {personalSTR[key]} / txtSTRs[key] : {txtSTRs[key]}")
            #if personalSTR[STR].value == txtSTRs[STR].value:
            #if int(personalSTR[i].value) == int(txtSTRs[i-1].value):
                match += 1
                print(match)
        if match == len(STRs):
            print(personalSTR[index[0]])
            exit()
    print("No match")


    '''
    ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
    2020.10.02 일치하는것까지 다 확인했고, 이름출력만 제대로 하면 된다!!!!!!!!!!!!!!!!
    for personalSTR in csv_dict:
        match = 0
        print(personalSTR)
        for STR in STRs:
            print(f"personalSTR[STR] : {personalSTR[STR]} / txtSTRs[STR] : {txtSTRs[STR]}")
            if int(personalSTR[STR]) == int(txtSTRs[STR]):
            #if personalSTR[STR].value == txtSTRs[STR].value:
            #if int(personalSTR[i].value) == int(txtSTRs[i-1].value):
                print(match)
                match += 1
        if match == len(STRs):
            print(personalSTR[0])
            exit()
    print("No match")
    '''


'''
with open(argv[1], "r") as csv_file:
    csv_reader = csv.reader(csv_file)
    print(type(csv_reader), csv_reader)
    for personalSTR in csv_reader:
            for i in range(1,len(personalSTR)):
                if personalSTR[i] == txtSTR[STR[i]]:
                    print("concidence")
'''