#include "Task.h"

namespace engine 
{
    Task::Task(LogQueue& queue)
        : m_queue{ queue }
    {}

    void Task::Stop()
    {
        m_runner.request_stop();
    }
}