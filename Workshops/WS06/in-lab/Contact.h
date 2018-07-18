// Sue Ming Chun 
// 032343154

#ifndef OOP244_CONTACT_H
#define OOP244_CONTACT_H

// TODO: create namespace
namespace sict {
	class Contact {
		char name[20];
		long long * pnumbers = nullptr;
		int num;
	public:
		Contact();
		Contact(const char*, const long long *, const int);
		bool isEmpty() const; 
		void display() const;
		bool isValid(const long long) const;
		~Contact();
	};
}

#endif