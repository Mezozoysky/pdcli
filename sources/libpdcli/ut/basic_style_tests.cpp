#include <catch2/catch_test_macros.hpp>
#include <pd/cli/basic_style.hpp>

using pd::cli::basic_style;

TEST_CASE("basic_style tests", "[style][basic_style]")
{
    basic_style style{};

    REQUIRE(style.is_long_allowed() == true);
    REQUIRE(style.get_long_prefix() == "--");
    REQUIRE(style.is_short_allowed() == true);
    REQUIRE(style.get_short_prefix() == "-");
    REQUIRE(style.is_short_grouping_allowed() == false);
    REQUIRE(style.is_long_separator_allowed() == true);
    REQUIRE(style.get_long_separator() == "=");
    REQUIRE(style.is_long_blank_separator_allowed() == true);
    REQUIRE(style.is_long_no_separator_allowed() == false);
    REQUIRE(style.is_short_separator_allowed() == true);
    REQUIRE(style.get_short_separator() == "=");
    REQUIRE(style.is_short_blank_separator_allowed() == true);
    REQUIRE(style.is_short_no_separator_allowed() == false);

    REQUIRE(style.is_options_first_required() == true);
    REQUIRE(style.is_stop_word_allowed() == true);
    REQUIRE(style.get_stop_word() == "--");
    REQUIRE(style.is_stop_word_required() == false);
    REQUIRE(style.is_subcommands_allowed() == false);
}
