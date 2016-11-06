#ifndef ACCOUNTDATA_H_INCLUDED
#define ACCOUNTDATA_H_INCLUDED
#include <string>
using namespace std;
class accountData {
private:
    int ID;
    std::string name;
    std::string username;
    std::string password;
    std::string address;
    double balance;

public:
    void setName(string name){
        this->name=name;
    }

    void setUserName(string username){
    this->username=username;
    }

    void setPass(string pass){
        this->password=password;
    }

    void setAddress(string address){
        this->address=address;
    }

    void setBalance(int balance){
        this->balance=balance;
    }

    string getName(){
        return name;
    }

    string getUserName(){
        return username;
    }

    string getPass(){
        return password;
    }
    string getAddress(){
        return address;
    }
    double getBalance(){
        return balance;
    }



};

class Admin:public accountData{
private:
    string adminUsr, adminPass;
public:
    Admin(){
        adminUsr="admin";
        adminPass="lock90";
    }

    void setAdminUsr(string usrname){
        adminUsr = usrname;
    }

    void setPass(string pass){
        adminPass=pass;
    }

    string getAdminUsr(){
        return adminUsr;
    }
    string getPass(){
        return adminPass;
    }
};


#endif // ACCOUNTDATA_H_INCLUDED
