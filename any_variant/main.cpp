#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <any>
#include <variant>

void boost_variant_test()
{
    using my_var_t = boost::variant<int, const char*, std::string>;
    using my_nullable_t = boost::variant<boost::blank, int>;
    my_nullable_t n;
    assert(n.which() == 0);
    std::vector<my_var_t> some_values;
    some_values.push_back(10);
    some_values.push_back("Hello there!");
    some_values.push_back(std::string("Wow!"));
    std::string& s = boost::get<std::string>(some_values.back());
    s += " That is great!\n";
    std::cout << s << "\n";
    my_var_t x;
    std::cout << "x is empty? " << x.empty() << "\n";
}

void std_variant_test()
{
    using my_var_t = std::variant<int, const char*, std::string>;
    my_var_t x;
    std::cout << "std index: " << x.index() << "\n";
    assert(x.index() == 0);
    x = std::string("Hi!");
    auto s = std::get_if<std::string>(&x);
    std::cout << *s << "\n";
}

void boost_any_test()
{
    std::vector<boost::any> some_values;
    some_values.push_back(10);
    some_values.push_back("Hello there!");
    some_values.push_back(std::string("Wow!"));
    std::string& s = boost::any_cast<std::string&>(some_values.back());
    s += " That is great!";
    std::cout << s << "\n";

    boost::any variable(std::string("Hello world!"));
    // Following method may throw a boost::bad_any_cast exception
    // if actual value in variable is not a std::string.
    std::string s1 = boost::any_cast<std::string>(variable);
    // Never throws. If actual value in variable is not a std::string
    // will return an NULL pointer.
    std::string* s2 = boost::any_cast<std::string>(&variable);
    if(s2)
        std::cout << s2 << "\n"; 
    std::cout << s1 << "\n";
}

void std_any_test()
{
    std::any x{2.67};
    boost::any y{3};
    std::cout << "std::any has value?" << x.has_value() << "\n";
    x.reset();
    std::cout << "reset. std::any has value? " << x.has_value() << "\n";
    std::cout << "boost::any is empty: " << y.empty() << "\n";
    y.clear();
    std::cout << "clear. boost::any is empty: " << y.empty() << "\n";
}

int main() 
{
    boost_any_test();
    std_any_test();
    boost_variant_test();
    std_variant_test();
}