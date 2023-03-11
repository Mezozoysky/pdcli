#pragma once

#include "abstract_argument.hpp"
#include <iostream>


namespace pd::cli
{

template<typename T>
class argument_list;

template<typename T>
class argument : public abstract_argument
{
public:
    argument(std::string_view name = "",
             std::string_view help_text = "",
             bool optional = false)
    : abstract_argument()
    , m_given{false}
    , m_name{name}
    , m_help_text{help_text}
    , m_optional{optional}
    {
    }
    virtual ~argument() noexcept = default;

    inline bool is_given() const noexcept override final
    {
        return m_given;
    }

    inline std::string_view get_name() const noexcept override final
    {
        return m_name;
    }
    inline std::string_view get_help_text() const noexcept override final
    {
        return m_help_text;
    }

    inline bool is_optional() const noexcept override final
    {
        return m_optional;
    }

    inline bool is_list() const noexcept override final
    {
        return false;
    }
    inline std::size_t get_min_args() const noexcept override final
    {
        return m_optional ? 0 : 1;
    }
    inline std::size_t get_max_args() const noexcept override final
    {
        return 1;
    }

    bool parse_cmd_line(std::vector<std::string> const & line,
                        std::size_t & cursor,
                        abstract_style const & st) override
    {
        assert(!is_given());
        std::string_view token = line[cursor];
        try
        {
            m_value = from_string<T>(token);
            set_is_given(); //++m_given;
            ++cursor;
        }
        catch (std::exception const & e)
        {
            std::cerr << "failed to parse command line argument '" << token
                      << "': " << e.what() << std::endl;
            // return m_optional ? true : false;
            return false;
        }
        catch (...)
        {
            std::cerr << "failed to parse command line argument '" << token << "'"
                      << std::endl;
            // return m_optional ? true : false;
            return false;
        }
        // return m_optional ? true : is_given();
        return is_given();
    }

    inline T const & value() const noexcept
    {
        return m_value;
    }
    inline T && get_value() noexcept
    {
        return std::move(m_value);
    }

protected:
    friend class argument_list<T>;
    inline void set_is_given(bool given = true)
    {
        m_given = given;
    }
    inline void set_name(std::string_view name)
    {
        m_name = name;
    }
    inline void set_help_text(std::string_view help_text)
    {
        m_help_text = help_text;
    }

private:
    bool m_given;
    std::string m_name;
    std::string m_help_text;
    bool m_optional;
    T m_value;
};

} // namespace pd::cli
