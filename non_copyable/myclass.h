#pragma once
#include<string>
#include<boost/noncopyable.hpp>

class MyClass
{
public:
	MyClass() = default;
	explicit MyClass(std::string i_str): d_name(std::move(i_str))
	{}
	MyClass(const MyClass&) = delete;
	MyClass& operator = (const MyClass&) = delete;
	std::string name() const 
	{
		return d_name;
	}

private:
	std::string d_name = "Default Name";
};

class MyClass2 : boost::noncopyable
{
public:
	MyClass2() = default;
	explicit MyClass2(std::string i_str) : d_name(std::move(i_str))
	{}
	std::string name() const
	{
		return d_name;
	}

private:
	std::string d_name = "Default Name";
};