#pragma once

#include <vector>
#include <string>
#include <string_view>


namespace pd::cli
{

class abstract_style;

class abstract_clidget
{
public:
    abstract_clidget() noexcept = default;
    abstract_clidget(abstract_clidget const &) noexcept = default;
    abstract_clidget(abstract_clidget &&) noexcept = default;
    abstract_clidget & operator=(abstract_clidget const &) noexcept = default;
    abstract_clidget & operator=(abstract_clidget &&) noexcept = default;
    ~abstract_clidget() noexcept = default;

    virtual bool is_given() const noexcept = 0;
    virtual bool parse_cmd_line(std::vector<std::string> const & line,
                                std::size_t & cursor,
                                abstract_style const & st) = 0;
    virtual std::string_view get_name() const noexcept = 0;
    virtual std::string_view get_help_text() const noexcept = 0;
};


} // namespace pd::cli
