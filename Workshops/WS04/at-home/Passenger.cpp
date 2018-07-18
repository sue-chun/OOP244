// TODO: add file header comments here
// Sue Ming Chun 
// 032343154

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Passenger.h"

using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		PassName[0] = '\0';
		DestName[0] = '\0';
		y_dep = 0;
		m_dep = 0;
		d_dep = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char * pass, const char * dest) {
		if (pass != nullptr && dest != nullptr) {
			strncpy(PassName, pass, 32);
			PassName[31] = '\0';
			strncpy(DestName, dest, 32);
			DestName[31] = '\0';
			y_dep = 2017;
			m_dep = 7;
			d_dep = 1;
		}
		else {
			*this = Passenger();							// makes current object to safe empty state 
		}
	}

	Passenger::Passenger(const char * pass, const char * dest, int year, int month, int day) {
		if (pass != nullptr && dest != nullptr && year >= 2017 && year <= 2020 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
			strncpy(PassName, pass, 32);
			PassName[31] = '\0';
			strncpy(DestName, dest, 32);
			DestName[31] = '\0';
			y_dep = year;
			m_dep = month;
			d_dep = day;
		}
		else {
			*this = Passenger();
		}
	}


	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (PassName[0] != '\0' && DestName[0] != '\0' && y_dep >= 2017 && y_dep <= 2020 && m_dep >= 1 && m_dep <= 12 && d_dep >= 1 && d_dep <= 31) {		// could also check with: (strlen(PassName) > 0 && strlen(DestName > 0)
			return false;
		}
		else {
			return true;
		}
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (PassName[0] != '\0' && DestName[0] != '\0' && y_dep != 0 && m_dep != 0 && d_dep != 0) {
			cout << PassName << " - " << DestName << " on " << y_dep << "/" << setfill('0') << setw(2) << m_dep << "/" << setfill('0') << setw(2) << d_dep << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}

	const char* Passenger::name() const {
		return PassName;
	}

	bool Passenger::canTravelWith(const Passenger& ptravel) const {
		if ((*this).y_dep == ptravel.y_dep && (*this).m_dep == ptravel.m_dep && (*this).d_dep == ptravel.d_dep && strcmp((*this).DestName, ptravel.DestName) == 0) {	// make sure date of travel and destination is same to travel together 
			return true;
		}
		else {
			return false;
		}
	}
}

