#include <pd/cli/from_string.hpp>

#include <exception>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std::literals;

namespace pd::cli
{


template<>
std::string from_string(std::string_view token)
{
    std::string value{token};
    return std::move(value);
}

template<>
bool from_string(std::string_view token)
{
    bool value{false};

    std::string token_lower{token};
    std::transform(token_lower.begin(), token_lower.end(),
                   token_lower.begin(),
                   [](unsigned char c)
                   {
                        return std::tolower(c);
                   });
    if (token_lower == "true"sv
        || token_lower == "t"sv
        || token_lower == "on"sv)
    {
        value = true;
    }
    else if (token_lower == "false"sv
             || token_lower == "f"sv
             || token_lower == "off"sv)
    {
        value = false;
    }
    else
    {
        std::ostringstream error_str;
        error_str << "Failed to parse \"" << token << "\" as bool";
        throw std::runtime_error(error_str.str());
    }
    return value;
}

template<>
int from_string(std::string_view token)
{
    int value{0};
    std::string const str{token};
    try
    {
        value = std::stoi(str);
    }
    catch (std::exception const & e)
    {
        std::cout << "failed to parse integer: " << e.what() << std::endl;
        throw;
    }
    return value;
}

template<>
long from_string(std::string_view token)
{
    long value{0l};
    std::string const str{token};
    try
    {
        value = std::stol(str);
    }
    catch (std::exception const & e)
    {
        std::cout << "failed to parse long: " << e.what() << std::endl;
        throw;
    }
    return value;
}

template<>
unsigned long from_string(std::string_view token)
{
    unsigned long value{0ul};
    std::string const str{token};
    try
    {
        value = std::stoul(str);
    }
    catch (std::exception const & e)
    {
        std::cout << "failed to parse unsigned long: " << e.what() << std::endl;
        throw;
    }
    return value;
}

template<>
long long from_string(std::string_view token)
{
    long long value{0ll};
    std::string const str{token};
    try
    {
        value = std::stoll(str);
    }
    catch (std::exception const & e)
    {
        std::cout << "failed to parse long long: " << e.what() << std::endl;
        throw;
    }
    return value;
}

template<>
unsigned long long from_string(std::string_view token)
{
    unsigned long long value{0ull};
    std::string const str{token};
    try
    {
        value = std::stoull(str);
    }
    catch (std::exception const & e)
    {
        std::cout << "failed to parse unsigned long long: " << e.what() << std::endl;
        throw;
    }
    return value;
}

template<>
float from_string(std::string_view token)
{
    float value{0.0f};
    std::string const str{token};
    try
    {
        value = std::stof(str);
    }
    catch (std::exception const & e)
    {
        std::cout << "failed to parse float: " << e.what() << std::endl;
        throw;
    }
    return value;
}

template<>
double from_string(std::string_view token)
{
    double value{0.0};
    std::string const str{token};
    try
    {
        value = std::stod(str);
    }
    catch (std::exception const & e)
    {
        std::cout << "failed to parse double: " << e.what() << std::endl;
        throw;
    }
    return value;
}

template<>
long double from_string(std::string_view token)
{
    long double value{0.0l};
    std::string const str{token};
    try
    {
        value = std::stold(str);
    }
    catch (std::exception const & e)
    {
        std::cout << "failed to parse long double: " << e.what() << std::endl;
        throw;
    }
    return value;
}


} // namespace pd::cli

