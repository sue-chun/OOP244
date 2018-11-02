// Sue Ming Chun
// 032343154

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>
#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount {
		double current_balance;

	protected:
		double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double initial_bal);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double add_amount);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double sub_amount);
	};
}
#endif
