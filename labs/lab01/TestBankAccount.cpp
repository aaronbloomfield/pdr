#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include "bankAccount.h"
using namespace std;

string options[] =   {"Quit",
					  "Create Account",
                      "Deposit",
                      "Withdraw",
                      "View Balance",
                     };
int const n_choice = 5;
int menu(string option[], int n_opt);
bool is_double(const string& s);
double sanitize(const string& s);

int main(){
	string response;
	bankAccount* account = NULL;
	double previousAmount;

	cout << fixed;
	cout << setprecision(2);
	cout << "--------------------------------------------------\n";
    cout << "This test harness operates with one bank account\n"
         << "Use the menu options to manipulate it\n\n";

	while(1){
		int option = menu(options, n_choice);

		switch(option){
			case 1:					// quit
				cout << "\tDo you really want to quit? (y/n) > ";
                cin  >> response;

                if (response[0] == 'y' || response[0] == 'Y') {                 // Normal Exit
                    if (account != NULL) delete account;
                    return 0;
                }

	            break;
	        case 2:					// new accont
	        	if (account != NULL) delete account;

                cout << "\tDo you want to initialize it with an amount (y/n)? > ";
                cin  >> response;

                if (response[0] != 'y' && response[0] != 'Y'){
                	cout << "\tCurrent balance is: $0.00\n";
                	account = new bankAccount;
                    break;
                } 
                // accept elements
                cout << "\t\tEnter the amount you would like your bank account to have.\n";
                cout << "\t\tThe amount will be rounded to the second decimal place: ";
                cin >> response;

                while (! is_double(response)) {
                    cout << "\t\tPlease input a valid numeric: ";
                    cin >> response;
                }

                account = new bankAccount(sanitize(response));
                cout << endl << "Current balance is: $" << account->getBalance() << endl;
                break;
            case 3: 				// Deposit
            	if (account == NULL){
            		cout << endl << "\tCreate an account first." << endl;
            		break;
            	}

            	cout << "\tYou currently have $" << account->getBalance() << " in your account\n"
            		 << "\tEnter how much you would like to deposit: ";
            	cin >> response;

            	while (! is_double(response)) {
                    cout << "\tPlease input a valid numeric: ";
                    cin >> response;
                }

                previousAmount = account->getBalance();
                account->deposit(sanitize(response));
                if(previousAmount == account->getBalance()){
                	cout << endl << "\tNo money deposited into your account.";
                }
                cout << endl << "\tThe new balance is: $" << account->getBalance() << endl;
                break;
            case 4:					// Withdraw
            	if (account == NULL) {
            		cout << endl << "\tCreate an account first." << endl;
            		break;
            	}

            	cout << "\tYou currently have $" << account->getBalance() << " in your account\n"
            		 << "\tEnter how much you would like to withdraw: ";
            	cin >> response;

            	while (! is_double(response)) {
                    cout << "\tPlease input a valid numeric: ";
                    cin >> response;
                }

                previousAmount = account->getBalance();
                account->withdraw(sanitize(response));
                if (previousAmount == account->getBalance()){
                	cout << endl << "\tNo money was taken out of your account.";
                }
                cout << endl << "\tThe new balance is: $" << account->getBalance() << endl;
                break;
            case 5:					// View balance
            	if (account == NULL) {
            		cout << endl << "\tCreate an account first." << endl;
            		break;
            	}

            	cout << "\tCurrent balance is: $" << account->getBalance() << endl;
            	break;
		}
	}

	return 0;
}

int menu(string option[], int n_opt) {
    int choice, i;
    string input;

    cout << "     - - - - - -  MENU - - - - - -\n\n";

    for (i = 0; i < n_opt; ++i)
        cout << "\t" << (i+1) << " - " << option[i] << endl;

    cout << "\n";
    cout << "     - - - - - - - - - - - - - - -\n";

    while (input.empty()) {
        cout << "     Enter number of choice > ";
        cin >> input;

        if (isdigit(input[0])) {
            choice = atoi(input.c_str());

            if (choice <= n_opt && choice > 0) {
                return choice;
            } else {          /* choice out of range */
                cout << "\tYour response MUST be between 1 and "
                     << n_opt << endl;
                input = "";
            }
        } else {                /* Non-numeric input, ignore */
            cout << "\tYour response MUST be a number!\n";
            input = "";
        }
    }

    return 1;
}

bool is_double(const string& s){
	char* end;
	double val = strtod(s.c_str(), &end);
	// make sure end is not the start of the string nor null terminate
	// make sure val is not HUGE_VAL, meaning the num is out of double's range
	return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

double sanitize(const string& s){
	char* end;
	double amount = strtod(s.c_str(), &end);
	amount = round(amount * 100.0) / 100.0;
    if (amount < 0) amount = 0;
	return amount;
}
