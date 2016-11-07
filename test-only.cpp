//
// Created by Daniel Juanda on 11/6/2016.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main4(){
    string usrname, password;
    string firstName,lastName,username,address;
    double balance;
    double amount;
    cout << "Enter username : ";
    cin >> usrname;
    cout << "Enter password";
    cin >> password;
    bool valid;
    string getUsrname,getPass,getID;
    ifstream read;
    read.open("dataLogin.txt");

    while(read >> getUsrname >> getPass) {
        if (usrname == getUsrname && password == getPass) {
            valid = true;
            break;
        }
    }
    if(valid){
        cout << "Login successful!.\n";
    }
        else
    {
        cout << "Login Failed.";
    }

    cout << "Withdraw : ";
    cin >> amount;

    fstream myAcc;
    myAcc.open("100013065.txt",ios::in);
    myAcc >> firstName >> lastName >> username >> address >> balance;
    balance -=amount;
    read.close();
}