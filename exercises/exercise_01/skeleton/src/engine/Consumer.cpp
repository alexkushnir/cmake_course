#include "Consumer.h"

#include <print>
#include <iostream>
#include <format>

namespace engine
{
    Consumer::Consumer(LogQueue& queue)
        : Task{ queue }
    {}
    
    void Consumer::Run()
    {
        m_runner = std::jthread([&](std::stop_token stopToken) {
            
            while (!stopToken.stop_requested())
            {
                auto message = m_queue.Dequeue();
                std::println("Received {}", message);
            }
        });
    }
}