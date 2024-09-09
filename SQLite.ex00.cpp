#include <stdio.h>
// GPP means this file gets included, not separately commpiled
#include "sqlite3.h"
// #include "sqlite3.cpp"

#include <iostream>

/* the arguments in callback function 'callback' -- you may rename it to your liking--
   are the number of columns, their name and their value.
 * This function is supposed to be called on each row that is returned.
 * Function callback was originally defined static, which I have commented out.
 */
/* static */ int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for(i=0; i<argc; i++)
    std::cout << azColName[i] << (argv[i] ? argv[i] : "NULL");
  std::cout << '\n';
  return 0;
}


int main(int argc, char **argv){
  sqlite3 *db;
  char *zErrMsg = nullptr; // instead of " = 0;"
  int rc; // usage: rc = sqlite3_function()

  if( argc!=3 ) {
    // fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
    std::cerr << "Usage: " << argv[0] << " DATABASE SQL-STATEMENT\n";
    return 1;
  }

  rc = sqlite3_open(argv[1], &db);
  if(rc) {
    // fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    std::cerr << "Can't open database: " << sqlite3_errmsg(db) << '\n';
    sqlite3_close(db);
    return 1;
  }

  rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ){
    // fprintf(stderr, "SQL error: %s\n", zErrMsg);
    std::cerr << "SQL error: " << zErrMsg << '\n';
    sqlite3_free(zErrMsg);
  }

  sqlite3_close(db);
  return 0;
}
