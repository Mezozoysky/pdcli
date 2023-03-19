#pragma once

#include "abstract_option.hpp"


namespace pd::cli
{

class option
: public abstract_option
{
public:
    option(std::string_view name, std::string_view short_name, std::string_view help_text, bool mandatory, bool multiple);
    option(const option &) = default;
    option(option &&) noexcept = default;
    option& operator=(const option &) noexcept = default;
    option& operator=(option &&) noexcept = default;
    ~option() noexcept = default;

    bool parse_cmd_line(std::vector<std::string> const & line, std::size_t & cursor, abstract_style const & st) override;

    inline bool is_given() const noexcept override final
    {
        return m_is_given;
    }

    inline std::string_view get_name() const noexcept override final
    {
        return m_name;
    }

    inline std::string_view get_help_text() const noexcept override final
    {
        return m_help_text;
    }

    inline std::string_view get_short_name() const noexcept override final
    {
        return m_short_name;
    }

    inline bool is_mandatory() const noexcept override final
    {
        return m_is_mandatory;
    }

    inline bool is_multiple() const noexcept override final
    {
        return m_is_multiple;
    }

protected:
    inline void set_is_given(bool given = true) { m_is_given = given; }
    inline void set_name(std::string_view name) { m_name = name; }
    inline void set_help_text(std::string_view help_text) { m_help_text = help_text; }

private:
    bool m_is_given;
    std::string m_name;
    std::string m_short_name;
    std::string m_help_text;
    bool m_is_mandatory;
    bool m_is_multiple;
};

} // namespace pd::cli
