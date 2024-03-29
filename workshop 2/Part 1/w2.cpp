//*************************************************************************
//// OOP345  Workshop 2 in-lab  Name Salley Jeong
//// // File: w2.cpp
//// // Version: Final
//// // Date: February 1st 2019
//// // Author: Salley Jeong
//// // Description: Workshop 2, in-lab portion, w2.cpp file
//// // Revision History
//// // -----------------------------------------------------------
//// // Name            Date            Reason
//// // Salley          2019-02-01      Added Comment Block 
//// *************************************************************************/

// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Chris Szalwinski
// 2019/01/10

#include <iostream>
#include <iomanip>
#include "Text.h"
#include "Timekeeper.h"
using namespace sict;

int main (int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	if (argc == 1) {
        std::cerr << argv[0] << ": missing file operand\n";
        return 1;
	}
	else if (argc != 2) {
        std::cerr << argv[0] << ": too many arguments\n";
        return 2;
    }

	Timekeeper t;
    {
        std::cout << std::fixed << std::setprecision(3);
		t.start();
        Text a;
		t.stop();
		t.recordEvent("0-arg Constructor");
        std::cout << "0-arg Constructor - a.size = " << a.size() << std::endl;

		t.start();
		Text b(argv[1]);
		t.stop();
		t.recordEvent("1-arg Constructor");
		std::cout << "1-arg Constructor - b.size = " << b.size() << std::endl;

		t.start();
		Text c = b;
		t.stop();
		t.recordEvent("Copy Constructor ");
        std::cout << "Copy Constructor  - c.size = " << c.size() << std::endl;

		t.start();
		a = b;
		t.stop();
		t.recordEvent("Copy Assignment  ");
        std::cout << "Copy Assignment   - a.size = " << a.size() << std::endl;

        t.start();
    }
    t.stop();
	t.recordEvent("Destructor       ");

	t.report(std::cout);
}