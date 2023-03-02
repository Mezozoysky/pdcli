#pragma once

#include "abstract_style.hpp"
#include <string>


namespace pd::cli
{

class basic_style
: public abstract_style
{
protected:
    explicit basic_style(std::string_view long_prefix = "--",
                         std::string_view short_prefix = "-",
                         std::string_view long_separator = "=",
                         std::string_view short_separator = "=",
                         std::string_view stop_word = "--");

public:
    basic_style(const basic_style&) noexcept = default;
    basic_style(basic_style&&) noexcept = default;
    basic_style& operator=(const basic_style&) noexcept = default;
    basic_style& operator=(basic_style&&) noexcept = default;
    virtual ~basic_style() noexcept = default;

    inline bool is_long_allowed() const noexcept override final
    {
        return m_long_allowed;
    }
    inline std::string_view get_long_prefix() const override final
    {
        return m_long_prefix;
    }

    inline bool is_short_allowed() const noexcept override final
    {
        return m_short_allowed;
    }
    inline std::string_view get_short_prefix() const override final
    {
        return m_short_prefix;
    }
    inline bool is_short_grouping_allowed() const noexcept override final
    {
        return m_short_grouping_allowed;
    }

    inline bool is_long_separator_allowed() const noexcept override final
    {
        return m_long_separator_allowed;
    }
    inline std::string_view get_long_separator() const override final
    {
        return m_long_separator;
    }
    inline bool is_long_blank_separator_allowed() const noexcept override final
    {
        return m_long_blank_separator_allowed;
    }
    inline bool is_long_no_separator_allowed() const noexcept override final
    {
        return m_long_no_separator_allowed;
    }

    inline bool is_short_separator_allowed() const noexcept override final
    {
        return m_short_separator_allowed;
    }
    inline std::string_view get_short_separator() const override final
    {
        return m_short_separator;
    }
    inline bool is_short_blank_separator_allowed() const noexcept override final
    {
        return m_short_blank_separator_allowed;
    }
    inline bool is_short_no_separator_allowed() const noexcept override final
    {
        return m_short_no_separator_allowed;
    }

    bool is_valid_long_option(std::string_view token) const noexcept override;
    bool is_valid_short_option(std::string_view token) const noexcept override;

    std::string_view parse_option_name(std::string_view token, bool is_short=false) const override;

    inline bool is_options_first_required() const noexcept override final
    {
        return m_options_first_required;
    }

    inline bool is_stop_word_allowed() const noexcept override final
    {
        return m_stop_word_allowed;
    }
    inline std::string_view get_stop_word() const override final
    {
        return m_stop_word;
    }
    inline bool is_stop_word_required() const noexcept override final
    {
        return m_stop_word_required;
    }

    inline bool is_subcommands_allowed() const noexcept override final
    {
        return m_subcommands_allowed;
    }

    bool is_valid_command_name(std::string_view token) const noexcept override;

protected:
    bool m_long_allowed;
    std::string m_long_prefix;

    bool m_short_allowed;
    std::string m_short_prefix;
private:
    bool m_short_grouping_allowed; //TODO: should be protected

protected:
    bool m_long_separator_allowed;
    std::string m_long_separator;
    bool m_long_blank_separator_allowed;
private:
    bool m_long_no_separator_allowed;

protected:
    bool m_short_separator_allowed;
    std::string m_short_separator;
    bool m_short_blank_separator_allowed;
    bool m_short_no_separator_allowed;

    bool m_options_first_required;

    bool m_stop_word_allowed;
    std::string m_stop_word;
    bool m_stop_word_required;

    bool m_subcommands_allowed;
};

} // namespace pd::cli
