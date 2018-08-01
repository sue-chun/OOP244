// Sue Ming Chun
// 032343154

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include <fstream>

#include "iProduct.h"
#include "ErrorState.h"



namespace AMA {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double TAX = 0.13;

	class Product : public iProduct {
		char the_type;
		char the_sku[max_sku_length + 1];
		char the_unit[max_unit_length + 1];
		char* the_name;
		int the_onhand;
		int the_needed;
		double the_pretax;
		bool the_taxable;

	protected:
		ErrorState prod_es;
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Product(char new_type = 'N');
		Product(const char * new_sku, const char * new_name, const char * new_unit, int new_onhand=0, bool new_taxable=true, double new_pretax=0, int new_needed=0);
		Product(const Product& src);
		~Product();
		Product& operator=(const Product& src);
		std::fstream& store(std::fstream& file, bool newLine=true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int new_onhand);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream& os, const iProduct& src);
	std::istream& operator>>(std::istream& is, iProduct& src);
	double operator+=(double& total, const iProduct& src);
	iProduct* CreateProduct();
}
#endif