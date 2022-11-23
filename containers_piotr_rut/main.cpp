#include<iostream>
#include<boost/container/small_vector.hpp>
#include<boost/container/static_vector.hpp>
#include<boost/circular_buffer.hpp>
class Spy
{
    public:
    explicit Spy(int n): d_n(n) 
    {
        std::cout << "Spy(" << d_n << ")\n";
    }

    Spy(const Spy& other): d_n(other.d_n)
    {
        std::cout << "Spy copy(" << d_n << ")\n";
    }

    Spy& operator = (const Spy& i_other)
    {
        std::cout << "Spy(" << d_n << ") = Spy(" << i_other.d_n << ")\n";
        d_n = i_other.d_n;
        return *this;
    }

    ~Spy()
    {
        std::cout << "~Spy(" << d_n << ")\n";
    }

    int get() const
    {
        return d_n;
    }

    private:
    int d_n;
};

int main()
{
    {
        std::cout << "small vector\n";
        boost::container::small_vector<Spy, 4> v;
        std::cout << v.capacity() << "\n";
        v.emplace_back(1);
        std::cout << v.size() << ", " << v.capacity() << "\n";
        for(int i = 2; i < 8; ++i)
        {
            v.emplace_back(i);
        }
    }
    {
        std::cout << "static vector\n";
        boost::container::static_vector<Spy, 4> v;
        for(int i = 0; i < 4; ++i)
        {
            v.emplace_back(i);
        }
        try
        {
          v.emplace_back(5);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    {
        std::cout << "circular buffer\n";
        boost::circular_buffer<Spy> buf;
        buf.set_capacity(4);
        for(int i = 0; i != 5; ++i)
        {
            buf.push_back(Spy(i));
        }

        for(auto& a: buf)
        {
            std::cout << a.get() << "\n";
        }
    
    }
}