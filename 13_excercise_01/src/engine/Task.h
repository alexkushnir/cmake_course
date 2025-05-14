#pragma once 

#include "../protocol/LogMessage.h"
#include "Queue.h"

#include <thread>
#include <queue>
#include <mutex>

namespace engine
{
    class Task
    {
    public:
        explicit Task(LogQueue& queue);
        void Stop();
        virtual void Run() = 0;

    protected:
        std::jthread m_runner;
        LogQueue& m_queue;
    };
}