#ifndef DBIF
#define DBIF
//#include <QtCore/QCoreApplication>
//#include <QtSql>
//#include <QtDebug>
//#include <QFileInfo>
#include <sqlite3.h>
#include <vector>
#include "src/drink.h"
#include "src/log.h"
#include <iostream>
#include <sstream>
#include <pthread.h>
#include <boost/thread.hpp>
#include <sstream>

#define DRINK 98
#define INGREDIENT 99

using namespace std;

enum errors
{
  NO_ERRORS=0,
  DB_FAILED_TO_OPEN=1,
  DB_QUERY_FAIL=2,
  DB_INGREDIENS_NOT_FOUND=3,
  UNDEFINED_PARAMETER=4,
  DB_ENTRY_ALREADY_EXIST=5,
  DB_DRINK_NOT_FOUND=6,
  DB_INGREDIENS_IN_USE=7
};


class DatabaseIF
{
public:
    DatabaseIF();
    ~DatabaseIF();
    int getLastError();
    vector<vector<string> > query(string query);
    int getDrinksName(vector<string> &);
    int getAddress(string, vector <int> &);
    bool checkName(int, string);
    int getIngredientsName(vector <string>&);
    int createDrink(Drink &);
	int addImage(string toAdd);
    int getDrink(string, Drink &);
    bool checkForUse(string);
    bool checkContainerInUse(int);
    int changeDrink(Drink &);
    int remove(string, int);
    int createIngredient(string, int);
    int getIngAdress(string, int &);
    int changeIngrediensAddr(string, int);
    int saveOrder(string);


private:
    //QSqlDatabase db;
    sqlite3 *db;
    Logger log;
    boost::mutex mtx;
    int lastError;
};

#endif // DBIF

