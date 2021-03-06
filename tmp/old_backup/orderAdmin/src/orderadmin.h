#ifndef ORDERADMIN_H
#define ORDERADMIN_H
#include <iostream>
#include <string>
#include "dbif.h"
#include <vector>
#include <map>
#include "drink.h"
#include "log.h"
#include <queue>
#include <boost/thread.hpp>
#include "guinf.h"

using namespace std;

class orderAdmin
{
public:
    orderAdmin(Controller*);
    ~orderAdmin();

    void getDrinksName();
    void orderDrinks(vector<string> drinks);
    map<string,string> checkStock();
    string getErrorPT(int);

private:
    Controller* GUINF;
    queue<vector<string> > orders; // New
    pthread_mutex_t mtx;
    pthread_cond_t bell;
    void handleOrder();
    boost::thread* worker;
    DatabaseIF db;
    Logger log;
};

#endif // ORDERADMIN_H
