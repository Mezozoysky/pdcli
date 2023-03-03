#pragma once

#include "basic_style.hpp"


namespace pd::cli
{

class gnu_style
    : public basic_style
{
public:
    gnu_style() noexcept;
    gnu_style(gnu_style const &) noexcept = default;
    gnu_style(gnu_style &&) noexcept = default;
    gnu_style& operator=(gnu_style const &) noexcept = default;
    gnu_style& operator=(gnu_style &&) noexcept = default;
    virtual ~gnu_style() noexcept = default;
};

} // namespace pd::cli
