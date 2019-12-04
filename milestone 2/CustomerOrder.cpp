#include "CustomerOrder.h"

namespace sict {

  CustomerOrder::CustomerOrder() {}

  CustomerOrder::CustomerOrder(const std::string& str) {

    size_t next_pos= 0 ;

    custName = utilities.extractToken(str, next_pos);

    if (custName.size() > utilities.getFieldWidth()) {
      utilities.setFieldWidth(custName.size());
    }

    if (next_pos <= str.size()) {
      prdName = utilities.extractToken(str, next_pos);
    }

    while (next_pos <= str.size()) {

      ItemInfo* temp;
      temp = new ItemInfo[quantity];
      for (size_t i = 0; i < quantity; i++) { temp[i] = itemArray[i]; }
      delete[] itemArray;
      itemArray= new ItemInfo [++quantity];
      for (size_t i = 0; i < quantity - 1; i++) { itemArray[i] = temp[i]; }
      delete[] temp;
      itemArray[quantity - 1].itemName = utilities.extractToken(str, next_pos);

    }
  }

  CustomerOrder::CustomerOrder(CustomerOrder&& src) { 
    if (this != &src) {
    *this = std::move(src);
    }

  }

  CustomerOrder::~CustomerOrder() {
      delete[]itemArray; 
  }

  void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {

    for (size_t i = 0; i < quantity; i++) {

      if (item.getName() == itemArray[i].itemName) {

        if (item.getQuantity() > 0 && itemArray[i].fillStatus == false) {

          itemArray[i].fillStatus = true;
          itemArray[i].itemSerial  = item.getSerialNumber();

          if (item.getQuantity() > 0) --item;

          os << " Filled " << custName << " [" << prdName << "][" << itemArray[i].itemName << "][" << itemArray[i].itemSerial  << ']' << std::endl;;
        }

        else if (item.getQuantity() > 0 && itemArray[i].fillStatus) {
          os << " Unable to fill " << custName << " [" << prdName << "][" << itemArray[i].itemName << "][" << itemArray[i].itemSerial  << "] already filled" << std::endl;;
        }

        else {
          os << " Unable to fill " << custName << " [" << prdName << "][" << itemArray[i].itemName << "][" << itemArray[i].itemSerial  << "] out of stock" << std::endl;
        }
      }
    }
  }

  bool CustomerOrder::isFilled() const {

    int allFilled=1;

    for (size_t i = 0; i < quantity; i++) {
      allFilled *= static_cast<int>(itemArray[i].fillStatus);
    }

    return static_cast<bool>(allFilled);
  }

  bool CustomerOrder::isItemFilled(const std::string& item) const {

    int allFilled=1;

    for (size_t i = 0; i < quantity; i++) {

      if (itemArray[i].itemName == item) {
        allFilled *= static_cast<int>(itemArray[i].fillStatus);
      }

    }

    return static_cast<bool>(allFilled);
  }

  std::string CustomerOrder::getNameProduct() const {

    std::string nameProduct = custName + " [" + prdName + ']';

    return nameProduct;

  }

  void CustomerOrder::display(std::ostream& os, bool showDetail) const {

    if (!showDetail) {

      os.width(utilities.getFieldWidth());
      os << custName;
      os << " [" << prdName << ']' << std::endl;

      if (quantity > 0) {

        for (size_t i = 0; i < quantity; i++) {

          for (size_t i = 0; i < utilities.getFieldWidth()+1; i++) { os << ' '; }

          os << itemArray[i].itemName << std::endl;
        }
      }
    }
    
    else {

      os.width(utilities.getFieldWidth());
      os << custName;
      os << " [" << prdName << ']' << std::endl;

      if (quantity > 0) {

        for (size_t i = 0; i < quantity; i++) {

          for (size_t i = 0; i < utilities.getFieldWidth()+1; i++) { os << ' '; }

          os << '[' << itemArray[i].itemSerial  << "] " << itemArray[i].itemName;
          os << " - " << (itemArray[i].fillStatus ? "FILLED" : "MISSING") << std::endl;
        }
      }
    }
  }

  CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {

    if (this != &src) {

      delete[] itemArray;
      itemArray = nullptr;
      custName = src.custName;
      prdName = src.prdName;
      quantity = src.quantity;
      itemArray = src.itemArray;
      src.custName = "";
      src.prdName = "";
      src.quantity = 0;
      src.itemArray = nullptr;

    }
    return *this;

  }


}