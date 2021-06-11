#include<iostream>
#include<boost/stacktrace.hpp>

void call()
{
	std::cout <<"call\n";
	boost::stacktrace::stacktrace();
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

