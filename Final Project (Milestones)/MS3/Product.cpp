// Sue Ming Chun
// 032343154

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "Product.h"


using namespace std;

namespace AMA {
	void Product::name(const char * new_name) {
		if (new_name != nullptr) {
			the_name = new char[strlen(new_name) + 1];
			strncpy(the_name, new_name, strlen(new_name));
			the_name[strlen(new_name)] = '\0';
		}
	}

	const char * Product::name() const {
		return the_name;
	}

	const char * Product::sku() const {
		return the_sku;
	}

	const char * Product::unit() const {
		return the_unit;
	}

	bool Product::taxed() const {
		return the_taxable;
	}

	double Product::price() const {
		return the_pretax;
	}

	double Product::cost() const {					// used taxed() function instead of private data member the_taxable 	
		if (taxed())
			return (price()*(TAX + 1));
		else
			return price();
	}

	void Product::message(const char * error_msg) {
		prod_es.message(error_msg);					// prod_es as object of ErrorState class using ErrorState member function message(const char*) 
	}

	bool Product::isClear() const {
		return prod_es.isClear();					// prod_es as object of ErrorState class using ErrorState member function isClear 
	}

	Product::Product(char new_type) {
		the_type = new_type;
		the_sku[0] = '\0';						// check here if needed (might need initialize the_type
		the_unit[0] = '\0';
		the_name = nullptr;
		the_onhand = 0;
		the_needed = 0;
		the_pretax = 0.0;
		the_taxable = false;
	}

	Product::Product(const char * new_sku, const char * new_name, const char * new_unit, int new_onhand, bool new_taxable, double new_pretax, int new_needed) {
		strncpy(the_sku, new_sku, max_sku_length+1);
		the_sku[strlen(new_sku)+1] = '\0';

		strncpy(the_unit, new_unit, max_unit_length+1);
		the_unit[strlen(new_unit)+1] = '\0';

		the_onhand = new_onhand;
		the_needed = new_needed;
		the_pretax = new_pretax;
		the_taxable = new_taxable;

		name(new_name);				// call name() function to deep copy product name
	}

	Product::Product(const Product & src) {
		if (src.the_name != nullptr) {
			the_name = nullptr;
			*this = src;				// call overloaded assignment operator 
		}
	}

	Product::~Product() {
		delete[] the_name;
		prod_es.clear();
	}

	Product & Product::operator=(const Product & src) {
		if (this != &src) {
			strncpy(the_sku, src.the_sku, max_sku_length+1);
			the_sku[strlen(src.the_sku)+1] = '\0';

			strncpy(the_unit, src.the_unit, max_unit_length+1);
			the_unit[strlen(src.the_unit)+1]= '\0';

			the_type = src.the_type;
			the_onhand = src.the_onhand;
			the_needed = src.the_needed;
			the_pretax = src.the_pretax;
			the_taxable = src.the_taxable;

			delete[] the_name;

			name(src.the_name);			// call name() function to deep copy product name
		}
		return *this;
	}

	std::fstream & Product::store(std::fstream & file, bool newLine) const {
		file << the_type << ',' << the_sku << ',' << the_unit << ',' << the_name << ',' << the_onhand << "," << the_taxable << "," << the_pretax << "," << the_needed;
		if (newLine)
			file << endl;
		file.clear();
		file.close();
		return file;
	}

	std::fstream & Product::load(std::fstream & file) {
		Product temp;

		if (file.is_open()) {
			file >> temp.the_type >> temp.the_sku >> temp.the_unit >> temp.the_name >> temp.the_onhand >> temp.the_taxable >> temp.the_pretax >> temp.the_needed;
			*this = temp;					// call copy assignment operator 
		}
		return file;
		
	}

	std::ostream & Product::write(std::ostream & os, bool linear) const {
		if (linear) {
			os << setw(max_sku_length) << left << sku() << "|"
				<< setw(20) << left << name() << "|"
				<< setw(7) << fixed << setprecision(2) << right << cost() << "|"
				<< setw(4) << right << quantity() << "|"
				<< setw(10) << left << unit() << "|"
				<< setw(4) << right << qtyNeeded() << "|";
		}
		else {
			os << "SKU: " << sku() << endl
				<< "Name: " << name() << endl
				<< "Price: " << price() << endl;

			if (taxed())
				os << "Price after tax: " << cost() << endl;
			else
				os << "N/A" << endl;
			os << "Quantity on hand: " << quantity() << endl
				<< "Quantity Needed: " << qtyNeeded() << endl;
		}
		return os;
	}

	std::istream & Product::read(std::istream & is) {
		char new_sku[max_sku_length + 1];
		char *new_name = new char[max_name_length + 1];
		char new_unit[max_unit_length + 1];
		int new_onhand;
		int new_needed;
		double new_pretax;
		char tax_input;
		bool new_taxable;

		cout << " Sku: ";
		is >> new_sku;

		cout << " Name (no spaces): ";
		is >> new_name;

		cout << " Unit: ";
		is >> new_unit;

		cout << " Taxed? (y/n): ";
		is >> tax_input;

		if (tax_input == 'Y' || tax_input == 'y')
			new_taxable = true;
		else if (tax_input == 'N' || tax_input == 'n')
			new_taxable = false;
		else {
			is.setstate(ios::failbit);
			prod_es.message("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail()) {
			cout << " Price: ";
			is >> new_pretax;
			if (is.fail()) {
				prod_es.message("Invalid Price Entry");
			}

		}

		if (!is.fail()) {
			cout << " Quantity on hand: ";
			is >> new_onhand;
			if (is.fail()) {
				prod_es.message("Invalid Quantity Entry");
			}
		}

		if (!is.fail()) {
			cout << " Quantity needed: ";
			is >> new_needed;
			if (is.fail()) {
				prod_es.message("Invalid Quantity Needed Entry");
			}
		}

		if (!is.fail()) {
			*this = Product(new_sku, new_name, new_unit, new_onhand, new_taxable, new_pretax, new_needed);
		}
		return is;
			
	}


	bool Product::operator==(const char * new_sku) const {
		if (strcmp(new_sku, the_sku) == 0)
			return true;
		else
			return false;
	}

	double Product::total_cost() const {
		double total_cost = quantity() * cost();
		return total_cost;
	}

	void Product::quantity(int new_onhand) {
		the_onhand = new_onhand;
	}

	bool Product::isEmpty() const {
		if (the_name == nullptr)
			return true;
		else
			return false;
	}

	int Product::qtyNeeded() const {
		return the_needed;
	}

	int Product::quantity() const {
		return the_onhand;
	}

	bool Product::operator>(const char * new_sku) const {
		if (strcmp(the_sku, new_sku) > 0)
			return true;
		else
			return false;
	}

	bool Product::operator>(const Product & src) const {
		if (strcmp(the_name, src.the_name) > 0)
			return true;
		else
			return false;
	}

	int Product::operator+=(int units) {
		if (units > 0) {
			the_onhand += units;
			return the_onhand;
		}
		else
			return the_onhand;
	}

	std::ostream & operator<<(std::ostream & os, const Product & src) {
		return src.write(os, true);
	}

	std::istream & operator>>(std::istream & is, Product & src) {
		src.read(is);
		return is;
	}

	double operator+=(double & total, const Product & src) {
		return total + src.total_cost();
	}
}