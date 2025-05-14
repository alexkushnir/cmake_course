#include "Producer.h"

#include <print>
#include <iostream>
#include <format>

namespace engine
{
    Producer::Producer(const std::chrono::milliseconds interval, LogQueue& queue)
        : Task{ queue }
        , m_interval{ interval }
    {}
    
    void Producer::Run()
    {
        m_runner = std::jthread([&](std::stop_token stopToken) {
            static std::uint32_t counter{ 0 };
            while (!stopToken.stop_requested())
            {
                auto start = std::chrono::high_resolution_clock::now();

                protocol::LogMessage lm{ protocol::LogMessage::LogSeverity::INFO, std::format("Sending message with counter {}", ++counter) };
                std::println("Sending {}", lm);
                m_queue.Enqueue(lm);
                auto end = std::chrono::high_resolution_clock::now();
                    
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                std::this_thread::sleep_for(m_interval - duration);
            }
        });
    }
}