#웹사이트 db 불러와서 원하는대로 가공해보기
'''
Error Message
    Traceback (most recent call last):
      File "IMDb.py", line 4, in <module>
        with open ("title.basics.tsv", "r") as titles:
    FileNotFoundError: [Errno 2] No such file or directory: 'title.basics.tsv'

어떻게 해야 올바르게 파일을 불러올 수 있을까?
/Users/joonyubkim/Downloads/data.tsv
data.tsv

다 아니다.. 뭘까 그럼??
'''


import csv

with open ("/Users/joonyubkim/Downloads/data.tsv", "r") as titles:
    reader = csv.DictReader(titles, delimiter = '\t')

    with open("shows0.csv", "w") as shows:
        writer = csv.writer(shows)
        writer.writerow(["tconst", "primaryTitle", "startYear", "genres"]) #불러온 파일의 index와는 상관 없이 자체적으로 만드는 index

        for row in reader:
            if row["titleType"] == "tvSeries" and row["isAdult"] == "0":
                if row["startYear"] != "\\N" and int(row["startYear"]) >= 1970:
                    writer.writerow([row["tconst"], row["primaryTitle"], row["startYear"], row["genres"]])
