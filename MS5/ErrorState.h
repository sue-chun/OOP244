// Sue Ming Chun
// 032343154

#ifndef AMA_ERROR_STATE_H
#define AMA_ERROR_STATE_H
#include <iostream>
#include <cstring>
#include <string>

namespace AMA {
	class ErrorState {
		char* the_message;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	// helper operator
	std::ostream& operator<<(std::ostream& os, const ErrorState& em);
}
#endif