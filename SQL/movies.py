import sqlite3 as sql #sqlite3라는 module import

#.connect라는 class / connect라는 method 안의 cursor라는 method
conn = sql.connect('/Users/joonyubkim/workspace/python/SQL/movies/movies.db')
c = conn.cursor()

c.execute("SELECT title FROM movies WHERE year = 2008")
#어떻게 하면 1.sql에다가 저장할 수 있을까?

conn.commit()

c.close()
conn.close()