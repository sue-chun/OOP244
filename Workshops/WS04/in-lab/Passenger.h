// TODO: add file header comments here
// Sue Ming Chun 
// 032343154

// TODO: add header file guard here
#ifndef OOP244_PASSENGER_H
#define OOP244_PASSENGER_H

// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here

	class Passenger {
		char PassName[32];
		char DestName[32];

	public:
		Passenger();
		Passenger(const char * pass, const char * dest);
		bool isEmpty() const;
		void display() const;
	};
}

#endif