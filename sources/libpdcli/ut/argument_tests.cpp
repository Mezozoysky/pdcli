#include <catch2/catch_test_macros.hpp>

#include <pd/cli/argument.hpp>
#include <pd/cli/gnu_style.hpp>
#include <pd/cli/from_string.hpp>


using namespace std::literals;
using namespace pd::cli;

TEST_CASE("argument basic tests" "[argument]")
{
    argument<std::string> str_arg{};
    argument<int> int_arg{};
    argument<unsigned long> ulong_arg{};

    std::vector<std::string> cmd_line
    {
        "some_string"s,
        "22"s,
        "-33"s,
        "+44"s,
        "1001100100"s
    };

    gnu_style st{};

    bool success{true};
    std::size_t cursor{0u};

    REQUIRE(!str_arg.is_given());
    success = str_arg.parse_cmd_line(cmd_line, cursor, st);
    REQUIRE(success);
    REQUIRE(cursor == 1u);
    REQUIRE(str_arg.is_given());
    REQUIRE(str_arg.value() == "some_string"s);

    REQUIRE(!int_arg.is_given());
    success = int_arg.parse_cmd_line(cmd_line, cursor, st);
    REQUIRE(success);
    REQUIRE(cursor == 2u);
    REQUIRE(int_arg.is_given());
    REQUIRE(int_arg.value() == 22);
    int_arg = argument<int>{};
    success = int_arg.parse_cmd_line(cmd_line, cursor, st);
    REQUIRE(success);
    REQUIRE(cursor == 3u);
    REQUIRE(int_arg.is_given());
    REQUIRE(int_arg.value() == -33);
    int_arg = argument<int>();
    success = int_arg.parse_cmd_line(cmd_line, cursor, st);
    REQUIRE(success == true);
    REQUIRE(cursor == 4u);
    REQUIRE(int_arg.is_given() == true);
    REQUIRE(int_arg.value() == 44);

}
