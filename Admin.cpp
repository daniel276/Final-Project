//
// Created by Daniel on 10/25/2016.
// this cpp for writing user data
#include <iostream>
#include <fstream>
#include <random>
#include "accountData.h"
using namespace std;
void login_Page();
void disp();
void admin_Page();
void add_Account();
int generateID();
int main(){
    cout << generateID();
    login_Page();
    disp();

    return 0;
}



bool validate_Login(string username, string password) {
    if(username=="admin" && password=="lol"){
        return true;
    }
    else
    {
        return false;
    }
}



void login_Page() {
    bool loginValidation;
    accountData admin;
    cout << "-----------------------------------" << endl;
    cout << "        BANK CENTRAL AFRICA        " << endl;
    cout << "           ADMINISTRATOR           " << endl;
    cout << "               LOGIN               " << endl;
    cout << "-----------------------------------" << endl;
    cout << endl;
    do {
        cout << "ENTER USERNAME : \n";
        cin >> admin.username;
        cout << "ENTER PASSWORD : \n";
        cin >> admin.password;
        loginValidation = validate_Login(admin.username, admin.password);

        if (loginValidation) {
            admin_Page();
        } else
            cout << "INVALID INPUT. PLEASE ENTER CORRECT ONE!.\n";
    }while(!loginValidation);
}

void admin_Page() {
    int choice;
    cout << "1. ADD ACCOUNT\n";
    cout << "ENTER CHOICE : \n";
    cin >> choice;

    switch(choice){
        case 1: add_Account();

    }
}

void add_Account(){
    accountData getData;
    accountData *ptr = &getData;
    fstream fileAdd;
    fileAdd.open("");
    cout << "ENTER FULL NAME : ";
    cin >> getData.name;

    cout << "ENTER USERNAME : ";
    cin >> getData.username;

    cout << "ENTER PASSWORD : ";
    cin >> getData.password;

    cout << "ENTER ADDRESS,CITY,STATE : ";
    cin >> getData.address;

    cout << "ENTER INITIAL BALANCE : ";
    cin >> getData.balance;

    ofstream writeFile;
    writeFile.open("");
}

void disp(){
    accountData GetData;
}

int generateID(){

    random_device id;
    mt19937_64 generator{id()};
    uniform_int_distribution<> dist{100000,999999};
    int x = dist(generator);
    return x;

}
