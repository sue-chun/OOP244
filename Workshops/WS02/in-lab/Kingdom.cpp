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
using namespace std;

#include "Kingdom.h"

// TODO: the sict namespace
namespace sict {

	// TODO:definition for display(...) 
	void display(const Kingdom& x) {
		cout << x.m_name << ", population " << x.m_population << endl;
	}
}