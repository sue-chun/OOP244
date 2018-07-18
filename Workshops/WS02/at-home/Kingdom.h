/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

#ifndef OOP244_KINGDOM_H
#define OOP244_KINGDOM_H


// TODO: sict namespace
namespace sict {
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population = 0;
	};
	// TODO: declare the function display(...),
	void display(const Kingdom& x);
	//         also in the sict namespace
	// overload display function
	void display(Kingdom const *kingdoms, int n);
}
#endif