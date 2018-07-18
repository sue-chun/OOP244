// Sue Ming Chun
// 032343154

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include <iostream>
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double current_interest;
	
	public:
			// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

			// TODO: perform month end transactions
		void monthEnd();

			// TODO: display inserts the account information into an ostream			
		void display(std::ostream& os) const;
	};
}
#endif
