#pragma once
#include <string>

namespace adas
{
    struct Pose
    {
        int x;
        int y;
        char heading;
    };

    class Executor
    {
    public:
        static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;
        Executor(void) = default;
        virtual ~Executor(void) = default;
        // 不允许拷贝构造
        Executor(const Executor &) = delete;
        // 不允许拷贝赋值
        Executor &operator=(const Executor &) = delete;

        virtual Pose Query(void) const noexcept = 0;
        virtual void Execute(const std::string &commands) noexcept = 0;
    };
}