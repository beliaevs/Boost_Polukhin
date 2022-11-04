#include<iostream>
#include<boost/utility/base_from_member.hpp>

class MyBase
{
    public:
    explicit MyBase(int n): d_n(n){}
    int d_n;
};

class OtherBase
{
    public:
    explicit OtherBase(int& n): d_n(n)
    {
    }
    
    int get_n() const
    {
        return d_n;
    }
    private:
    int& d_n;
};

class MostDerived: private boost::base_from_member<MyBase>, public OtherBase
{
    public:
    explicit MostDerived(int n): IntData(n), OtherBase(IntData::member.d_n)
    {} 

    private:
    using IntData = boost::base_from_member<MyBase>;
};

int main()
{
    MostDerived d(42);
    std::cout << d.get_n() << "\n";
    return 0;
}