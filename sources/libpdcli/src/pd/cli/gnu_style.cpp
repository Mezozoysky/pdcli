#include <pd/cli/gnu_style.hpp>


namespace pd::cli
{

gnu_style::gnu_style() noexcept
: basic_style()
{
    m_short_grouping_allowed = true;
    m_short_no_separator_allowed = true;
    m_options_first_required = false;
}

} // namespace pd::cli
