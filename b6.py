import sqlite3
con = sqlite3.connect("users.db"); cur = con.cursor()
cur.execute("CREATE TABLE IF NOT EXISTS users (id INT, name TEXT, age INT)")
cur.execute("INSERT INTO users VALUES (1, 'Alice', 22)")
con.commit()
for r in cur.execute("SELECT * FROM users"): print(r)
