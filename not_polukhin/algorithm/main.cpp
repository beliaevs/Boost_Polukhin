#include<boost/algorithm/searching/boyer_moore.hpp>
#include<string>
#include<iostream>

int main()
{
    std::cout << "Hello!\n";
    std::string needle("hello");
    std::string haystack("Every step you take, every move you make (hello) I'll be watching you");
    boost::algorithm::boyer_moore finder(needle.cbegin(), needle.cend());
    auto [first, last] = finder(haystack);
    std::cout << haystack << "\n";
    const auto pos1 = first - haystack.cbegin();
    for(auto i = 0; i < pos1; ++i)
        std::cout << " ";
    std::cout << "^";
    for(auto i = 1; i < last - first; ++i)
        std::cout << " ";
    std::cout << "^\n";
    return 0;
}