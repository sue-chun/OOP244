/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;


// TODO: the sict namespace
namespace sict {

	// TODO:definition for display(...) 
	void display(const Kingdom& x) {
		cout << x.m_name << ", population " << x.m_population << endl;
	}
	void display(Kingdom const *kingdoms, int n) {
		int sum = 0;
		cout << "------------------------------" << endl
			<< "Kingdoms of SICT" << endl
			<< "------------------------------" << endl;
		
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << kingdoms[i].m_name << ", population "			// list out the element m_name in kingdoms array index i 
				 << kingdoms[i].m_population << endl;								// list out the element m_population in kingdoms array index i
			sum += kingdoms[i].m_population;										// get total of population in kingdom 
		}

		cout << "------------------------------" << endl
			<< "Total population of SICT: " << sum << endl
			<< "------------------------------" << endl;


	}
}