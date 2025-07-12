#pragma once 

#include "Task.h"

namespace engine
{
    class Consumer : public Task
    {
    public:
        explicit Consumer(LogQueue& queue);
        void Run() override;
    };
}