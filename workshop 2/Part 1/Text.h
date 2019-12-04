//*************************************************************************
//// OOP345  Workshop 2 in-lab  Name Salley Jeong
//// // File: Text.h
//// // Version: Final
//// // Date: February 1st 2019
//// // Author: Salley Jeong
//// // Description: Workshop 2, in-lab portion, Text.h file
//// // Revision History
//// // -----------------------------------------------------------
//// // Name            Date            Reason
//// // Salley          2019-02-01      Added Comment Block 
//// *************************************************************************/

#ifndef SICT_TEXT_H_
#define SICT_TEXT_H_

#include <string>

namespace sict{

class Text{

    std::string * TheTextLines;

    int numOfLines;

public: 

Text(){

TheTextLines=nullptr;
numOfLines=0;
    
}

Text(const char *);

Text (const Text&); 

Text (Text&&); 

Text& operator=(const Text&);

Text& operator=(Text&&);

size_t size() const;

~Text();

};

}
#endif