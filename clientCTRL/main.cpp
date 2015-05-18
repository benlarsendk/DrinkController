#include "src/adminclient.h"
#include "src/guinf.h"

int main()
{
    cout << "****FAKE AD GUI****" << endl << endl;

    cout << "[*] Creating Controller and AC" << endl;
    Controller me;
    AdminClient AC(&me);


    cout << "[*] Requesting drinks list" << endl;

   vector<string> test = AC.getDrinksName();

   for (vector<string>::iterator iter = test.begin(); iter != test.end(); iter++){

       cout << *iter << endl;
   }


   cout << endl << "[*] Requesting Ingredients list" << endl;

   vector<string> ings;
   AC.getIngredientsName(ings);

   for (vector<string>::iterator iter = ings.begin(); iter != ings.end(); iter++){

       cout << *iter << endl;
   }


   cout << endl << "[*] Creating a drink [Kaffe | Kaffepulver | 25 | vand | 30 | LOL/PATH]" << endl;

   Drink kaffe;
   kaffe.name =" Kaffe";
   kaffe.content[0].name="Kaffepulver";
   kaffe.content[0].amount=25;
   kaffe.content[1].name="Vand";
   kaffe.content[1].amount=30;
   kaffe.path="LOL/PATH";

   AC.createDrink(kaffe);


   cout << "[*] Seeing if it worked..." << endl;

   vector<string> test2 = AC.getDrinksName();
   for (vector<string>::iterator iter = test2.begin(); iter != test2.end(); iter++){

       cout << *iter << endl;
   }

   if(AC.deleteDrink("Kaffe")){
       cout << "\n[*]Kaffe should be gone" << endl;
       vector<string> test3 = AC.getDrinksName();
       for (vector<string>::iterator iter = test3.begin(); iter != test3.end(); iter++){

           cout << *iter << endl;
       }
   }
   else cout << "[-] ERROR...." << endl;


   cout << "\n [*]Seeing if Rom exist (1) and Tea (2)" << endl;

   if (AC.checkNameDrink("Rom"))
       cout << "[+] Rom exist!" << endl;
   else
       cout << "[-] Rom doesnt exist...?" << endl;

   if (AC.checkNameDrink("Tea")){
       cout << "[-] Tea exist?!" << endl;
   }
   else cout << "[+] Tea doesnt exist." << endl;











}
