#pragma once

namespace wd
{
    class Noncopyable
    {
    protected:
        Noncopyable() {}
        ~Noncopyable() {}
        Noncopyable(const Noncopyable & rhs) = delete;
        Noncopyable & operator=(const Noncopyable &) = delete;
    };
}
