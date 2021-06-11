#include<iostream>
#include<boost/stacktrace.hpp>

void call()
{
	std::cout <<"call\n";
	std::cout << boost::stacktrace::stacktrace();
}

void f()
{
	call();
}

int main()
{
	f();
	return 0;
}

