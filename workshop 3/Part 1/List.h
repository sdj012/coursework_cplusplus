//List.h - defines a class template for a list of elements of any data type (for example, a list of ints)
namespace sict {

 template <typename T, size_t N>
 class List {
     T a[N];
     size_t num;

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

}