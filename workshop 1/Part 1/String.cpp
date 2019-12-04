#include "String.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "w1.h"

namespace sict{

int itemnum = INITIAL; 

String::String(const char* c){

    if (c==nullptr) str[0]='\0';
    else strcpy (str,c);
    }

void String::display(std::ostream& ostr) {
		ostr << str;
	}

std::ostream& operator<<(std::ostream& ostr, String& s) {
ostr << itemnum<< ": ";
s.display(ostr);
itemnum++;
return ostr;
}
}

