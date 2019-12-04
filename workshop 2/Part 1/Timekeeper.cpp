//*************************************************************************
//// OOP345  Workshop 2 in-lab  Name Salley Jeong
//// // File: Timekeeper.cpp
//// // Version: Final
//// // Date: February 1st 2019
//// // Author: Salley Jeong
//// // Description: Workshop 2, in-lab portion, Timekeeper.cpp file
//// // Revision History
//// // ------------------`-----------------------------------------
//// // Name            Date            Reason
//// // Salley          2019-02-01      Added Comment Block 
//// *************************************************************************/

#include "Timekeeper.h"
#include <chrono>
#include <cstring>
#include <iostream>

 using namespace sict;

    Timekeeper::Timekeeper(){

    noOfRec=0;

    }

    void Timekeeper::start(){

    startTime=std::chrono::steady_clock::now();

    }

    void Timekeeper::stop(){

    endTime=std::chrono::steady_clock::now();

    }

    void Timekeeper::recordEvent(const char * eventDesc){
    
    strcpy(rec[noOfRec].message,eventDesc);

    rec[noOfRec].dur=std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime);

    strcpy(rec[noOfRec].timeunit," seconds");

    noOfRec++;

    }

    void Timekeeper::report(std::ostream & os){
      
    os <<"Execution Times:";
    for(int i=1;i<noOfRec;i++){
    os<<rec[i].message << rec[i].dur.count() << rec[i].timeunit;

    }
    
    }
    