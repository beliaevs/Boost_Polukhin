#include<iostream>
#include<boost/program_options.hpp>

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    // Constructing an options describing variable and giving
    // it a textual description "All options".
    opt::options_description desc("All options");
    // When we are adding options, first parameter is a name
    // to be used in command line. Second parameter is a type
    // of that option, wrapped in value<> class. Third parameter
    // must be a short description of that option.
    int apples_var = 0;
    int oranges_var = 0;
    desc.add_options()
        ("apples", opt::value<int>(&apples_var)->required(), "how many apples do you have")
        ("oranges", opt::value<int>(&oranges_var)->required(), "how many oranges do you have")
        ("help", "produce help message");

    // Variable to store our command line arguments.
    opt::variables_map vm;
    // Parsing and storing arguments.
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    try
    {
        // Must be called after all the parsing and storing.
        opt::notify(vm);
    }
    catch(const opt::required_option& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << desc << "\n";
        return 2;
    }

    if (vm.count("help")) 
    {
        std::cout << desc << "\n";
        return 1;
    }
    
    std::cout << "Fruits count: " << apples_var + oranges_var << std::endl;
    
    return 0;
}