#ifndef ADMIN
#define ADMIN

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdint.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "drink.h"
#include "dbif.h"
#include "log.h"
#include "server.h"
#include "guinf.h"
class Server;

using namespace std;
enum
{
    CHECKNAMEDRINK = 0,
    CHECKSTOCK = 1,
    GETINGREDIENTSNAME = 3,
    CREATEDRINK = 4,
    GETDRINKSNAME = 5,
    GETDRINK = 6,
    CHANGEDRINK = 7,
    DELETEDRINK = 8,
    CHECKNAMEINGREDIENT = 9,
    CHECKCONTAINER = 10,
    CREATEINGREDIENT = 11,
    GETINGREDIENTADDR = 12,
    CHANGEINGREDIENTADDR =13,
    DELETEINGREDIENT = 14,
    CLEAN = 15,
    GETERROR = 16,
    CLEAN_WATER = 17,
    GETTEMP = 18
};

class Admin
{
public:
    Admin(Controller*, DatabaseIF*);
    ~Admin();
    bool checkNameDrink(string namecheck);
    string* decode(string);
    map<string,string> checkStock();
    map<string,string> getTemp();
    void getIngredientsName(vector <string> & currentIngredients);
    bool createDrink(Drink newDrink);
    vector<string> getDrinksName();
    Drink getDrink(string name);
    bool changeDrink(Drink drinktoedit);
    bool deleteDrink(string todelte);
    bool checkNameIngredient(string name);
    bool checkContainer(int addr);
    bool createIngredient(string name, int addr);
    int getIngredientAddress(string ingredient);
    bool changeIngredientAddr(string name,int newAddr);
    bool deleteIngredient(string todelte);
    void clean();
    void clean_water();
    void parser(char*, int);
    string getErrorPT(int);

private:
    DatabaseIF* db;
    boost::mutex mtx;
    Controller* GUINF;
    Server* server;

};



#endif // ADMIN

