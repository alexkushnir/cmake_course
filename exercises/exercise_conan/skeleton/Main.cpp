#include"FileListener.h"
#include <memory>
#include <semaphore>

// Handle Ctrl + C 
#include <signal.h>

std::binary_semaphore sem(0);

void CtrlCHandler([[maybe_unused]] int dummy)
{
    sem.release();
}

int main()
{
    // Register Ctrl + C handler
    signal(SIGINT, CtrlCHandler);

    // Setup the directory watcher
    auto fileWatcher = std::make_unique<efsw::FileWatcher>();
    auto listener = std::make_unique<UpdateListener>();
    auto watchID = fileWatcher->addWatch( "/tmp", listener.get(), true );
    fileWatcher->watch();
    
    // Wait for stop
    sem.acquire();    
       
    fileWatcher->removeWatch(watchID);

    return 0;
}