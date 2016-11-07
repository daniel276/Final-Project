//Daniel Juanda // 2001586262 // // //
//HUMAN MALE

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include "accountData.h" // call header file accountData.h which contain struct and link to here.

void main_Menu();
bool login_validation(string usrName, string pin);
void login_page();
void forgot_password();
void clearScreen();
void account_Page();
void check_Balance();
void fund_Transfer();
void confirm_Page();
void select_Payment();
int exit_Select();
void acc_Settings();
string myID,myPass;
//void sleep(unsigned);

int main()
{
    clearScreen();
    main_Menu(); // call main_menu();


    return 0;
}

void main_Menu()
{
    int choice;
    cout << "-------------------------------------------------------------" << endl;
    cout << "                       WELCOME TO                            " << endl;
    cout << "                   BANK CENTRAL AFRICA                       " << endl;
    cout << "                     ONLINE BANKING                          " << endl;
    cout << "-------------------------------------------------------------" << endl;


    cout << "1.\t LOGIN" << endl;
    cout << "2.\t FORGOT PASSWORD" << endl;
    cout << "Enter your choice (1-2)" << endl;
    cin >> choice;
    while (choice <0 || choice >3) // Validate input
    {
        cout << "INVALID INPUT, PLEASE ENTER 1 OR 2 ONLY\n";
        cin >> choice;
    }
    switch (choice) {
        case 1:  login_page(); // if user input '1' then call function login_page
            break;
        case 2: forgot_password(); // if user input '2' then call function forgot_password
            break;

    }
}

void login_page()
{
    string username, password;
    clearScreen();                              // call clear screen
    bool validateLogin;					// set initial value of validateLogin as false
    // declare string variables as input for argument login_Validatio
    do{								        			// do while syntax .. .
        cout << "Enter Username : \n";  				// prompt user to input username
        cin >> username;       			        // store nameLogin string
        cin.ignore();
        cout << "Enter Password : \n";	    			// prompt user to input username
        cin >> password;             				// store passLogin string

        validateLogin = login_validation(username,password);

        if(validateLogin) 						// if validateLogin accept true value then proceed
        {
            clearScreen();							// clear screen
            account_Page();							// go to account_Page function
        }
        else
            cout << "INVALID INPUT. ENTER CORRECT USERNAME/PASSWORD!.\n"; //display if login input is false

    }while(!validateLogin); // keep repeating loop while login input isn't correctly entered.

}

void forgot_password()
{
    bool goOn=false; // initial value set to false
    int choice; // variable to store user's choice
    clearScreen(); // call clearScreen function
    const int MIN_VALUE = 1000000; // set min value of random-number generated
    const int MAX_VALUE = 9999999; // max value of random-numer generated
    int ticketNumber;             // declare ticket_Number variable
    unsigned seed = (unsigned int) time(0);        // seed generated by time

    srand(seed);

    ticketNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; // formula to generate random-number
    cout << "--------------------------------------------\n";           // display
    cout << "          WE'VE MADE YOU A TICKET           \n";           // display
    cout << "\t  Ticket Number : " << ticketNumber << endl;            // display
    cout << "PLEASE KEEP THIS TICKET NUMBER TO CONTACT US.\n";          // display
    cout << "--------------------------------------------\n";           // display


    do {        // do start

        cout << "Enter 1 to Main Menu" << endl;     // display choice 1
        cout << "Enter 2 to Exit" << endl;          // display choice 2
        cin >> choice;                              // prompt user to enter choice;

        switch (choice){                            // switch statement start

            case 1 : {                              // case 1
                goOn = true;                        //
                clearScreen();                      // clear screen func
                main_Menu();                        // go to main_Menu()
                break;                              // break statement if case 1 fulfill
            }
            case 2 :{                               // case 2
                cout << "Exit Now.";                // display exit
                break;                              // break statement ifcase 2 fulfill
            }

            default : {                                             // default switch
                cout <<"INVALID INPUT. ENTER 1 OR 2 ONLY!.";        // display
                break;                                              // break
            }
        }

    }while (goOn);
}

