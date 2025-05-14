#include "Queue.h"

namespace engine
{
    LogQueue::LogQueue()
        : m_readySemaphore{ 0 }
    {}

    void LogQueue::Enqueue(const protocol::LogMessage& message)
    {
        std::scoped_lock l(m_lock);
        m_queue.push(message);
        m_readySemaphore.release();
    }
        
    protocol::LogMessage LogQueue::Dequeue()
    {
        m_readySemaphore.acquire();
        
        std::scoped_lock l(m_lock);
        
        auto message = m_queue.front();
        m_queue.pop();
        
        return message;
    }
}