#pragma once 

#include <efsw/efsw.hpp>

// Inherits from the abstract listener class, and implements the the file action handler
class UpdateListener : public efsw::FileWatchListener 
{
public:
    void handleFileAction(efsw::WatchID watchid, const std::string& dir,
                           const std::string& filename, efsw::Action action,
                           std::string oldFilename ) override;
};

