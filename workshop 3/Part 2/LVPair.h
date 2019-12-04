//******************************************
//OOP345 Workshop 3 at-home Name:Salley Jeong
//File:LVPair.h
//Version:Final
//Date: February 9th 2019
//Author: Salley Jeong
//Description: Workshop 3, at - home portion
//***************************************** 

#include <string>
#include <iostream>

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

    L get_label() const {
      return Merchlabel;
    }

    V get_value() const {
      return quantity;
    }

  };

  template <typename L, typename V>
  std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair){
    pair.display(os);
    return os;
  }

  template<typename L, typename V, size_t de_w=0u>
  class SummableLVPair : public LVPair<L,V>{
    inline static V initial;
    inline static size_t fwidth=de_w;

  public:
  
  SummableLVPair(){}

  SummableLVPair(const L& label,const V& value):LVPair<L,V>(label,value){

    if (fwidth<label.size()){
      fwidth=label.size();
    }
  }

  const V& getInitialValue(){
    return initial;
  }

  V Sum(const L& l, const V& v){
    V local = v;
    if(l==LVPair<L,V>::get_label()){
      local= v+LVPair<L,V>::get_value();
    }
    return local;
  }

  void display(std::ostream & os)const{
    os<<std::left;
    os.width(fwidth);
    LVPair<L,V>::display(os);
  }
};

// Specialization for default constructor
// of Summable of types string and int
template<>
SummableLVPair<std::string,int>::SummableLVPair():LVPair<std::string,int>() {
  initial=0;
};

// Specialization for parameterized constructor
// of Summable of types string and int
template<>
SummableLVPair<std::string,int>::SummableLVPair(const std::string& l, const int& v):
  LVPair<std::string,int>(l,v){
    initial = 0;
};

// Specialization for default constructor
// of Summable of types string and string
template<>
SummableLVPair<std::string,std::string>::SummableLVPair():LVPair<std::string,std::string>(){
  initial="";
};

// Specialization for parameterized constructor
// of Summable of types string and string
template<>
SummableLVPair<std::string,std::string>::SummableLVPair(const std::string& l, const std::string& v):
  LVPair<std::string,std::string>(l,v){
    initial = "";
  };

// Specialization for Sum with type string and string
template<>
std::string SummableLVPair<std::string,std::string>::Sum(const std::string& l, const std::string& v){
  std::string local = v;
  if(l==LVPair<std::string,std::string>::get_label()){
    local= v+" "+LVPair<std::string,std::string>::get_value();
  }
  return local;
}
}