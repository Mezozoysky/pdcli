#include <pd/cli/option.hpp>
#include <cassert>

using namespace std::literals;


namespace pd::cli
{
option::option(std::string_view name, std::string_view short_name, std::string_view help_text, bool mandatory, bool multiple)
: abstract_option{}
, m_is_given{false}
, m_name{name}
, m_short_name{short_name}
, m_help_text{help_text}
, m_is_mandatory{mandatory}
, m_is_multiple{multiple}
{
}

bool option::parse_cmd_line(std::vector<std::string> const & line, std::size_t & cursor, abstract_style const & st)
{
    assert(!is_given() || m_is_multiple);

    if (cursor >= line.size())
    {
        return false;
    }

    std::string_view name{line[cursor]};
    bool is_short{false};
    if (name.starts_with("--"sv))
    {
        name.remove_prefix("--"sv.size());
    }
    else if (name.starts_with("-"sv))
    {
        name.remove_prefix("-"sv.size());
        is_short = true;
    }
    else
    {
        return false;
    }

    set_is_given();
    ++cursor;
    return true;
}

} // namespace pd::cli
