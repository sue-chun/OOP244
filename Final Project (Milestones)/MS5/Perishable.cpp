// Sue Ming Chun
// 032343154

#include <iostream>
#include <iomanip>
#include "Perishable.h"

using namespace std;

namespace AMA {
	Perishable::Perishable() : Product('P') {
		the_expiry = Date();									// sets the current object to a safe empty state
	}

	std::fstream & Perishable::store(std::fstream & file, bool newLine) const {
		Product::store(file, false);							// calls its base class version passing as arguments a reference to the fstream object and a false flag
		file << "," << Date(the_expiry) << endl;				// inserts a comma into the file record appends the expiry date to the file record 
//		if (newLine)											// If newLine is true, this function inserts a newline character (‘\n’) before exiting
	//		file << "\n";										// adds a new line, then it won't match the submission file 
		return file;
	}

	std::fstream & Perishable::load(std::fstream & file) {
		Product::load(file);									// calls its base class version passing as an argument a reference to the fstream object
		the_expiry.read(file);									// loads the expiry date from the file record using the read() function of the Date object
		file.ignore();
		return file;
	}

	std::ostream & Perishable::write(std::ostream & os, bool linear) const {
	Product::write(os, linear);									// calls its base class version passing as arguments a reference to the ostream object and the bool flag
		if (isClear() && !isEmpty()) {							// if the current object is not in an error or safe empty state
			if (linear)											// if linear is true, adds the expiry date on the same line 
				the_expiry.write(os);							// inserts the expiry date into the ostream object. 
			else {												// If linear is false, this function adds a new line character followed by the string “Expiry date: “ and the expiry date 
				os << "\n Expiry date: ";
				the_expiry.write(os);
			}
		}
		return os;												// returns a reference to the modified ostream object
	}

	std::istream & Perishable::read(std::istream & is) {
		Product::read(is);										// This function calls its base class version passing as its argument a reference to the istream object

		if (prod_es.isClear()) {
			cout << " Expiry date (YYYY/MM/DD): ";				// the prompt 
			the_expiry.read(is);								// If the base class object extracts data successfully, this function prompts for the expiry date and stores it in a temporary Date object. 
		}														// This function populates the current object with the data extracted from the istream object

		if (the_expiry.errCode() == CIN_FAILED) 
			prod_es.message("Invalid Date Entry");

		else if (the_expiry.errCode() == YEAR_ERROR) 
			prod_es.message("Invalid Year in Date Entry");

		else if (the_expiry.errCode() == MON_ERROR) 
			prod_es.message("Invalid Month in Date Entry");

		else if (the_expiry.errCode() == DAY_ERROR) 
			prod_es.message("Invalid Day in Date Entry");

		else 
			prod_es.clear();

		if (the_expiry.bad()) {
			is.setstate(std::ios::failbit);						// The member function that sets it to a failed state is istream::setstate(std::ios::failbit)
		}
		return is;
	}

	const Date & Perishable::expiry() const {
		return the_expiry;
	}
}