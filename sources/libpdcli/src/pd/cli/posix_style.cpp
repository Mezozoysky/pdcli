#include <pd/cli/posix_style.hpp>

using namespace std::literals;

namespace pd::cli
{

posix_style::posix_style() noexcept
: basic_style(""sv, "-"sv, ""sv, "="sv, ""sv)
{
    m_long_allowed = false;
    m_long_separator_allowed = false;
    m_long_blank_separator_allowed = false;
    m_long_no_separator_allowed = false;
    m_stop_word_allowed = false;
}

} // namespace pd::cli
