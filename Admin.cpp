//
// Created by Daniel on 10/25/2016.
// this cpp for writing user data
#include <iostream>
#include <random>
#include <sstream>
#include "accountData.h"
#include <conio.h>
using namespace std;
void login_Page();
void admin_Page();
int exit_select();
void add_Account();
void searchData();
void deleteData();
string generateID();
void clearScreen();
int main2(){


    login_Page();

    return 0;
}



bool validate_Login(string username, string password) {
    Admin get;
    if(username==get.getAdminUsr() && password==get.getAdminPass()){
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
    cout << "-----------------------------------" << endl;
    cout << "        BANK CENTRAL AFRICA        " << endl;
    cout << "           ADMINISTRATOR           " << endl;
    cout << "               LOGIN               " << endl;
    cout << "-----------------------------------" << endl;
    cout << endl;
    do {
        cout << "ENTER USERNAME : \n";
        cin >> username;
        cin.ignore();
        cout << "ENTER PASSWORD : \n";
        cin >> password;
        cin.ignore();
        loginValidation = validate_Login(username, password);

        if (loginValidation) {
            admin_Page();
        } else
            cout << "INVALID INPUT. PLEASE ENTER CORRECT ONE!.\n";
    }while(!loginValidation);
}

void admin_Page() {
    clearScreen();
    int choice;
    cout << "1. ADD ACCOUNT\n";
    cout << "2. FIND ACCOUNT\n";
    cout << "3. EXIT\n";
    cout << "ENTER CHOICE : \n";
    cin >> choice;

    switch(choice){
        case 1: add_Account();
            break;
        case 2: searchData();
            break;
        case 3: exit_select();
            break;
        case 4: deleteData();
            break;
        default: cout << "ERROR";
            break;

    }
}

void add_Account(){
    clearScreen();
    AccountData getData;
    string id = generateID();
    string firstName,lastname,username,password,address;
    double balance;


    cout << "ENTER USERNAME : ";
    cin >> username;
    cin.ignore();

    cout << "ENTER PASSWORD : ";
    cin >> password;
    cin.ignore();

    ofstream addRecord;
    addRecord.open("dataLogin.txt",ios::app);
    addRecord << endl << username << " " << password << " " << id;

    addRecord.close();

    cout << "ENTER FIRST NAME : ";
    cin >> firstName;
    cin.ignore();

    cout << "ENTER LAST NAME : ";
    cin >> lastname;
    cin.ignore();

    cout << "ENTER ADDRESS,CITY,STATE : ";
    getline(cin,address);
    cin.ignore();

    cout << "ENTER INITIAL BALANCE : $";
    cin >> balance;
    cin.ignore();

    getData.setFirstName(firstName);
    getData.setLastName(lastname);
    getData.setUserName(username);
    getData.setPass(password);
    getData.setAddress(address);
    getData.setBalance(balance);

    fstream write;
    write.open(id+".txt",ios::out);
    write << getData.getFirstName() << endl;
    write << getData.getLastName() << endl;
    write << getData.getUserName() << endl;
    write << getData.getAddress()<< endl;
    write << getData.getBalance() << endl;
    write.close();

    clearScreen();
    cout << "ACCOUNT SUCCESSFULLY CREATED!.\n";
    cout << "ACCOUNT ID : " << id;

    cout << "ENTER 1 TO MAIN MENU\n";
    cout << "ENTER 2 TO EXIT\n";
    int choice;
    switch(choice){
        case 1 :login_Page();
            break;
        case 2:exit_select();
            break;
        default: cout << "ERROR.";
    }

}

string generateID(){
    ostringstream get;
    const int MIN_VALUE = 100000000; // set min value of random-number generated
    const int MAX_VALUE = 999999999; // max value of random-numer generated
    int genId;             // declare ticket_Number variable
    unsigned seed = (unsigned int) time(0);        // seed generated by time
    srand(seed);
    genId = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    get<< genId;
    return get.str();



}

void searchData(){
    clearScreen();
    ifstream search;
    string id, first,last, username, address, balance;
    cout << "PLEASE ENTER ACCOUNT'S ID ";
    cin >> id;
    cin.ignore();
    search.open(id+".txt");
    clearScreen();
    if(search.is_open()){
        while(search >> first>> last >> username >> address >> balance);
        cout << "ACCOUNT ID : " << id << endl;
        cout << "FULL NAME : " << first+" "+ last << endl;
        cout << "Address : " << address << endl;
        cout << "Balance : " << balance << endl;
    }
else {
        cout << "File Not Found!." << endl;
    }
    search.close();
}

void deleteData(){
    clearScreen();
    string filename;
    char input;
    bool open=false;
    ifstream check;
    cout << "Delete Data" << endl;
    while(!open){
        open = check.is_open();
    cout << "Enter ACCOUNT ID : "<< endl;
    cin >> filename;
    check.open(filename+".txt");

    }

    if(open){
        cout << "DO YOU WISH TO DELETE ACCOUNT " << endl;
        cout << filename << endl;
        cout << "PRESS y/Y TO DELETE" << endl;
        input = getch();
             if(input=='y'||input=='Y'){
                 remove(filename.c_str());
             }
    }
    cout << "ACCOUNT SUCCESSFULLY DELETED!" << endl;
}

int exit_select(){
    clearScreen();
    cout << "Now Exit.";
   return 1;
}

void clearScreen() //function to clear the screen
{
    cout << string( 100, '\n' );
}
