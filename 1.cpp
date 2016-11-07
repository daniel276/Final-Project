//
// Created by Daniel Juanda on 11/6/2016.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main8(){
    string usrname, password;
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
        cout << "Login successful!.";
    }
        else
    {
        cout << "Login Failed.";
    }

    read.close();
}