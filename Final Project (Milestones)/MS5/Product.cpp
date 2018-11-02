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
	void Product::name(const char * new_name) {							// This function receives the address of a C-style null-terminated string that holds the name of the product
		if (new_name != nullptr) {
			the_name = new char[strlen(new_name) + 1];					// stores the name in dynamically allocated memory
			strncpy(the_name, new_name, strlen(new_name));
			the_name[strlen(new_name)] = '\0';
		}
	}

	const char * Product::name() const {
		if (the_name != nullptr)
			return the_name;											// returns the address of the C-style string that holds the name of the product
		else															// If the product has no name, this query returns nullptr
			return nullptr;
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

	double Product::cost() const {										// used taxed() function instead of private data member the_taxable 	
		if (taxed())
			return (price()*(TAX + 1));
		else
			return price();
	}

	void Product::message(const char * error_msg) {
		prod_es.message(error_msg);										// prod_es as object of ErrorState class using ErrorState member function message(const char*) 
	}

	bool Product::isClear() const {
		return prod_es.isClear();										// prod_es as object of ErrorState class using ErrorState member function isClear 
	}

	Product::Product(char new_type) {									// This constructor optionally receives a character that identifies the product type. The default value is ‘N’
		the_type = new_type;
		the_sku[0] = '\0';												// check here if needed (might need initialize the_type)
		the_unit[0] = '\0';
		the_name = nullptr;
		the_onhand = 0;
		the_needed = 0;
		the_pretax = 0.0;
		the_taxable = false;
	}

	Product::Product(const char * new_sku, const char * new_name, const char * new_unit, int new_onhand, bool new_taxable, double new_pretax, int new_needed) {
		strncpy(the_sku, new_sku, max_sku_length+1);
		the_sku[strlen(new_sku)] = '\0';

		strncpy(the_unit, new_unit, max_unit_length+1);
		the_unit[strlen(new_unit)] = '\0';

		the_onhand = new_onhand;
		the_needed = new_needed;
		the_pretax = new_pretax;
		the_taxable = new_taxable;

		name(new_name);													// call name() function to deep copy product name
	}

	Product::Product(const Product & src) {								// This constructor receives an unmodifiable reference to a Product object and copies the object referenced to the current object. 
		if (src.the_name != nullptr) {
			the_name = nullptr;
			*this = src;												// call overloaded assignment operator 
		}
	}

	Product::~Product() {
		delete[] the_name;
		prod_es.clear();
	}

	Product & Product::operator=(const Product & src) {					// This operator receives an unmodifiable reference to a Product object and replaces the current object with a copy of the object referenced. 
		if (this != &src) {
			strncpy(the_sku, src.the_sku, max_sku_length+1);
			the_sku[strlen(src.the_sku)] = '\0';

			strncpy(the_unit, src.the_unit, max_unit_length+1);
			the_unit[strlen(src.the_unit)]= '\0';

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
		file << the_type << ',' << the_sku << ',' << the_name << ',' << the_unit << ',' << the_taxable << "," << the_pretax << "," << the_onhand << "," << the_needed;
		if (newLine)
			file << endl;
		return file;
	}

	std::fstream & Product::load(std::fstream & file) {
		char new_sku[max_sku_length];
		char new_name[max_name_length];
		char new_unit[max_unit_length];
		char tax;
		int new_onhand;
		int new_needed;
		double new_pretax;
		bool new_taxable;

		if (file.is_open())
		{
			file.getline(new_sku, max_sku_length, ',');			// get characters up to delimiter of ,
			new_sku[strlen(new_sku)] = '\0';

			file.getline(new_name, max_name_length, ',');
			new_name[strlen(new_name)] = '\0';

			file.getline(new_unit, max_unit_length, ',');
			new_unit[strlen(new_unit)] = '\0';

			file >> tax;

			if (tax == '1')							// dumpFile uses cout.put which is unformatted output
				new_taxable = true;
			else if (tax == '0')
				new_taxable = false;

			file.ignore();

			file >> new_pretax;
			file.ignore();

			file >> new_onhand;
			file.ignore();

			file >> new_needed;
			file.ignore();

			*this = Product(new_sku, new_name, new_unit, new_onhand, new_taxable, new_pretax, new_needed);
		}
		return file;
	}

	std::ostream & Product::write(std::ostream & os, bool linear) const {
		if (prod_es.isClear()) {
			if (linear) {																		// If the bool parameter is true, the output is on a single line with the field widths 
				os << setw(max_sku_length) << left << sku() << "|"
					<< setw(20) << left << name() << "|"
					<< setw(7) << fixed << setprecision(2) << right << cost() << "|"
					<< setw(4) << right << quantity() << "|"
					<< setw(10) << left << unit() << "|"
					<< setw(4) << right << qtyNeeded() << "|";
			}
			else {																				// If the bool parameter is false, this function inserts the fields on separate lines 
				os << " Sku: " << sku() << endl
					<< " Name (no spaces): " << name() << endl
					<< " Price: " << price() << endl
					<< " Price after tax: ";

				if (taxed())
					os << cost() << endl;
				else
					os << "N/A" << endl;
				os << " Quantity on Hand: " << quantity() << " " << unit() << endl
					<< " Quantity needed: " << qtyNeeded();
			}
		}
		else {
			os << prod_es.message();
		}
		return os;
	}

	std::istream & Product::read(std::istream & is) {
		
		char *new_name = new char[max_name_length + 1];
		char tax_input;
		is.clear();

		cout << " Sku: ";
		is >> the_sku;

		cout << " Name (no spaces): ";
		is >> new_name;
		name(new_name);

		cout << " Unit: ";
		is >> the_unit;

		cout << " Taxed? (y/n): ";
		is >> tax_input;
		if (tax_input == 'Y' || tax_input == 'y')
			the_taxable = true;
		else if (tax_input == 'N' || tax_input == 'n')
			the_taxable = false;
		else {
			prod_es.message("Only (Y)es or (N)o are acceptable");
			is.setstate(ios::failbit);														// apparently have to set failbit and return the istream object each time 
			return is;
		}

		if (!is.fail()) {
			cout << " Price: ";
			is >> the_pretax;
			if (is.fail()) {
				prod_es.message("Invalid Price Entry");
				is.setstate(ios::failbit);
				return is;
			}
		}

		if (!is.fail()) {
			cout << " Quantity on hand: ";
			is >> the_onhand;
			if (is.fail()) {
				prod_es.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}
		}

		if (!is.fail()) {
			cout << " Quantity needed: ";
			is >> the_needed;
			cin.ignore();
			if (is.fail()) {
				prod_es.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				return is;
			}
		}
		prod_es.clear();
		return is;
	}

	bool Product::operator==(const char * new_name) const {
		if (strcmp(new_name, this->the_sku) == 0)
			return true;
		else
			return false;
	}

	double Product::total_cost() const {
		double total_cost = (the_pretax * (1 + TAX)) * quantity();
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

	bool Product::operator>(const iProduct & src) const {
		if (strcmp(the_name, src.name()) > 0)
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

	std::ostream & operator<<(std::ostream & os, const iProduct & src) {
		return src.write(os, true);
	}

	std::istream & operator>>(std::istream & is, iProduct & src) {
		src.read(is);
		return is;
	}

	double operator+=(double & total, const Product & src) {
		return total + src.total_cost();
	}
}