#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define FILE_NAME "shop.dat"

using namespace std;

class Item {
private:
    char itemCode[20], itemName[20], discountCode[20];
    double itemDiscount;
    double itemPrice;
public:
    void readItem() {
        cout << endl << "INPUT ITEM DETAILS" << endl;
        cout << "ITEM CODE: ";
        cin.getline(itemCode, 20);
        cout << "ITEM NAME (just use char variables !): ";
        cin.getline(itemName, 20);
        cout << "ITEM PRICE: ";
        cin >> itemPrice;
        cout << "DISCOUNT CODE (just use char variables !):";
        cin>> discountCode;
        cout << "DISCOUNT: ";
        cin >> itemDiscount;
    }
    void displayItem() {
       cout << left << setw(15) << itemCode
            << left << setw(15) << itemName
            << left << setw(15) << setprecision(4)<<  itemPrice
            << left <<setw(15) << discountCode
            << left << setw(15)<< itemDiscount << endl;
    }
    char* getItemCode() { return itemCode; }
};

int writeToFile(Item item, string filename) {
    item.readItem();
    fstream file;
    /// write to file
    file.open(filename, ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Error writing file" << endl;
        return -1;
    }
    file.write((char*)&item, sizeof(item));
    file.close();
    cout << "SAVED..." << endl;
    return 0;
}

int readFromFile(string filename) {
    Item item;
    fstream file;
    file.open(filename, ios::in | ios::binary);
    if (!file) {
        cout << "Error opening file" << endl;
        return -1;
    }
    if (file.read((char*)&item, sizeof(item))) {
        cout << endl
            << left << setw(15) << "ITEM CODE"
            << left << setw(15) << "ITEM NAME"
            << left << setw(15) << "ITEM PRICE"
            << left << setw(15) << "DISCOUNT CODE"
            << left << setw(15) << "DISCOUNT" << endl;
        while (!file.eof()) {
            item.displayItem();
            file.read((char*)&item, sizeof(item));
        }
    }
    else {
        cout << "Error reading from file" << endl;
        return -1;
    }
    file.close();
    return 0;
}

int searchItemCode(string search, string filename) {
    Item item;
    ifstream file;
    file.open(filename, ios::in);
    if (!file) {
        cout << "Error opening file" << endl;
        return -1;
    }
    if (file.read((char*)&item, sizeof(item))) {
        while (!file.eof()) {
            if (item.getItemCode() == search) {
                cout << endl
                    << left << setw(15) << "ITEM CODE"
                    << left << setw(15) << "ITEM NAME"
                    << left << setw(15) << "ITEM PRICE"
                    << left << setw(15) << "DISCOUNT CODE"
                    << left << setw(15) << "DISCOUNT" << endl;
                item.displayItem();
                break;
            }
            file.read((char*)&item, sizeof(item));
        }
    }
    else {
        cout << "Error reading from file" << endl;
        return -1;
    }
    file.close();
    cout << endl;
    return 0;
}

// // // // // // // //      Wallet Class

class wallet {
private:
    char walletCode[20];
    double walletBalance;
public:
    void readwalletItem() {
        cout << endl << "INPUT ITEM DETAILS" << endl;
        cout << "WALLET Code (just use char variables !) : ";
        cin.getline(walletCode, 20);
        cout <<endl<< "WALLET BALANCE : ";
        cin >> walletBalance;
    }
    void displaywalletItem() {
        cout << left << setw(15) << walletCode
            << left << setw(15) << walletBalance << endl;
    }
    char* getwalletItemCode() { return walletCode; }
};

int writeTowalletFile(wallet wallet, string filename) {
    wallet.readwalletItem();
    fstream file;
    /// write to file
    file.open(filename, ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Error writing file" << endl;
        return -1;
    }
    file.write((char*)&wallet, sizeof(wallet));
    file.close();
    cout << "SAVED..." << endl;
    return 0;
}

int readFromwalletFile(string filename) {
    wallet wallet;
    fstream file;
    file.open(filename, ios::in | ios::binary);
    if (!file) {
        cout << "Error opening file" << endl;
        return -1;
    }
    if (file.read((char*)&wallet, sizeof(wallet))) {
        cout << endl
            << left << setw(15) << "WALLET CODE : "
            << left << setw(15) << "WALLET BALANCE : " << endl;
        while (!file.eof()) {
            wallet.displaywalletItem();
            file.read((char*)&wallet, sizeof(wallet));
        }
    }
    else {
        cout << "Error reading from file" << endl;
        return -1;
    }
    file.close();
    return 0;
}