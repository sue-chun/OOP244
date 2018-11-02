#ifndef OOP244_CRA_ACCOUNT_H
#define OOP244_CRA_ACCOUNT_H	

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_years = 4;

	class CRA_Account {
		char CRAFamilyName[max_name_length + 1];
		char CRAGivenName[max_name_length + 1];
		int CRAsin;

		int arr_years[max_years];
		double arr_bal[max_years];
		int CRAYears = 0;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
	};
}

#endif