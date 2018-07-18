// Sue Ming Chun
// 032343154

#include "SavingsAccount.h" 

using namespace std;

namespace sict {

	// define interest rate
	//
	const double interest = 0.05;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type, double initial_bal) {
		iAccount *p = nullptr;
		if (type[0] == 'S') 
			p = new SavingsAccount(initial_bal, interest); 
		return p;
	}
}
