#pragma once

#include "abstract_argument.hpp"


namespace pd::cli
{
template<typename T>
class argument_list : public abstract_argument
{
public:
    argument_list(std::string_view name = "",
                  std::string_view help_text = "",
                  std::size_t min_args = 0ul,
                  std::size_t max_args = 0ul,
                  bool optional = false)
    : abstract_argument()
    , m_given{false}
    , m_name{name}
    , m_help_text{help_text}
    , m_min_args{min_args}
    , m_max_args{max_args}
    , m_optional{optional}
    {
        assert((min_args <= max_args) && "min_args should not be greater then max_args");
    }
    ~argument_list() noexcept = default;

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
        return true;
    }
    inline std::size_t get_min_args() const noexcept override final
    {
        return m_min_args;
    }
    inline std::size_t get_max_args() const noexcept override final
    {
        return m_max_args;
    }

    bool parse_cmd_line(std::vector<std::string> const & line,
                        std::size_t & cursor,
                        abstract_style const & st) override
    {
        assert(!is_given());
        if (cursor == line.size())
        {
            return true;
        }

        std::size_t cursor_save{cursor};
        argument<T> tmp_arg;
        bool success{true};
        while (cursor < line.size())
        {
            if (m_max_args > 0 && m_values.size() == m_max_args)
            {
                break;
            }
            tmp_arg.set_is_given(false); // reset arg
            success = tmp_arg.parse_cmd_line(line, cursor, st);
            if (!success)
            {
                break;
            }
            m_values.emplace_back(tmp_arg.get_value());
        }
        if (!success && m_max_args == 0 && m_values.size() >= m_min_args
            && cursor == line.size())
        {
            success = true;
        }
        if (m_min_args > 0u && m_values.size() < m_min_args)
        {
            std::cerr << "error: argument list requires at least "
                      << std::to_string(m_min_args) << " arguments"
                      << " but only " << m_values.size() << " are given" << std::endl;
            success = false;
        }
        if (!success)
        {
            cursor = cursor_save;
        }
        set_is_given(success);
        return success;
    }

    inline std::vector<T> const & value() const noexcept
    {
        return m_values;
    }
    inline std::vector<T> && get_value() noexcept
    {
        return std::move(m_values);
    }

protected:
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
    std::string_view m_help_text;
    std::size_t m_min_args;
    std::size_t m_max_args;
    bool m_optional;
    std::vector<T> m_values;
};


} // pd::cli
