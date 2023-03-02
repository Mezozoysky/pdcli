#pragma once

#include <string_view>


namespace pd::cli
{

class abstract_style
{
public:
    abstract_style() noexcept = default;
    abstract_style(const abstract_style&) noexcept = default;
    abstract_style(abstract_style&&) noexcept = default;
    abstract_style& operator=(const abstract_style&) noexcept = default;
    abstract_style& operator=(abstract_style&&) noexcept = default;
    virtual ~abstract_style() noexcept = default;

    virtual bool is_long_allowed() const noexcept = 0;
    virtual std::string_view get_long_prefix() const = 0;

    virtual bool is_short_allowed() const noexcept = 0;
    virtual std::string_view get_short_prefix() const = 0;
    virtual bool is_short_grouping_allowed() const noexcept = 0;

    virtual bool is_long_separator_allowed() const noexcept = 0;
    virtual std::string_view get_long_separator() const = 0;
    virtual bool is_long_blank_separator_allowed() const noexcept = 0;
    virtual bool is_long_no_separator_allowed() const noexcept = 0;

    virtual bool is_short_separator_allowed() const noexcept = 0;
    virtual std::string_view get_short_separator() const = 0;
    virtual bool is_short_blank_separator_allowed() const noexcept = 0;
    virtual bool is_short_no_separator_allowed() const noexcept = 0;

    virtual bool is_valid_long_option(std::string_view token) const noexcept = 0;
    virtual bool is_valid_short_option(std::string_view token) const noexcept = 0;
    virtual std::string_view parse_option_name(std::string_view token, bool is_short=false) const = 0;

    virtual bool is_options_first_required() const noexcept = 0;

    virtual bool is_stop_word_allowed() const noexcept = 0;
    virtual std::string_view get_stop_word() const = 0;
    virtual bool is_stop_word_required() const noexcept = 0;

    virtual bool is_subcommands_allowed() const noexcept = 0;

    virtual bool is_valid_command_name(std::string_view token) const noexcept = 0;
};

} // namespace pd::cli
