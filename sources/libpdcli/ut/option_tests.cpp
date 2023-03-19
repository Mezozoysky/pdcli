#include <catch2/catch_test_macros.hpp>

#include <pd/cli/option.hpp>
#include <pd/cli/gnu_style.hpp>
#include <vector>


using namespace std::literals;
using namespace pd::cli;

TEST_CASE("option parsing tests" "[clidget][option]")
{
    option flag{"flag"sv, "f"sv,
         "My flag description",
         false,
         false};
    option multi{"multi-flag"sv, "m"sv,
        "My multiflag option",
        false,
        true};

    std::vector<std::string> cmd_line{
        "--flag",
        "--multi-flag",
        "-m",
        "--multi-flag"
    };

    gnu_style st{};

    bool success{true};
    std::size_t cursor{0u};

    REQUIRE(flag.is_given() == false);
    success = flag.parse_cmd_line(cmd_line, cursor, st);
    REQUIRE(success == true);
    REQUIRE(cursor == 1u);
    REQUIRE(flag.is_given() == true);
    success = multi.parse_cmd_line(cmd_line, cursor, st);
    REQUIRE(success == true);
    REQUIRE(cursor == 2u);
}

