#include "../engine/Engine.h"

#include <thread>
#include <chrono>

using namespace std::literals;

int main()
{
    engine::Engine eng;
    std::this_thread::sleep_for(10s);
    
    eng.Shutdown();

    return 0;
}