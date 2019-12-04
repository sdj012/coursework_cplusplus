//*************************************************************************
//// OOP345  Workshop 2 in-lab  Name Salley Jeong
//// // File: Timekeeper.h
//// // Version: Final
//// // Date: February 1st 2019
//// // Author: Salley Jeong
//// // Description: Workshop 2, in-lab portion, Timekeeper.h file
//// // Revision History
//// // -----------------------------------------------------------
//// // Name            Date            Reason
//// // Salley          2019-02-01      Added Comment Block 
//// *************************************************************************/


#ifndef SICT_TIMEKEEPER_H_
#define SICT_TIMEKEEPER_H_

#include <chrono>
#include <iostream>

namespace sict{

    const int MAX_RECS= 10;

    class Timekeeper{    

    int noOfRec;
    
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;

    struct{
        char * message =nullptr;
        char * timeunit=nullptr;
        std::chrono::steady_clock::duration dur;
        
    }rec[MAX_RECS];

    public:

    Timekeeper();
    void start();
    void stop();
    void recordEvent(const char * eventDesc);
    void report(std::ostream & os);
    };

}
#endif