#include <iostream>
#include <cstring>
#include <iomanip>
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
		CRAFamilyName[max_name_length] = '\0';
		strncpy(CRAGivenName, givenName, max_name_length + 1);
		CRAGivenName[max_name_length] = '\0';
		CRAsin = sin; 

		int newsin = 0;			// use to change input into array
		int allarray[9];		// store array of digits from input in here
		int evenadd[4];			// store 'adding first set of alternatives to themselves'
		int evensum[4];			// store 'adding digits of evenadd array
		int j = 0;				
		int sum1 = 0;
		int sum2 = 0;
		int sum3 = 0;
		int oddtotal = 0;
		int total = 0;
		int validnum = 0;

		newsin = sin;

		for (int i = 0; i < 9; i++) {			// get remainder of dividing newsin by 10 
			allarray[i] = newsin % 10;			
			newsin /= 10;						// dividing it by 10 makes 'drop' its last digit as it is integer type 
		}

		for (int k = 1; k < 8; k += 2) {		// every other element of allarray so increment k by 2 each time, start at 1 
			evenadd[j] = allarray[k] * 2;		// * 2 because need to add each to themselves
			j++;								// increment j to run through the elements of evenadd array 
		}

/*		evenadd[0] = allarray[1] * 2;			// tedious way of doing the above 'for (int k) loop 
		evenadd[1] = allarray[3] * 2;
		evenadd[2] = allarray[5] * 2;
		evenadd[3] = allarray[7] * 2;
*/

		for (int j = 0; j < 4; j++) {					// get remainder of dividing by 10, then add back a 1 
			if (evenadd[j] > 10) {						// such as 18 remainder is 8, add a 1 makes it 1+8 
				evensum[j] = evenadd[j] % 10 + 1;
				sum1 += evensum[j];
			}
			else if (evenadd[j] == 10) {				// if it is 10, it is simply 1 because 1+0 
				evensum[j] = 1;
				sum2 += evensum[j];
			}
			else {										// if less than 10, it is just the number 
				evensum[j] = evenadd[j];
				sum3 += evensum[j];
			}
		}

		for (int m = 2; m < 9; m += 2) {				// add back the other alternating numbers using loop 
			oddtotal += allarray[m];
		}

//		oddtotal = allarray[2] + allarray[4] + allarray[6] + allarray[8];	// can also add back using this method 

		total = (sum1 + sum2 + sum3) + oddtotal;

		validnum = total + (10 - (total % 10));			// remainder of total / 10, 10 subtract the remainder, add total = next integer multiple of 10 
		validnum -= total;								// next integer multiple of 10 subtract total = number that should match last number of entered SIN 

		if (!isEmpty() && validnum == allarray[0] && familyName[0] != '\0' && givenName[0] != '\0') {
			CRAYears = 0;	
			CRAsin = sin;								// if is valid input, store SIN
		}

		else {
			CRAFamilyName[0] = '\0';
			CRAGivenName[0] = '\0';
			CRAsin = 0;									// if is not valid input, SIN = 0 
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
			for (int i = 0; i < CRAYears; i++) {
				if (arr_bal[i] > 2.00) {
					cout << fixed;
					cout << setprecision(2);
					cout << "Year (" << arr_years[i] << ") balance owing: " << arr_bal[i] << endl;
				}
				else if (arr_bal[i] < -2.00) {
					cout << fixed;
					cout << setprecision(2);				// show 2 decimal places 
					cout << "Year (" << arr_years[i] << ") refund due: " << -arr_bal[i] << endl;
				}
				else {
					cout << "Year (" << arr_years[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
	}

	void CRA_Account::set(int year, double balance) {
		if (!isEmpty() && CRAYears < max_years) {
			arr_years[CRAYears] = year;						// store inputted tax year into array 
			arr_bal[CRAYears] = balance;					// store inputted balance into array 
			CRAYears++;										// increment amount of years entered, not exceeding max_years 
		}
	}
}