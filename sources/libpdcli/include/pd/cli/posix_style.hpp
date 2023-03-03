#pragma once

#include "basic_style.hpp"


namespace pd::cli
{

class posix_style
: public basic_style
{
public:
    posix_style() noexcept;
    posix_style(posix_style const &) noexcept = default;
    posix_style(posix_style &&) noexcept = default;
    posix_style& operator=(posix_style const &) noexcept = default;
    posix_style& operator=(posix_style &&) noexcept = default;
    virtual ~posix_style() noexcept = default;
};

} // namespace pd::cli