bool login_validation(string usrName, string pass) {
    AccountData user;
    bool valid = false;
    string getUsrname, getPass, getID;
    ifstream data;
    data.open("dataLogin.txt");
    // here open file to replace the test
    while (data >> getUsrname >> getPass >> getID) {
        if (usrName == getUsrname && pass == getPass) {
            valid = true;
            break;
        }
    }
    myID = getID;
    getPass=myPass;
    data.close();
    return valid;

}

void clearScreen() //function to clear the screen
{
    cout << string( 100, '\n' );
}

void account_Page(){ // start func account_Page()
    clearScreen();
    AccountData user;
    string firstName,lastName,username,address;
    double balance;

    ifstream userAccount;
    if(userAccount.good()){
        userAccount.open(myID+".txt");
    }
    else {
        cout << "SOME FILES ARE MISSING. PLEASE CONTACT ADMINISTRATOR!.\n";
    }

    userAccount >> firstName >> lastName >> username >> address >> balance;
    user.setFirstName(firstName);
    user.setLastName(lastName);
    user.setUserName(username);
    user.setAddress(address);
    user.setBalance(balance);
    clearScreen();
    cout << "---------------------------------------------------\n";
    cout << "Hi, " << firstName << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "---------------------------------------------------\n";


    cout << "1. CHECK BALANCE \n";
    cout << "2. FUNDS TRANSFER \n";
    cout << "3. SELECT PAYMENTS \n";
    cout << "4. ACCOUNT SETTINGS \n";
    cout << "5. LOG OUT\n";
    cout << "6. EXIT \n";

    cout << "Enter your choice: \n";
    int select;
    switch(select){
        case 1: check_Balance();
            break;
        case 2: fund_Transfer();
            break;
        case 3: select_Payment();
            break;
        case 4: acc_Settings();
            break;
        case 5: main_Menu();
            break;
        case 6: exit_Select();
            break;

    }

    userAccount.close();

}

void check_Balance() {
    clearScreen();
    AccountData user;

    cout << "---------------------------------------------------\n";
    cout << "                  YOUR BALANCE                     \n";
    cout << endl;
    cout << endl;
    cout << "\t\t\t " << user.getBalance() << endl;
    cout << "---------------------------------------------------\n";

}
// end func account_Page()


void fund_Transfer(){
    clearScreen();
    AccountData user;
    user.setBalance();
    double getAmount,balance;
    int c;
    string destID, destFirstName, destLastName;
    string fullName = destFirstName + destLastName;
    cout << "---------------------------------------------------\n";
    cout << "                  FUND TRANSFER                    \n";
    cout <<  endl;
    cout <<  endl;
    cout <<  endl;
    cout << "---------------------------------------------------\n";
    cout << "ENTER AMOUNT TO TRANSFER : "<< endl;
    cin >> getAmount;

    clearScreen();
    cout << "ENTER DESTINATION ACCOUNT ID : " << endl;
    cin >> destID;

    ifstream search;
    string filename = destID+".txt";
    search.open(filename);
    search >> destFirstName >> destLastName >> destUsername >> destAddress >> destBalance;

    if(search.good()){

        cout << "---------------------------------------------------\n";
        cout << "                   FUND TRANSFER                   \n";
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "---------------------------------------------------\n";
        cout << "ACCOUNT ID RECEIVER : " << destID << endl;
        cout << "ACCOUNT ID Receiver Name : " << destFullName << endl;
        cout << "TRANSFER AMOUNT : " << getAmount << endl;
        cout << endl;
        cout << "DO YOU WISH TO PROCEED ?" << endl;
        cout << "PRESS Y TO CONTINUE..." << endl;
        c = getch();
        if(c=='y'||c=='Y'){
            string pass;
            cout << "---------------------------------------------------\n";
            cout << endl;
            cout << endl;
            cout << endl;
            cout <<"ENTER YOUR PASSWORD TO CONFIRM.."<< endl;
            cin >> pass;

            if(pass==myPass){
                balance-=-getAmount;


            }
        }

    }

}

void confirm_Page(){
    AccountData user;


}

void select_Payment(){

}

void acc_Settings(){

}

int exit_Select(){

    cout << "Exit Now...";
    return 0;

}




/*void date_Time() {
	time_t now = time(0);
	char* dt = ctime(&now);

	cout << dt;
}*/
