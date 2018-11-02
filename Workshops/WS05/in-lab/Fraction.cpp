// Sue Ming Chun 
// 032343154

// TODO: insert header files
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Fraction.h"

using namespace std;
// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		num = 0;
		den = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d) {
		if (n >= 0 && d >= 0) {
			num = n;
			den = d;
			reduce();
		}
		else {
			*this = Fraction();							// if not valid inputs, put current object in default constructor
		}
	}

	// TODO: implement the max query
	int Fraction::max() const {
		if (num > den) {
			return num;
		}
		else {
			return den;
		}
	}

    // TODO: implement the min query
	int Fraction::min() const {
		if (num < den) {
			return num;
		}
		else {
			return den;
		}
	}

	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
	void Fraction::reduce() {
		int divide = gcd();						// apparently using gcd() directly didn't produce proper outputs, need to use an int variable first
		num /= divide;			
		den /= divide;
	}

    // TODO: implement the display query
	bool Fraction::isEmpty() const {
		if (num != 0 && den != 0) {				// if not in safe empty, return false
			return false;
		}
		else {
			return true;
		}
	}
    // TODO: implement the isEmpty query
	void Fraction::display() const {
		if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else if (den == 1)						// if denominator is 1, only output the numerator
		{
			cout << num;
		}
		else
		{
			cout << num << "/" << den;
		}
	}

    // TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction sum;										// have to return the value as Fraction type 
		if (!isEmpty() && !rhs.isEmpty()) {
			sum.num = ((this->num) * rhs.den) + ((this->den) * rhs.num);	// need to make the numerator first
			sum.den = this->den * rhs.den;						// then make the denominator 
			return sum;	
		}
		else {
			sum = Fraction();
			return sum;
		}
											// return the entire object 
	}
}

