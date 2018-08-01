// Sue Ming Chun
// 032343154 

#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H

#include <iostream>
#include <fstream>

namespace AMA {
	class iProduct {
	public:
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char* str) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iProduct&) const = 0;
	};
	std::ostream& operator<<(std::ostream& os, const iProduct& src);
	std::istream& operator>>(std::istream& is, iProduct& src);
	double operator+=(double& total, const iProduct& src);
	iProduct* CreateProduct();
	iProduct* CreatePerishable();
}
#endif