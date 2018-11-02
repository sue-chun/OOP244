// Sue Ming Chun
// 032343154

#include <iostream>
#include <cstring>
#include <string>
#include "ErrorState.h"
using namespace std;

namespace AMA {
	ErrorState::ErrorState(const char * errorMessage) {
		if (errorMessage == nullptr)
			the_message = nullptr;
		else {
			the_message = new char[strlen(errorMessage) + 1];					// allocate new dynamic memory
			strncpy(the_message, errorMessage, (strlen(errorMessage) + 1));		// copy into the_message 
		}
	}

	ErrorState::~ErrorState() {				// deallocate dynamic memory of the_message 
		delete[] the_message;
		the_message = nullptr;
	}

	void ErrorState::clear() {
		delete[] this->the_message;			// deallocate dynamic memory associated with current object using this keyword
		the_message = nullptr;
	}

	bool ErrorState::isClear() const {
		if (the_message == nullptr)
			return true;
		else
			return false;
	}

	void ErrorState::message(const char * str) {
		delete[] the_message;								// deallocate previous memory
		the_message = new char[strlen(str) + 1];			// create new dynamic memory
		strncpy(the_message, str, (strlen(str) + 1));		// copy into the_message 
	}

	const char * ErrorState::message() const {
		return the_message;
	}

	std::ostream & operator<<(std::ostream & os, const ErrorState & em) {
		if (!em.isClear())
			os << em.message();
		return os;
	}
}