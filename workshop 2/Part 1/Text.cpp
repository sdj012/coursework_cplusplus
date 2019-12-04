//*************************************************************************
//// OOP345  Workshop 2 in-lab  Name Salley Jeong
//// // File: Text.cpp
//// // Version: Final
//// // Date: February 1st 2019
//// // Author: Salley Jeong
//// // Description: Workshop 2, in-lab portion, Text.cpp file
//// // Revision History
//// // -----------------------------------------------------------
//// // Name            Date            Reason
//// // Salley          2019-02-01      Added Comment Block 
//// *************************************************************************/

#include "Text.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace sict;

Text::Text(const char * filename){

    int i=0;
    std::ifstream inFile(filename);
    std::string line;

    while(getline(inFile,line)){
        numOfLines++;
    }

    TheTextLines=new std::string [numOfLines];

    while(getline(inFile,line)){
    TheTextLines[i]=line;
    i++;
}

};

Text::Text (const Text & base){     
    *this=base;
}

Text::Text (Text && base){     
    *this=base;
}

Text& Text::operator=(const Text& base){
    numOfLines=base.numOfLines;

    if(this!=&base){
        delete[] TheTextLines;

        TheTextLines=new std::string[numOfLines];
        if(base.TheTextLines!=nullptr){
            for(int i=0;i<base.numOfLines;i++){
                TheTextLines[i]=base.TheTextLines[i];
            }
        }
    }
return *this;
}

Text& Text::operator=(Text&& base){
    if(this!=&base){
        delete TheTextLines;
        numOfLines=base.numOfLines;

        TheTextLines=new std::string[numOfLines];
        if(base.TheTextLines!=nullptr){
            for(int i=0;i<base.numOfLines;i++){
                TheTextLines[i]=base.TheTextLines[i];
            }
        }
       
        base.TheTextLines=nullptr;
       
        base.numOfLines=0;
    }
return *this;
}

Text::~Text(){
delete[] TheTextLines;
TheTextLines=nullptr;
}

size_t Text::size() const{
return numOfLines;
}