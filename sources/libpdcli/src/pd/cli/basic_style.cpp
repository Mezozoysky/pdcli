#include <pd/cli/basic_style.hpp>
#include <cassert>

namespace pd::cli
{

basic_style::basic_style(std::string_view long_prefix,
                         std::string_view short_prefix,
                         std::string_view long_separator,
                         std::string_view short_separator,
                         std::string_view stop_word)
: abstract_style{}
, m_long_allowed{true}
, m_long_prefix{long_prefix}
, m_short_allowed{true}
, m_short_prefix{short_prefix}
, m_short_grouping_allowed{false}
, m_long_separator_allowed{true}
, m_long_separator{long_separator}
, m_long_blank_separator_allowed{true}
, m_long_no_separator_allowed{false}
, m_short_separator_allowed{true}
, m_short_separator{short_separator}
, m_short_blank_separator_allowed{true}
, m_short_no_separator_allowed{false}
, m_options_first_required{true}
, m_stop_word_allowed{true}
, m_stop_word{stop_word}
, m_stop_word_required{false}
, m_subcommands_allowed{false}
{
}

bool basic_style::is_valid_long_option(std::string_view token) const noexcept
{
    return (token.starts_with(get_long_prefix())
            && token.size() > get_long_prefix().size());
}

bool basic_style::is_valid_short_option(std::string_view token) const noexcept
{
    return (token.starts_with(get_short_prefix())
            && token.size() >= get_short_prefix().size() + 1);
}

std::string_view basic_style::parse_option_name(std::string_view token, bool is_short) const
{
    std::string_view name{};
    if (is_short)
    {
        if (!is_valid_short_option(token))
        {
            return std::string_view{};
        }
        name = token;
        name.remove_prefix(get_short_prefix().size());
        if (name.size() == 1)
        {
            return name;
        }
        if (!is_short_separator_allowed() && !is_short_no_separator_allowed())
        {
            return std::string_view{}; // short option name length should be equal to 1
        }
        else
        {
            std::size_t pos{name.find(get_short_separator())};
            if (pos != std::string_view::npos)
            {
                if (is_short_separator_allowed())
                {
                    name.remove_suffix(name.size() - pos);
                    assert(name.size() == 1);
                    return name;
                }
                else
                {
                    return std::string_view{};
                }
            }
            else
            {
                if (is_short_no_separator_allowed())
                    {
                        name.remove_suffix(name.size() - 1);
                        return name;
                    }
                else
                    {
                        return std::string_view{};
                    }
            }
        }
    }
    else
    {
        if (!is_valid_long_option(token))
        {
            return std::string_view{};
        }
        name = token;
        name.remove_prefix(get_long_prefix().size());
        if (is_long_separator_allowed())
        {
            std::size_t pos{name.find(get_long_separator())};
            if (pos == name.size() - 1)
            {
                return std::string_view{}; // separator without argument isnt allowed
            }
            if (pos != std::string_view::npos)
            {
                name.remove_suffix(name.size() - pos);
            }
        }
        return name;
    }
}

bool basic_style::is_valid_command_name(std::string_view token) const noexcept
{
    if (token.size() == 0)
    {
        return false;
    }
    if (is_long_allowed() && token.starts_with(get_long_prefix()))
    {
        return false;
    }
    if (is_short_allowed() && token.starts_with(get_short_prefix()))
        {
            return false;
        }
    if (is_stop_word_allowed() && token == get_stop_word())
    {
        return false;
    }
    return true;
}

} // namespace pd::cli
