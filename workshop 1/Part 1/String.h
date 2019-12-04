#ifndef _STRING_H
#define _STRING_H

#include <stdio.h>
#include <iostream>
#include <string>


namespace sict{

class String {

    char str[4];

    public:

    String(const char* c);

    void display(std::ostream& os);

};

std::ostream& operator<<(std::ostream& os, String& s);

}

#endif