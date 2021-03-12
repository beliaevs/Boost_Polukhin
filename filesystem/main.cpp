#include<boost/filesystem/operations.hpp>
#include<iostream>

int main()
{
    boost::filesystem::directory_iterator begin("./");
    boost::filesystem::directory_iterator end;

    for(; begin != end; ++begin)
    {
        auto fs = status(*begin);
        switch(fs.type())
        {
            case boost::filesystem::regular_file:
                std::cout << "FILE ";
                break;
            case boost::filesystem::symlink_file:
                std::cout << "SYMLINK ";
                break;
            case boost::filesystem::directory_file: 
                std::cout << "DIRECTORY ";
                break;
            default: 
                std::cout << "OTHER ";
                break;
        }
        if (fs.permissions() & boost::filesystem::owner_write) 
        {
            std::cout << "W ";
        } 
        else 
        {
            std::cout << " ";
        }
        std::cout << *begin << '\n';
    }
}

