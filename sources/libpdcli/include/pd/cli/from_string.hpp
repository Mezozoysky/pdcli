#pragma once

#include <string>
#include <string_view>


namespace pd::cli
{

template<typename T=std::string>
T from_string(std::string_view token);

} // namespace pd::cli

