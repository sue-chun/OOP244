// Sue Ming Chun
// 032343154

#include "SavingsAccount.h" 
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	// define interest rate
	//
	const double interest = 0.05;
	const double trans = 0.50;
	const double month = 2.00;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type, double initial_bal) {
		iAccount *p = nullptr;
		if (type[0] == 'S')
			p = new SavingsAccount(initial_bal, interest);
		else if (type[0] == 'C')
			p = new ChequingAccount(initial_bal, trans, month);
		return p;
	}
}
