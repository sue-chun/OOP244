// TODO: add file header comments here
// Sue Ming Chun 
// 032343154

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		PassName[0] = '\0';
		DestName[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char * pass, const char * dest) {
		if (pass != nullptr && dest != nullptr) {
			strncpy(PassName, pass, 32);
			PassName[31] = '\0';
			strncpy(DestName, dest, 32);
			DestName[31] = '\0';

		}
		else {
			*this = Passenger();							// makes current object to safe empty state 
		}
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (PassName[0] != '\0' && DestName[0] != '\0') {	// could also check with: (strlen(PassName) > 0 && strlen(DestName > 0)

			return false;
		}
		else {
			return true;
		}
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (PassName[0] != '\0' && DestName[0] != '\0') {
			cout << PassName << " - " << DestName << "\r" << endl;
		}
		else {
			cout << "No passenger!\r" << endl;
		}
	}

}

