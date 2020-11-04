import csv

with open("/Users/joonyubkim/Downloads/data.tsv","r") as titles:
    reader = csv.DictReader(titles, delimiter = '\t')

    with open ("show0.csv", "w") as shows:
        writer = csv.writer(shows)
        writer.writerow(["tconst", "primaryTitle", "startYear", "genres"])

        for row in reader:
            if row["titleType"] == "tvSeries" and row["isAdult"] == "0":
                if row["startYear"] != "\\N" and int(row["startYear"]) >= 1970:
                    writer.writerow([row["tconst"], row["primaryTitle"], row["startYear"], row["genres"]])
