// Sue Ming Chun
// 032343154

// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double initial_bal, double trans_fee, double month_end) : Account(initial_bal) {		// pass initial_bal to base class constructor
		if (trans_fee > 0 && month_end > 0) {			// if transaction fee and monthly fee are not zero or negative numbers 
			current_trans = trans_fee;
			current_month = month_end;
		}
		else {
			current_trans = 0;
			current_month = 0;
		}
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double add_amount) {
		if (Account::credit(add_amount)) {						// if was able to add credit amount, deduct transaction fee, return true 
			Account::debit(current_trans);
			return true;
		}
		else
			return false;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double sub_amount) {
		if (Account::debit(sub_amount + current_trans))			// if was able to deduct debit amount and transaction fee, return true
			return true;
		else
			return false;
	}

	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		Account::debit(current_month + current_trans);
	}

	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << endl;
		os.precision(2);
		os.setf(ios::fixed);
		os << "Balance: $" << Account::balance() << endl;
		os << "Per Transaction Fee: " << current_trans << endl;
		os << "Monthly Fee: " << current_month << endl;
	}


}