# since g++ does not compile sqlite3.c, make a module 'sqlite3.o'
# and apply separate compilation, as shown for goal 'examplepp'

sqlite3.o: sqlite3.c
	gcc -c sqlite3.o sqlite3.c

example: SQLite.ex00.cpp
	gcc SQLite.ex00.c sqlite3.c

*pp: *.cpp *.h sqlite3.o
	c++    -std=c++23 $< sqlite3.o -o $@

examplepp: SQLite.ex00.cpp sqlite3.o
	# g++ -std=c++11 -Wno-literal-suffix -o examplepp SQLite.ex00.cpp sqlite3.o
	g++ -std=c++11                     -o examplepp SQLite.ex00.cpp sqlite3.o

sqlite3: shell.c sqlite3.c sqlite3.h
	gcc -DSQLITE_THREADSAFE=0 shell.c sqlite3.c -ldl -lm -o sqlite3

clean:
	$(RM) sqlite3 example examplepp a.out
clean_all:
	$(RM) sqlite3 example examplepp a.out *.o
