// Sue Ming Chun
// 032343154

#include <iostream>
#include "Account.h"
using namespace std;

namespace sict {
	Account::Account(double initial_bal) {
		if (initial_bal > 0)
			current_balance = initial_bal;
		else
			current_balance = 0;
	}

	bool Account::credit(double add_amount) {
		if (add_amount > 0) {
			current_balance += add_amount;
			return true;
		}
		else 
			return false;
	}

	bool Account::debit(double sub_amount) {
		if (sub_amount > 0) {
			current_balance -= sub_amount;
			return true;
		}
		else 
			return false;
	}

	double Account::balance() const {
		return current_balance;
	}


}