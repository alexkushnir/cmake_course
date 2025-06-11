#pragma once 

#include "Task.h"

#include <chrono>

namespace engine
{
    class Producer : public Task
    {
    public:
        explicit Producer(const std::chrono::milliseconds interval, LogQueue& queue);
        void Run() override;
    
    private:
        std::chrono::milliseconds m_interval;
    };
}