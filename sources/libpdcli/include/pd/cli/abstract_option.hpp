#pragma once

#include "abstract_clidget.hpp"


namespace pd::cli
{

class abstract_option
: public abstract_clidget
{
public:
    abstract_option() noexcept = default;
    virtual ~abstract_option() noexcept = default;

    // virtual std::string_view get_name() const noexcept = 0;
    virtual std::string_view get_short_name() const noexcept = 0;
    virtual bool is_mandatory() const noexcept = 0;
    virtual bool is_multiple() const noexcept = 0;
};

} // namespace pd::cli
