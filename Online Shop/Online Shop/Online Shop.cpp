#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "ShopFiles.h"


#define FILE_NAME "shop.dat"


using namespace std;

int main()
{
    string usserName;
    string usserPassword;
    string inputPassword;
    string inputUsername;
    int logorsign;
    string userName;
    string userPassword;
    Item item{};
    int menuItem;
    string search;
    string itemDiscount;
    double walletnumber;
    double walletbalance;

    cout<<endl << "                                            **   Developed By Arshia Mostafaei  **"<< endl << endl;
    cout <<endl<< "                                       **********      SHOPING CENTER      **********" << endl ;
    cout << "_______________________________________________________________________________________________________________________";
    cout << endl << endl << endl;
    cout << "     1: Amin Panel" << endl<<endl;
    cout << "     2: Users Panel" << endl<<endl;
    cout << "     3: Products Search" << endl<<endl<<endl;
    cout << endl << "PLEASE SELECT AN OPTION: ";
    cin >> menuItem;
    cout << "________________________________________________________________________________________________________________________";


        switch (menuItem) {

             ///////////////             Admin               ////////////////

        case 1:
            cout << "Please enter your user name: ";
            cin >> userName;
            cout << "Please enter your user password: ";
            cin >> userPassword;
            if (userName == "Admin" && userPassword == "Admin@1234")
            {
                cout << "Welcome Admin !\n";

                Item item{};
                wallet wallet{};
                int menuItem;
                
                cout << endl << "                              **********      ONLINE SHOP  (Admin Panel)    **********" << endl;
                cout << "________________________________________________________________________________________________________________________";
                cout << "0: EXIT" << endl;
                cout << "1: ADD ITEM (+ DISCOUNTS)" << endl;
                cout << "2: DISPLAY ALL ITEMS" << endl;
                cout << "3: SEARCH ITEM " << endl;
                cout << "4: WALLETS" << endl;

                while (true) {
                    cout << endl << "PLEASE SELECT AN OPTION: ";
                    cin >> menuItem;
                    switch (menuItem) {

                    case 0:
                        return 0;

                    case 1:
                        cin.ignore();
                        writeToFile(item, FILE_NAME);
                        break;

                    case 2:
                        readFromFile(FILE_NAME);
                        break;

                    case 3:
                        cout << "\nSearch for item code: ";
                        cin >> search;
                        searchItemCode(search, FILE_NAME);
                        break;

                    case 4: 
                        int ShowEditwallet;
                        cout << endl << "1: EDIT OR CREATE WALLET ";
                        cout << endl << "2: SHOW WALLETS";
                        cin >> ShowEditwallet;
                        switch(ShowEditwallet){
                        case 1:
                            cin.ignore();
                            writeTowalletFile(wallet, FILE_NAME);
                            break;
                        case 2: 
                            readFromwalletFile(FILE_NAME);
                            break;
                        }
                    }
                }
            }
            else
            {
                cout << "Invalid Username or Password. Please try again !\n" << '\n';
            }

            break;



                ////////////////////Users Panel
        case 2:
            cout << endl << "                               **********      ONLINE SHOP  (User Panel)    **********" << endl;
            cout << "________________________________________________________________________________________________________________________";


            cout << "For Login Enter : 1" << endl;
            cout << "For Signin Enter : 2" << endl;
            cin >> logorsign;
            switch (logorsign)
            {
                ////////////////////    Login   ///////////////////////
            case 1:
                cout << endl << "                               **********      ONLINE SHOP  (User Panel)    **********" << endl;
                cout << "______________________________________________________________________________________________________________________";

                cout << "Please enter your user name: ";
                cin >> usserName;
                cout << endl;
                cout << "Please enter your user password: ";
                cin >> usserPassword;
                if (usserName == "User" && usserPassword == "User@1234")
                {
                    cout <<endl<< "Welcome User !\n";
                    
                    Item item{};
                    wallet wallet{};
                    int menuItem;
                    cout << endl << "                               **********      ONLINE SHOP  (User Panel)    **********" << endl;
                    cout << "_______________________________________________________________________________________________________________________";
                    cout << "0: EXIT" << endl;
                    cout << "1: ADD ITEM (Blocked for Users :) )" << endl;
                    cout << "2: DISPLAY ALL ITEMS" << endl;
                    cout << "3: SEARCH ITEM" << endl;
                    cout << "4: WALLET " << endl;
                    while (true) {
                        cout << endl << "PLEASE SELECT AN OPTION: ";
                        cin >> menuItem;
                        switch (menuItem) {
              
                        case 0:
                            return 0;
                        case 1:
                            cout << "This Part Is Blocked ";
                            break;
                        case 2:
                            readFromFile(FILE_NAME);
                            break;
                        case 3:
                            cout << "\nSearch for item code: ";
                            cin >> search;
                            searchItemCode(search, FILE_NAME);
                            break;
                        case 4 :
                            cin.ignore();
                            writeTowalletFile(wallet, FILE_NAME);
                            cout << endl;
                            readFromwalletFile(FILE_NAME);
                            break;
                        default:
                            cout << "ERROR" << endl;
                            return 0;
                        }
                    }
                }
                else
                {
                    cout << "Invalid Username or Password. Please try again !\n" << '\n';
                }
                break;


                ////////////////////    Signin   ///////////////////////
            case 2:

                cout << "*****************   Signin Page    *****************" << endl;
                cout << " Enter Your Username : ";
                cin >> userName;
                cout << endl;
                cout << " Enter Your Password : ";
                cin >> userPassword;
                inputUsername = userName;
                inputPassword = userPassword;

                cout << "Now You Are Signed In" << endl;
                cout << "You Can Login in Your Account ;) ";



                cout << "Please enter your user name: ";
                cin >> usserName;
                cout << "Please enter your user password: ";
                cin >> usserPassword;
                if (usserName == inputUsername && usserPassword == userPassword)
                {
                    cout << "Welcome User !";

                    Item item{};
                    int menuItem;
                    cout << "**********      ONLINE SHOP  (Users Panel)    **********" << endl;
                    cout << "0: EXIT" << endl;
                    cout << "1: ADD ITEM (Blocked for Users :) )" << endl;
                    cout << "2: DISPLAY ALL ITEMS" << endl;
                    cout << "3: SEARCH ITEM" << endl;
                    while (true) {
                        cout << endl << "PLEASE SELECT AN OPTION: ";
                        cin >> menuItem;
                        switch (menuItem) {
                        case 0:
                            return 0;
                        case 1:
                            cout << "This Part Is Blocked ";
                            break;
                        case 2:
                            readFromFile(FILE_NAME);
                            break;
                        case 3:
                            cout << "Search for item code: ";
                            cin >> search;
                            searchItemCode(search, FILE_NAME);
                            break;
                        default:
                            cout << "ERROR" << endl;
                            return 0;
                        }
                    }
                }
            }
            
            break;

            ///////////////////////////          Search         ///////////////////////////
        case 3:
            cout << "\nSearch for item code: ";
            cin >> search;
            searchItemCode(search, FILE_NAME);
            break;
        default:
            cout << "ERROR" << endl;
            return 0;
        }
    return 0;
}