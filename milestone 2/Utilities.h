//*************************************************************************
//// OOP345  Milestone 1 Name Salley Jeong
//// // File: Utilities.h
//// // Version: 1
//// // Date: April 8th 2019
//// // Author: Salley Jeong
//// // Description: Milestone 1 Utilities.h file
//// // Revision History
//// // -----------------------------------------------------------
//// // Name            Date            Reason
//// // Salley Jeong       2019-04-08      Added Comment Block 
//// *************************************************************************


#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <string>

namespace sict {

class Utilities {

	static size_t fwidth;           
	static char delimiter;        

public:

	Utilities();
	const std::string extractToken(const std::string& str, size_t& next_pos);
	const char getDelimiter() const;
    size_t getFieldWidth() const;
	static void setDelimiter(const char d);
    void setFieldWidth(size_t);
};

}

#endif