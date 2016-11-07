#ifndef ACCOUNTDATA_H_INCLUDED
#define ACCOUNTDATA_H_INCLUDED
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
class AccountData {
private:
    string ID;
    std::string firstName;
    std::string lastName;
    std::string username;
    std::string password;
    std::string address;
    double balance;

public:
   // AccountData(string username,string password,string ID){
    //}
    void setID(string ID){
       this->ID=ID;
   }

    void setFirstName(string firstName){
        this->firstName=firstName;
    }

    void setLastName(string lastName){
        this->lastName=lastName;
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

    void setBalance(double balance){
        this->balance=balance;
    }

    string getID(){
        return ID;
    }

    string getFirstName(){
        return firstName;
    }

    string getLastName(){
        return lastName;
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

class Admin:public AccountData{
private:
    string adminUsr, adminPass;
public:
    Admin(){
        adminUsr="admin";
        adminPass = "lock90";
    }

    void setAdminUsr(string usrname){
        adminUsr = usrname;
    }

    void setAdminPass(string pass){
        adminPass=pass;
    }

    string getAdminUsr(){
        return adminUsr;
    }
    string getAdminPass(){
        return adminPass;
    }
};


#endif // ACCOUNTDATA_H_INCLUDED
