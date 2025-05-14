#pragma once

#include "Producer.h"
#include "Consumer.h"
#include "Queue.h"

namespace engine
{
    class Engine
    {
        Engine();

        void Shutdown();

    private:
        LogQueue m_queue;
        Producer m_producer;
        Consumer m_consumer;        
    };
}