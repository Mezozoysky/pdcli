#include <pd/cli/from_string.hpp>

#include <exception>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std::literals;

namespace pd::cli
{

static void ltrim(std::string & str)
{
    str.erase(str.begin(),
              std::find_if(str.begin(), str.end(),
                           [](unsigned char c)
                           {
                               return !std::isspace(c);
                           }));
}

static void rtrim(std::string & str)
{
    str.erase(std::find_if(str.rbegin(), str.rend(),
                           [](unsigned char c)
                           {
                               return ! std::isspace(c);
                           }).base(),
              str.end());
}

static void trim(std::string & str)
{
    rtrim(str);
    ltrim(str);
}

// TODO: replace stoi/stol/etc with own strict by-char parsing

static void tolower(std::string & str)
{
    std::transform(str.begin(), str.end(),
                   str.begin(),
                   [](unsigned char c)
                   {
                       return std::tolower(c);
                   });
}

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
    trim(token_lower);
    tolower(token_lower);
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
    std::string str{token};
    trim(str);
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
    std::string str{token};
    trim(str);
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
    std::string str{token};
    trim(str);
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
    std::string str{token};
    trim(str);
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
    std::string str{token};
    trim(str);
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
    std::string str{token};
    trim(str);
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
    std::string str{token};
    trim(str);
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
    std::string str{token};
    trim(str);
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

