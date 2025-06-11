#include "Queue.h"

using namespace std::chrono_literals;

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
        if (m_readySemaphore.try_acquire_for(2s))
        {
            std::scoped_lock l(m_lock);
        
            auto message = m_queue.front();
            m_queue.pop();
        
            return message;
        }      
        else
        {
            return protocol::LogMessage{ protocol::LogMessage::LogSeverity::FATAL, "Timeout occured!" };
        }
    }
}