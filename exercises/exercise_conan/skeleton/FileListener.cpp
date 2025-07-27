#include "FileListener.h"
#include <print>

void UpdateListener::handleFileAction([[maybe_unused]] efsw::WatchID watchid, const std::string& dir,
                           const std::string& filename, efsw::Action action,
                           std::string oldFilename)
{
        switch (action) 
        {
            case efsw::Actions::Add:
                std::println("DIR ({}) FILE ({}) got event Add", dir, filename);
                break;
            case efsw::Actions::Delete:
                std::println("DIR ({}) FILE ({}) got event Delete", dir, filename);
                break;
            case efsw::Actions::Modified:
                std::println("DIR ({}) FILE ({}) got event Modified", dir, filename);
                break;
            case efsw::Actions::Moved:
                std::println("DIR ({}) FILE ({}) got event Moved from {}", dir, filename, oldFilename);
                break;
            default:
                std::println("Should never happen!");
        }
}
