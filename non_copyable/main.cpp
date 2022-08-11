#include<iostream>
#include<boost/version.hpp>
#include "myclass.h"

int main()
{
	std::cout << "Boost version: " << BOOST_LIB_VERSION << "\n";
	MyClass myclass("hello!");
	MyClass a;
	std::cout << myclass.name() << ", " << a.name() << "\n";
	//a = myclass;

	MyClass2 myclass2("bye!");
	std::cout << myclass2.name() << "\n";
	MyClass2 c;
	//c = myclass2;
	//MyClass2 b(myclass2);
	//std::cout << b.name() << "\n";

}