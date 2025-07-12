#pragma once 

#include "../protocol/LogMessage.h"

#include <queue>
#include <mutex>
#include <semaphore>

namespace engine
{
    class LogQueue
    {
    public:
        LogQueue();
        void Enqueue(const protocol::LogMessage& message);
        protocol::LogMessage Dequeue();

    private:
        std::queue<protocol::LogMessage> m_queue;
        std::mutex m_lock;
        std::binary_semaphore m_readySemaphore;
    };
}