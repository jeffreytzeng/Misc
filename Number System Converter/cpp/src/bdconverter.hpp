#ifndef BDCONVERTER
#define BDCONVERTER

#include <string>

class BDConverter
{
	public:
		BDConverter(std::string s = "");
		void GetInput(std::string);
		bool IsDecimal();
		void ShowB2D();
		void ShowD2B();

	private:
		std::string str_;
};

#endif