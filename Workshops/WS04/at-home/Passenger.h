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
		int y_dep;
		int m_dep;
		int d_dep;

	public:
		Passenger();
		Passenger(const char * pass, const char * dest);
		Passenger(const char * pass, const char * dest, int year, int month, int day);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}

#endif