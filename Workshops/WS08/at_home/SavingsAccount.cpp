// Sue Ming Chun
// 032343154

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

sict::SavingsAccount::SavingsAccount(double initial_bal, double s_int) : Account(initial_bal) {		// pass initial_bal to base class constructor 
	if (s_int > 0) 
		current_interest = s_int;
	else
		current_interest = 0;
}

void sict::SavingsAccount::monthEnd() {
	double interest = (balance() * current_interest);			// inherit balance() to query current_balance amount (private member function of Account) 
	credit(interest);											// inherit credit() member function from Account 
}

void sict::SavingsAccount::display(ostream & os) const {
	os << "Account type: Savings" << endl;
	os.precision(2);											// change to 2 decimal places and fixed 
	os.setf(ios::fixed);
	os << "Balance: $" << Account::balance() << endl;
	os << "Interest Rate (%): " << (current_interest * 100) << endl;
	os.precision(6);
	os.unsetf(ios::fixed);
}
