#ifndef ADMIN
#define ADMIN

#include <iostream>
#include <string>
#include "src/dbif.h"
#include <vector>
#include <map>
#include "src/drink.h"
#include "src/log.h"
//#include "controller.h"

using namespace std;

class Admin
{
public:
    Admin();
    Admin(Controller*);
    bool checkNameDrink(string namecheck);
    void orderDrinks(vector<string> drinks);
    map<string,string> checkStock();
    void getIngredientsName(vector <string> & currentIngredients);
    bool createDrink(Drink newDrink);
    void getDrinksName();
    void getDrink(string name);
    void changeDrink(Drink drinktoedit);
    void deleteDrink(string todelte);
    bool checkNameIngredient(string name);
    bool checkContainer(int addr);
    void createIngredient(string name, int addr);
    void getIngredientAddress(string ingredient);
    void changeIngredientAddr(string name,int newAddr);
    void deleteIngredient(string todelte);
	void clean();
//	void addImage(string toImage);
    string getErrorPT(int);

private:
    DatabaseIF db;
    Logger log;
    Controller *GUINF;

};



#endif // ADMIN
