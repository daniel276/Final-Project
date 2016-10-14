
// Final_Project.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

void main_Menu();
bool login_validation(string usrName, string pin);
void login_page();
void forgot_password();
void generate_Ticket_Number();
void clearScreen();
void account_Page();

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
	int choice,displayTicket; 
	cout << "-------------------------------------------------------------" << endl;
	cout << "                       WELCOME TO                            " << endl;
	cout << "                   BANK CENTRAL AFRICA                       " << endl;
	cout << "                     ONLINE BANKING                          " << endl;
	cout << "-------------------------------------------------------------" << endl;


	cout << "1.\t LOGIN" << endl;
	cout << "2.\t FORGOT PASSWORD" << endl;
	cout << "Enter your choice (1-2)" << endl;
	cin >> choice;
	while (choice <0 || choice >2) // Validate input
	{
		cout << "INVALID INPUT, PLEASE ENTER 1 OR 2 ONLY\n";
		cin >> choice;
	cout << choice;
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
	clearScreen();
	bool validateLogin=false;
	string nameLogin, passLogin;
	do{
	
	cout << "Enter Username : \n";
	cin >> nameLogin;
	cout << "Enter Password : \n";
	cin >> passLogin;
	validateLogin = login_validation(nameLogin, passLogin);
	
	if(validateLogin)
	{
		clearScreen();
		account_Page();
	}
	else 
		cout << "Wrong Username/PIN. Please enter correct one!.\n";
	
	
}while(!validateLogin);

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
	
	cout << "Enter 1 to Main Menu" << endl;
	cout << "Enter 2 to Exit" << endl;
	cin >> choice;
	do{
	
	if(choice <=1 || choice >3)
	{
		clearScreen();
		goOn=true;
		main_Menu();
	}
	else {
		cout << "Enter 1 or 2 only!.\n";
	}
}while(!goOn);
}


bool login_validation(string usrName, string pin)
{
	
	bool validate; //set initial boolean validate value to false.
	if (usrName == "daniel" && pin == "123456") // condition if 
	{
		bool validate = true; //flaggg
	}
	else
	{
		bool validate = false;
	}
	return validate;
}

void clearScreen() //function to clear the screen 
    {
    cout << string( 100, '\n' );
    }

void account_Page(){
	cout << "-------------------------------------------";
	cout << "Hi, [usrName]";
	cout << endl;
	cout << "-------------------------------------------";
}

/*void date_Time() {
	time_t now = time(0);
	char* dt = ctime(&now);

	cout << dt;
}*/

