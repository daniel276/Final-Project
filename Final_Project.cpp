
// Final_Project.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using namespace std;

void main_Menu();
bool login_validation(string usrName, string pin);
void login_page();
void forgot_password();
void generate_Ticket_Number();
void clearScreen();
void account_Page();
void sleep(unsigned);
string nameLogin;
string UsrName;



int main()
{
	clearScreen();
	main_Menu(); // call main_menu();



    return 0;
}

void main_Menu()
{
	int choice;
	int displayTicket; 
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
	void ClearScreen();
}

void login_page() 
{
	clearScreen(); 								// clear screen 
	bool validateLogin=false;					// set initial value of validateLogin as false 
	string nameLogin, passLogin;					// declare string variables as input for argument login_Validation 
	
	
	do{											// do syntax
	cout << "Enter Username : \n";				// prompt user to input username
	cin >> nameLogin;							// store nameLogin string
	cout << "Enter Password : \n";				// prompt user to input username
	cin >> passLogin;							// store passLogin string
	validateLogin = login_validation(nameLogin, passLogin);			
	
	if(validateLogin ==1) 						// if validateLogin accept true value then proceed
	{
		clearScreen();							// clear screen 
		account_Page();							// go to account_Page function
	}
	else 
		cout << "Invalid input, enter correct username/password!.\n";
	
}while(validateLogin!=1); 

}

void forgot_password()
{
	bool goOn=false;
	int choice;
	clearScreen();
	const int MIN_VALUE = 1000000;
	const int MAX_VALUE = 9999999;
	int ticket_Number;
	unsigned seed = time(0);

	srand(seed);

	ticket_Number = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	cout << "--------------------------------------------\n";
	cout << "          WE'VE MADE YOU A TICKET           \n";
	cout << "\t  Ticket Number : " << ticket_Number << endl;
	cout << "PLEASE KEEP THIS TICKET NUMBER TO CONTACT US.\n";
	cout << "--------------------------------------------\n";
	
	
	do {
		
	cout << "Enter 1 to Main Menu" << endl;
	cout << "Enter 2 to Exit" << endl;
	cin >> choice;
	
	switch (choice){
	
	case 1 : {
		goOn = true;
		clearScreen();
		main_Menu();
		break;
	}
	case 2 :{
		cout << "Exit Now.";
		break;
}

	default : {
		cout <<"Invalid input 1 or 2 only.";
		break;
		}
	}
		
}while (goOn);
}

bool login_validation(string usrName, string pin)
{
	bool validate; //set initial boolean validate value to false.
	if (usrName == "daniel" && pin == "123456") // condition if 
	{
	        validate = true; //flaggg , true bool validate is true if the usrName and pin input are correct.
	}
	else
	{
		 validate = false;
	}
	return validate;
}

void clearScreen() //function to clear the screen 
    {
    cout << string( 100, '\n' );
    }

void account_Page(){ // start func account_Page()
	int choice;
	ifstream userAccount;
	userAccount.open("userDetails.txt");
	clearScreen();
	string usrName, usrBalance;
	getline(userAccount, usrName, '|');
	sleep(1500);
	cout << "---------------------------------------------------\n";
	cout << "Hi, " << usrName << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------------------------------------\n";
	
	sleep(750);
	cout << "1. Check Balance \n";
	cout << "2. Funds Transfer \n";
	cout << "3. Select Payment \n";
	cout << "4. Mini Statements \n";
	cout << "5. Account Settings \n";
	cout << "6. Cancel \n";
	
	cout << "Enter your choice: \n";
	
	cin >> choice;
	
	
	
} // end func account_Page()

void check_Balance(){
	clearScreen();
	ifstream accountDetails;
	
	cout << "Your Balance is : \n";
	
}

void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }




/*void date_Time() {
	time_t now = time(0);
	char* dt = ctime(&now);

	cout << dt;
}*/

