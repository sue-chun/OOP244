// Sue Ming Chun 
// 032343154

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict {
	Contact::Contact() {
		name[0] = '\0';
		pnumbers = nullptr;
		num = 0;
	}

	Contact::Contact(const Contact& src) {
		pnumbers = nullptr;			
		*this = src;				// call the = operator 
	}

	Contact::Contact(const char* new_name, const long long* new_phone, const int new_num) {
		if (new_name != nullptr && new_name[0] != '\0') {
			int name_length = (strlen(new_name) < 20) ? strlen(new_name) : 19;
			strncpy(name, new_name, 19);
			name[name_length] = '\0';
		}
		else {
			name[0] = '\0';
		}
		if (new_phone != nullptr && new_num > 0) {
			pnumbers = new long long[new_num];
			num = 0;

			for (int i = 0; i < new_num; i++) {
				if (isValid(new_phone[i]) && new_num > 0) {
					pnumbers[num] = new_phone[i];
					num += 1;
				}
			}
		}
		else {
			pnumbers = nullptr;
			num = 0;
		}
	}

	Contact& Contact::operator = (const Contact& src) {
		if (this != &src) {
			// shallow copies 
			strncpy(name, src.name, 19);
			num = src.num;

			// deep copies
			delete[] pnumbers;
			if (src.pnumbers != nullptr) {
				pnumbers = new long long[num];
				for (int i = 0; i < num; i++) {
					pnumbers[i] = src.pnumbers[i];
				}
			}
			else {
				pnumbers = nullptr;
			}
		}
		return *this;
	}

	Contact& Contact::operator += (long long int add_num) {
		if (isValid(add_num) && !isEmpty()) {				// cannot be empty and number must be valid to add to array 
			long long *add = new long long[num+1];			// new array of size num+1 
			for (int i = 0; i < num; i++) {
				add[i] = pnumbers[i];
			}
			if (pnumbers != nullptr) {
				delete[] pnumbers;
			}
			num++;	
			pnumbers = new long long[num];
			for (int i = 0; i < num; i++) {
				pnumbers[i] = add[i];						// copy back into pnumbers with new array size of +1 
			}
			pnumbers[num-1] = add_num;						// last element of array is add_num
			delete[] add;
		}
		return *this;
	}

	bool Contact::isEmpty() const {
		if (name[0] == '\0' && pnumbers == nullptr && num <= 0)
			return true;
		else
			return false;
	}

	bool Contact::isValid(const long long new_pnumbers) const {
		string pnumberstring = to_string(new_pnumbers);
		if (new_pnumbers <= 0 || pnumberstring.length() < 11 || pnumberstring.length() > 12 || pnumberstring[pnumberstring.length() - 7] == '0' || pnumberstring[pnumberstring.length() - 10] == '0')
			return false;
		else
			return true;
	}

	void Contact::display() const {
		if (isEmpty())
			cout << "Empty Contact!" << endl;
		else {
			cout << name << endl;
			for (int i = 0; i < num; i++) {
				string pstring;
				string countrycode;
				string areacode;
				string number1;
				string number2;

				pstring = to_string(pnumbers[i]);
				if (pstring.length() == 11) {
					countrycode = pstring.substr(0,1);
					areacode = pstring.substr(1, 3);
					number1 = pstring.substr(4, 3);
					number2 = pstring.substr(7, 4);
				}
				else if (pstring.length() == 12) {
					countrycode = pstring.substr(0,2);
					areacode = pstring.substr(2, 3);
					number1 = pstring.substr(5, 3);
					number2 = pstring.substr(8, 4);
				}
				cout << "(+" << countrycode << ") " << areacode << " " << number1 << "-" << number2 << endl;
			}

		}
	}

	Contact::~Contact() {
		if (pnumbers != nullptr) {
			delete[] pnumbers;
			pnumbers = nullptr;
		}
	}
}