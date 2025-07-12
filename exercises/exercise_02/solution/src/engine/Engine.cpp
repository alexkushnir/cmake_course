#include "Engine.h"

namespace engine
{
    Engine::Engine()
        : m_producer{ std::chrono::milliseconds{ 1000 }, m_queue }
        , m_consumer{ m_queue }
    {
        m_producer.Run();
        m_consumer.Run();
    }

    void Engine::Shutdown()
    {
        m_producer.Stop();
        m_consumer.Stop();
    }
}