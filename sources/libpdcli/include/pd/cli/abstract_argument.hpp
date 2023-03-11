#pragma once

#include "abstract_clidget.hpp"


namespace pd::cli
{

class abstract_argument
: public abstract_clidget
{
public:
    abstract_argument() noexcept = default;
    virtual ~abstract_argument() noexcept = default;

    virtual bool is_optional() const noexcept = 0;

    virtual bool is_list() const noexcept = 0;
    virtual std::size_t get_min_args() const noexcept = 0;
    virtual std::size_t get_max_args() const noexcept = 0;
};

} // namespace pd::cli
