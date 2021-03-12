#include<boost/filesystem/operations.hpp>
#include<iostream>
#include<filesystem>

void stdfilesystem()
{
    std::cout << "std::filesystem:\n";
    std::filesystem::directory_iterator begin("./");
    std::filesystem::directory_iterator end;
    for(; begin != end; ++begin)
    {
        auto fs = begin->status();
        switch(fs.type())
        {
            case std::filesystem::file_type::regular:
                std::cout << "FILE ";
                break;
            case std::filesystem::file_type::symlink:
                std::cout << "SYMLINK ";
                break;
            case std::filesystem::file_type::directory: 
                std::cout << "DIRECTORY ";
                break;
            default: 
                std::cout << "OTHER ";
                break;
        }
        if ( (fs.permissions() & std::filesystem::perms::owner_write) != std::filesystem::perms::none ) 
        {
            std::cout << "W ";
        } 
        else 
        {
            std::cout << " ";
        }
        std::cout << begin->path() << '\n';
    }
}

int main()
{
    boost::filesystem::directory_iterator begin("./");
    boost::filesystem::directory_iterator end;

    for(; begin != end; ++begin)
    {
        auto fs = begin->status();
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
        std::cout << begin->path() << '\n';
    }

    stdfilesystem();
}

