#include "sqlite3.h"
#include <sstream>
#include <iostream>
int sqltest()
{
  sqlite3 *db;
  //char *errMsg = 0;
  //int rc;

  // Open a database connection
  sqlite3_open("example.db", &db);

  // Create a table
  const char *sqlCreateTable = "CREATE TABLE IF NOT EXISTS company("
                               "id INT PRIMARY KEY     NOT NULL,"
                               "name           TEXT    NOT NULL,"
                               "age            INT     NOT NULL,"
                               "address        CHAR(50),"
                               "salary         REAL );";
  sqlite3_exec(db, sqlCreateTable, 0, 0, 0);

  sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, 0);
  std::ostringstream oStringStream;
  for (int i = 1; i <= 1000; ++i)
  {
    oStringStream << "INSERT OR IGNORE INTO company (id, name, age, address, salary) "
                    << "VALUES (" << i << ", 'Name" << i << "', " << (20 + i % 50) << ", 'Address" << i << "', " << (30000 + i * 100) << "); ";
  }
  std::cout << oStringStream.str() << "\n";
  std::string sqlInsert = oStringStream.str(); //.str() is from sstream
  sqlite3_exec(db, sqlInsert.c_str(), 0, 0, 0);
  sqlite3_exec(db, "COMMIT;", 0, 0, 0);
  sqlite3_close(db);
  return 0;
}
// TODO:
// (1) Grabbing values from the database
// (2) delete values from the database
// (3) modify values from database

int main ()
{
  std::cout << "Program Ran Successfully!\n";
  return 0;
}
