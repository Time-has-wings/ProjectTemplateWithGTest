#include "ExexutorImple.hpp"
#include <new>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return pose;
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto &command : commands)
        {
            if (command == 'M')
            {
                switch (pose.heading)
                {
                case 'N':
                    pose.y += 1;
                    break;
                case 'S':
                    pose.y -= 1;
                    break;
                case 'E':
                    pose.x += 1;
                    break;
                case 'W':
                    pose.x -= 1;
                    break;
                default:
                    break;
                }
            }
        }
    }
}