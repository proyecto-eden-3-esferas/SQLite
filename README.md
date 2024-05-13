# SQLite: A Full-Featured Embedded DataBase Engine

(To be hosted as a branch at https://github.com/proyecto-eden-3-esferas/SQLite/.)

SQLite is both:
- A DataBase Management System (DBMS), and
- A C library to be compiled and linked into executables (no dependencies on dynamic libraries) that go on to become specialized DBMS's.


# SQLite's Good Points

- SQLite distribution code is small, so it can be included in your application. (Below I explain that I just build an SQLite.o object file and link it in.)

- When you run it on the command line, it creates one database file in the current directory by default. This makes your databases absolutely carriable.

- It is written in standard C and used as C code.

- It runs on Linux, Windows MacOS... Yet this project is initially centred on Linux.


# Install(ed) Packages on Debian-Based Linux (`.deb` packages)

1. `sqlite3`
SQLite is a C library that implements an SQL database engine.
Programs that link with the SQLite library can have SQL database
access without running a separate RDBMS process.

2. `sqlite3-doc` (28MB of documentation)
- /usr/share/doc/sqlite3/index.html
- /usr/share/doc/sqlite3/c3ref/

3. `sqlite3-tools`
/usr/bin/showdb
/usr/bin/showjournal
/usr/bin/showstat4
/usr/bin/showwal
/usr/bin/sqldiff
/usr/bin/sqlite3_analyzer

This package contains various tools such as:
 - showdb
 - showjournal
 - showstat4
 - showwal
 - sqldiff
 - sqlite3_analyzer

9MB downloaded
33MB additional disk space

4. `libsqlite-dev`
- /usr/include/sqlite3.h
- /usr/include/sqlite3ext.h


# Procedures

Create a DB first:

```
  sqlite3   mydata.db
```

Actually, `man sqlite3` provides enough information.


# Compiling as C++ (GNU ToolChain)

Essentially, I create an object file (`sqlite3.o`) and link it into the executable. The main program just includes the header file (`sqlite3.o`).
So I build with a line like:

```
g++ -std=c++11 -o examplepp SQLite.ex00.cpp sqlite3.o
```
This builds an executable that already showcases many of the features of SQLite... it executes SQL code.


# Compiling as C++ (GNU ToolChain)

(Proceed analogously.)


# Projects

1. A zettelkasten application:
A table would hold the text of the notes. Other tables would handle links to other notes, with some explanation of the relationship between the source and the target note. Another table might hold relationships with their arity ("next", "previous", "is an example of", "contradicts", "relevant quote" and so on.).
At an advanced, further stage, I would like to deal with notes whose text excedes the alloted number of characters, typically through VARCHAR(NNN). This is a general SQL issue. It is inefficient to define a slot size capable of accomodating the largest imaginable piece of text.

2. An INSERT-generator:
Given a database, SQL code for inserting records or rows into a database is generated. The reverse, reading an SQL file and defing and populating a database would be fairly straightforward. (You may name it "SQL-interpreter".) It would be desirable for the code generated to be "pretty": indented consistently, without redundant space characters, and so on.

3. An Intelligent Agenda Manager
