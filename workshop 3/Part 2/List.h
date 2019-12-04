//**********************************************
//OOP345 Workshop 3 at-home Name: Salley Jeong
//File: List.h
//Version: Final
//Date: February 9th 2019
//Author: Salley Jeong
//Description: Workshop 3, at-home portion
//***********************************************

namespace sict {

 template <typename T, size_t N>
 class List {
     T a[N];
     size_t num = 0u;

    public:

    size_t size() const{
    return num;
    }

    const T& operator[](size_t i)const{
    return a[i];
    }

    void operator+=(const T& t){
    if(size()<N)  a[num++] = t;
    }   
 };
template<typename T,typename L, typename V, size_t N>
class LVList : public List<T,N>{

public:
V accumulate(const L& label) const{
SummableLVPair<L,V> temp;
V local=temp.getInitialValue();
size_t localSize=((List<T, N>&)*this).size();

for (size_t i=0;i<localSize;i++){
    temp=((List<T, N>&)*this)[i];
    local=temp.Sum(label,local);
}
return local;
}
};
}
