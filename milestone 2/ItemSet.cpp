//*************************************************************************
//// OOP345  Milestone 1 Name Salley Jeong
//// // File: ItemSet.cpp
//// // Version: 1
//// // Date: April 8th 2019
//// // Author: Salley Jeong
//// // Description: Milestone 1 ItemSet.cpp file
//// // Revision History
//// // -----------------------------------------------------------
//// // Name            Date            Reason
//// // Salley Jeong       2019-04-08      Added Comment Block 
//// *************************************************************************


#include <iostream>
#include <string>
#include "Utilities.h"
#include "ItemSet.h"

namespace sict {


Utilities utility;

ItemSet::ItemSet(std::string& f_str) {

    size_t next_pos{0};

    name = utility.extractToken(f_str,next_pos);

    if (name.size() > utility.getFieldWidth()){
      utility.setFieldWidth(name.size());
    }

    if (next_pos <= f_str.size()) {
      sernum = std::stoul(utility.extractToken(f_str, next_pos));
    }
	
    if (next_pos <= f_str.size()) {
      quantity = std::stoul(utility.extractToken(f_str, next_pos));
    }

    if (next_pos <= f_str.size()) {
      desc = utility.extractToken(f_str, next_pos);
    }

}			

const std::string& ItemSet::getName() const {
	return name;
}

const unsigned int ItemSet::getSerialNumber() {
	return sernum;
}

const unsigned int ItemSet::getQuantity() {
	return quantity;
}

ItemSet& ItemSet::operator --() {

  this->quantity--;
  this->sernum++;

  return *this;
}

void ItemSet::display(std::ostream& os , bool full) const {

if (full) {
      os.width(utility.getFieldWidth());
      os << std::left;
      os.fill(' ');
      os << name;
      os << " [";
      os.fill('0');
      os.width(5);
      os << sernum;
      os.fill(' ');
      os << "] Quantity ";
      os << std::left;
      os.width(3);
      os << quantity;
      os << " Description: ";
      os << desc;
      os << std::endl;
}
  else {
      os.width(utility.getFieldWidth());
      os << std::left;
      os.fill(' ');
      os << name;
      os << " [";
      os.fill('0');
      os.width(5);
      os << sernum + 1 << ']';
      os << std::endl;
    }
}

ItemSet::ItemSet(ItemSet&& base) {
name = base.name;
sernum = base.sernum;
quantity = base.quantity;
desc = base.desc;
base.name = "";
base.sernum= 0;
base.quantity = 0;
}
  
}
