#include <iostream>
#include <cstring>
#include "CRA_Account.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {
	bool CRA_Account::isEmpty() const {
		if (CRAsin >= min_sin && CRAsin <= max_sin) {
			return false;
		}
		else {
			return true;
		}
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		strncpy(CRAFamilyName, familyName, max_name_length + 1);
		strncpy(CRAGivenName, givenName, max_name_length + 1);
		CRAsin = sin;

		if (isEmpty()) {
			CRAsin = 0;
		}

	}


	void CRA_Account::display() const {
		if (isEmpty()) {
			cout << "Account object is empty!" << endl;
		}
		else {
			cout << "Family Name: " << CRAFamilyName << endl
				<< "Given Name : " << CRAGivenName << endl
				<< "CRA Account: " << CRAsin << endl;
		}
	}
}