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

from sys import argv
import csv

if not len(argv) == 3: # 만약 4일 경우 command line의 가장 처음 쓰게되는 'python'이라는 argument는 count되지 않으므로 주의하도록 한다!
    print("Usage: python dna.py data.csv sequence.txt")

#load database
with open(argv[1], "r") as csv_file: #python에서는 commandline 입력값의 첫 argument인 python이 카운트 되지 않기 때문에, 파일명인 ㅇㅇㅇ.py가 0번째 index가 된다!    #with as 구문으로 열면 맨 끝에 .close를 하지 않아도 된다!!(조건문처럼 :와 indetation이 적용됨)

    ## database에 있는 STR을 하나씩 읽어오기 ##
    csv_reader = csv.reader(csv_file)
    firstline = next(csv_reader)
    STR = firstline[1:]
    ''' #STR이라는 list에 알맞게 저장되었는지 확인하기
    for i in range(len(STR)):
        print(STR[i])
    '''
    ##### 이로써 STR이라는 list에 database로부터 각각의 염기서열을 저장함

s = []

#load sequences
with open(argv[2], "r") as csv_file: #python에서는 commandline 입력값의 첫 argument인 python이 카운트 되지 않기 때문에, 파일명인 ㅇㅇㅇ.py가 0번째 index가 된다!    #with as 구문으로 열면 맨 끝에 .close를 하지 않아도 된다!!(조건문처럼 :와 indetation이 적용됨)
    sequence = csv_file.read()
    print(sequence)
    s = sequence
    '''
    for i in range(len(sequence)):
        print(f"{s[i]}")
    '''

#count STR in sequence
txtSTR = {}
for i in range(len(STR)): # i는 각 STR을 가지고 sequence에 대조하기 위한 iteration
    count = 0
    j = 0
    while (j <= len(sequence)):
        #print(s[j:j+len(STR[i])])
        #print(STR[i])
        if (s[j:j+len(STR[i])] == STR[i]) and (j+len(STR[i]) <= len(sequence)):
            print(f"\t{STR[i]}")
            count += 1
            j += len(STR)+1
        else:
            j += 1
    txtSTR[STR[i]] = count


print(txtSTR)

'''
1.txt로 실행을 할 경우
AGATC   4회
AATG    1회
TATC    5회
'''
#compare with database
with open(argv[1], "r") as csv_file:
    csv_dict = csv.DictReader(csv_file)
    #next(csv_dict)
    for personal_STR in csv_dict:
        #print(personal_STR)

        #print(personal_STR[key(1):])
#Database에서 로드한 값의 첫번째 key-value 값을 제외한 뒤 각 줄을 루프로 돌려서 일치하는 사람이 있는지 대조해보면 됨!!
    '''
    for i in range(len(STR)):
        if int(personal_STR[i+1].value) == :#i번째의 STR값이 서로 같은지!!!
            '''

#Type of STRs _ AGATC,TTTTTTCT,AATG,TCTAG,GATA,TATC,GAAA,TCTG
#이 STR에 대해 직접적인 입력으로 비교하기보다, database의 index를 활용하여 일치하는지 여부를 비교하는 방식으로 접근
    #database의 첫줄만 뽑아서 1번째 index부터 저장하면 될텐데?

#file = open(argv[2], "r")

# key로 name을, value로 염기서열 반복횟수를 각각 매치(첫열은 어떻게 처리하지?)
# 사람 이름에 대하여 list를 만들고, 각  리스트에 대해 dict?? 흠...

#names = []