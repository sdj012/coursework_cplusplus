//*************************************************************************
//// OOP345  Milestone 1 Name Salley Jeong
//// // File: ItemSet.h
//// // Version: 1
//// // Date: April 8th 2019
//// // Author: Salley Jeong
//// // Description: Milestone 1 ItemSet.h file
//// // Revision History
//// // -----------------------------------------------------------
//// // Name            Date            Reason
//// // Salley Jeong       2019-04-08      Added Comment Block 
//// *************************************************************************

#include "Utilities.h"

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

namespace sict {

class ItemSet{

	std::string name="";
	unsigned sernum=0;
	unsigned int quantity=0;
	std::string desc="";

public:

	ItemSet(std::string& f_str);						
	const std::string& getName() const;				
	const unsigned int getSerialNumber();			
	const unsigned int getQuantity();				
    ItemSet& operator--();
	void display(std::ostream& os, bool full) const;
	ItemSet(const ItemSet&) = delete;
    ItemSet(ItemSet&&);
	ItemSet& operator=(const ItemSet&) = delete;
    ItemSet&& operator=(ItemSet&&) = delete;

};

}

#endif 