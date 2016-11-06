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
int exit_select();
void add_Account();
int generateID();
int main(){
    cout << generateID();
    login_Page();
    disp();

    return 0;
}



bool validate_Login(string username, string password) {
    Admin get;
    if(username==get.getAdminUsr() && password==get.getPass()){
        return true;
    }
    else
    {
        return false;
    }
}



void login_Page() {
    bool loginValidation;
    string username,password;
    accountData admin;
    cout << "-----------------------------------" << endl;
    cout << "        BANK CENTRAL AFRICA        " << endl;
    cout << "           ADMINISTRATOR           " << endl;
    cout << "               LOGIN               " << endl;
    cout << "-----------------------------------" << endl;
    cout << endl;
    do {
        cout << "ENTER USERNAME : \n";
        cin >> username;
        cout << "ENTER PASSWORD : \n";
        cin >> password;
        loginValidation = validate_Login(username, password);

        if (loginValidation) {
            admin_Page();
        } else
            cout << "INVALID INPUT. PLEASE ENTER CORRECT ONE!.\n";
    }while(!loginValidation);
}

void admin_Page() {
    int choice;
    cout << "1. ADD ACCOUNT\n";
    cout << "2. Exit\n";
    cout << "ENTER CHOICE : \n";
    cin >> choice;

    switch(choice){
        case 1: add_Account();
        case 2: exit_select();
        default: cout << "ERROR";

    }
}

void add_Account(){
    accountData getData;
    string name,username,password,address;
    int balance;
    cout << "ENTER FULL NAME : ";
    getline(cin,name);
    cin.ignore();

    cout << "ENTER USERNAME : ";
    cin >> username;

    cout << "ENTER PASSWORD : ";
    cin >> password;

    cout << "ENTER ADDRESS,CITY,STATE : ";
    cin >> address;

    cout << "ENTER INITIAL BALANCE : $";
    cin >> balance;

    getData.setName(name);
    getData.setUserName(username);
    getData.setAddress(address);
    getData.setBalance(balance);

    int id = generateID();
    fstream write;
    write.open("id",ios::out);

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

int exit_select(){
    cout << "Now Exit.";
   return 0;
}