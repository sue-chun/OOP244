// Sue Ming Chun 
// 032343154

#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>

namespace AMA {

	#define NO_ERROR 0
	#define CIN_FAILED 1
	#define YEAR_ERROR 2
	#define MON_ERROR 3
	#define DAY_ERROR 4
	
	// Predefined Constants
	const int min_year = 2000;
	const int max_year = 2030;

	class Date {
	private:
		// Data Members 
		int the_year, the_month, the_day, the_compare, error_state;

		// Member Functions 
		int mdays(int, int) const;
		void errCode(int errorCode);

	public:
		// Constructors 
		Date();
		Date(int year, int month, int day);

		//Operators 
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		// Queries and Modifiers
		int errCode() const;
		bool bad() const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
	// Helper Functions 
	std::ostream& operator<<(std::ostream& ostr, const Date&);
	std::istream& operator>>(std::istream& istr, Date&);
}
#endif