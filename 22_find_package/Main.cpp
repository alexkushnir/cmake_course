#include <boost/timer/timer.hpp>
#include <print>

int main()
{
    boost::timer::auto_cpu_timer t1;

    for (auto i = 0; i < 100000; ++i)
    {
        std::println("Index is {}", i);
    }

    return 0;
}
