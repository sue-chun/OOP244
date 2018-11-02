// Sue Ming Chun 
// 032343154

// TODO: header file guard
#ifndef OOP244_FRACTION_H
#define OOP244_FRACTION_H

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int num;
		int den;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction&) const;
	};
}


#endif