// Sue Ming Chun
// 032343154

#include <iostream>
#include <iomanip>
#include "Perishable.h"

using namespace std;

namespace AMA {
	Perishable::Perishable() : Product('P') {
		prod_es.clear();
	}

	std::fstream & Perishable::store(std::fstream & file, bool newLine) const {
		Product::store(file, false);
		file << "," << Date(the_expiry) << endl;
		return file;
	}

	std::fstream & Perishable::load(std::fstream & file) {
		Product::load(file);
		the_expiry.read(file);
		file.ignore();
		return file;
	}

	std::ostream & Perishable::write(std::ostream & os, bool linear) const {
	Product::write(os, linear);
		if (isClear() && !isEmpty()) {
			if (linear)
				the_expiry.write(os);
			else {
				os << "\n Expiry date: ";
				the_expiry.write(os);
			}
		}
		return os;
	}

	std::istream & Perishable::read(std::istream & is) {
		Product::read(is);

		if (prod_es.isClear()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			the_expiry.read(is);
		}

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
			is.setstate(std::ios::failbit);
		}
		return is;
	}

	const Date & Perishable::expiry() const {
		return the_expiry;
	}
}