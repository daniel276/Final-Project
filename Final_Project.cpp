
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
string nameLogin;




int main()
{
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
	while (choice <0 || choice > 2) // Validate input
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
}

void login_page() 
{
	bool validateLogin;
	string nameLogin, passLogin;
	cout << "Enter Username : \n";
	cin >> nameLogin;
	cout << "Enter Password : \n";
	cin >> passLogin;
	validateLogin = login_validation(nameLogin, passLogin);
}

void forgot_password()
{
	const int MIN_VALUE = 1000000;
	const int MAX_VALUE = 9999999;
	int ticket_Number;
	unsigned seed = time(0);

	srand(seed);

	ticket_Number = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	cout << "--------------------------------------------\n";
	cout << "          WE'VE MADE YOU A TICKET           \n";
	cout << " Ticket Number : " << ticket_Number << endl;
	cout << "PLEASE KEEP THIS TICKET NUMBER TO CONTACT US.\n";
}


bool login_validation(string usrName, string pin)
{
	
	bool validate = false;
	if (usrName == "daniel" && pin == "123456")
	{
		bool validate = true;
	}
	else
	{
		cout << "WRONG USERNAME OR PIN!";
	}
	return validate;
}


/*void date_Time() {
	time_t now = time(0);
	char* dt = ctime(&now);

	cout << dt;
}*/

