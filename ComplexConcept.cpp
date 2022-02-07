#include <iostream>
#include <string>

template<typename T> concept ComplexConcept =
!std::has_virtual_destructor<T>::value && requires (T t)
{   
    {t.hash()}->std::convertible_to<long>;
    {t.toString()}->std::same_as<std::string>;
};

struct A
{
  int I = 0;
  //virtual ~A() {};
  std::string toString() { return std::to_string(I); }
  int hash() { return 3; };
};

void print(ComplexConcept  auto & r) 
{
    std::cout << r.toString() << std::endl;
}


int main()
{
    A a{20};
    print(a);    
}