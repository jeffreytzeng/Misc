#include <iostream>
#include "bdconverter.hpp"
using namespace std;

int main()
{
	string input = "";
	cin >> input;

	BDConverter *bd = new BDConverter(input);
	[&](BDConverter *b) { b->IsDecimal() ? b->ShowD2B() : b->ShowB2D();}(bd);
	delete bd;
}