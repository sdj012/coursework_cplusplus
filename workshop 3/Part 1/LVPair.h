#include <string.h>

namespace sict {

 template <typename L, typename V>
 class LVPair {
    L Merchlabel;
    V quantity;

    public:

    LVPair():Merchlabel(),quantity(){};

    LVPair(const L& label, const V& value):Merchlabel(label),quantity(value){};

    void display(std::ostream& os) const {
      os << Merchlabel << " : " << quantity << std::endl;
    }
   };

   template <typename L, typename V>
    std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair){

      pair.display(os);
      return os;
    }
 }