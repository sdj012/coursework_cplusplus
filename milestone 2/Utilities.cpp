//*************************************************************************
//// OOP345  Milestone 1 Name Salley Jeong
//// // File: Utilities.cpp
//// // Version: 1
//// // Date: April 8th 2019
//// // Author: Salley Jeong
//// // Description: Milestone 1 Utilities.cpp file
//// // Revision History
//// // -----------------------------------------------------------
//// // Name            Date            Reason
//// // Salley Jeong       2019-04-08      Added Comment Block 
//// *************************************************************************

#include <string>
#include "Utilities.h"

namespace sict {

size_t Utilities::fwidth = 0;
char Utilities::delimiter = '|';


Utilities::Utilities() {};

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {

   std::string temp="";

	if (str.size() > next_pos) {
      temp = str.substr(next_pos, str.find(delimiter, next_pos) - next_pos);
    }
    else { 
      temp = "";
    }
    
    if (str.find(delimiter,next_pos) != std::string::npos) {
      next_pos = str.find(delimiter,next_pos) + 1;
    } 
    else {
      next_pos = std::string::npos;
    }

    if (temp.size() == 0) { throw "No token"; }

    return temp;

}

const char Utilities::getDelimiter() const {
	return delimiter;
}

size_t Utilities::getFieldWidth() const {
	return fwidth;
}

void Utilities::setDelimiter(const char d) {
	delimiter = d;
}

void Utilities::setFieldWidth(size_t fw) {
	fwidth = fw;
}

}