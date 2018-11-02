// Sue Ming Chun 
// 032343154

// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"

using namespace std;

namespace AMA {

	// PUBLIC CONSTRUCTORS 
	// set safe empty state with zero-argument constructor
	Date::Date() {
		the_year = 0;
		the_month = 0;
		the_day = 0;
		the_compare = 0;
		error_state = NO_ERROR;
	}

	// 3 argument constructor to validate input data (save if valid)
	Date::Date(int year, int month, int day) {
		bool valid_year = year >= min_year && year <= max_year;
		int month_days = mdays(month, year);        // call mdays member function
		bool valid_month_days = month_days != -1 && day <= month_days;

		if (valid_year && valid_month_days) {
			the_year = year;
			the_month = month;
			the_day = day;
			error_state = NO_ERROR;
			the_compare = year * 372 + month * 13 + day;
		}
		else {
			*this = Date();
			error_state = NO_ERROR;
		}
	}

	// PRIVATE MEMBER FUNCTIONS 
	// number of days in month and year
	int Date::mdays(int mon, int year) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	// set the error state to the parameter errorCode
	void Date::errCode(int errorCode) {
		error_state = errorCode;
	}

	// PUBLIC OPERATORS 
	// compare rhs == this
	bool Date::operator==(const Date& rhs) const {
		if (this->the_year == rhs.the_year && this->the_month == rhs.the_month && this->the_day == rhs.the_day)
			return true;
		else
			return false;
	}

	// compare rhs != this
	bool Date::operator!=(const Date& rhs) const {
		if (!(*this == rhs))
			return true;
		else
			return false;
	}

	// see if this < rhs (if doesn't work, double check this) 
	bool Date::operator<(const Date& rhs) const {
		if (this->the_year < rhs.the_year)
			return true;
		else if (this->the_year == rhs.the_year && this->the_month < rhs.the_month)
			return true;
		else if (this->the_year == rhs.the_year && this->the_month == rhs.the_month && this->the_day < rhs.the_day)
			return true;
		else
			return false;
	}

	// see if this > rhs
	bool Date::operator>(const Date& rhs) const {
		if (!(*this < rhs))
			return true;
		else
			return false;
	}

	// see if this <= rhs
	bool Date::operator<=(const Date& rhs) const {
		if (*this < rhs || *this == rhs)
			return true;
		else
			return false;
	}

	// see if this >= rhs
	bool Date::operator>=(const Date& rhs) const {
		if (*this > rhs || *this == rhs)
			return true;
		else
			return false;
	}

	// PUBLIC QUERIES AND MODIFIERS 
	// Return error_state as an error code value
	int Date::errCode() const {
		return error_state;
	}

	// Return true if m_errorState != NO_ERROR (if doesn't work, double check this) 
	bool Date::bad() const {
		if (error_state != NO_ERROR)
			return true;
		else
			return false;
	}

	// use istream to read date 
	std::istream& Date::read(std::istream& istr) {
		char slash;

		errCode(NO_ERROR);		
		istr >> the_year >> slash >> the_month >> slash >> the_day;


		if (istr.fail()) {
			*this = Date();
			errCode(CIN_FAILED);
		}

			if (the_year < min_year || the_year > max_year) {
				*this = Date();
				errCode(YEAR_ERROR);
			}
			else if (the_month < 1 || the_month > 12) {
				*this = Date();
				errCode(MON_ERROR);
			}
			else if (the_day > mdays(the_month, the_year)) {
				*this = Date();
				errCode(DAY_ERROR);

		}
		istr.clear();
		return istr;
	}

	// use ostream to print date 
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << the_year << "/";
		if (the_month < 10)
			ostr << 0;
		ostr << the_month << "/";
		if (the_day < 10)
			ostr << 0;
		ostr << the_day;

		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& object1)
	{
		return object1.read(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& object2)
	{
		return object2.write(ostr);
	}
}
