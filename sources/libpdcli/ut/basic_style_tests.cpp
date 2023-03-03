#include <catch2/catch_test_macros.hpp>
#include <pd/cli/basic_style.hpp>

using namespace std::literals;
using pd::cli::basic_style;

TEST_CASE("basic_style tests", "[style][basic_style]")
{
    basic_style style{};

    REQUIRE(style.is_long_allowed());
    REQUIRE(style.get_long_prefix() == "--"sv);
    REQUIRE(style.is_long_separator_allowed());
    REQUIRE(style.get_long_separator() == "="sv);
    REQUIRE(style.is_long_blank_separator_allowed());
    REQUIRE(!style.is_long_no_separator_allowed());
    REQUIRE(style.is_short_allowed());
    REQUIRE(style.get_short_prefix() == "-"sv);
    REQUIRE(style.is_short_separator_allowed());
    REQUIRE(style.get_short_separator() == "="sv);
    REQUIRE(style.is_short_blank_separator_allowed());
    REQUIRE(!style.is_short_no_separator_allowed());

    REQUIRE(!style.is_short_grouping_allowed());

    REQUIRE(style.is_options_first_required());

    REQUIRE(style.is_stop_word_allowed());
    REQUIRE(style.get_stop_word() == "--");
    REQUIRE(!style.is_stop_word_required());

    REQUIRE(!style.is_subcommands_allowed());

    REQUIRE(style.is_valid_long_option("--option"sv));
    REQUIRE(style.is_valid_long_option("--some-option"sv));
    REQUIRE(style.is_valid_long_option("--1"sv));
    REQUIRE(!style.is_valid_long_option("-option"sv));
    REQUIRE(!style.is_valid_long_option("option"sv));
    REQUIRE(!style.is_valid_long_option("--"sv));
    REQUIRE(!style.is_valid_long_option(""sv));

    REQUIRE(style.is_valid_short_option("-o"sv));
    REQUIRE(style.is_valid_short_option("-oo"sv)); // no separator is lega in common case
    REQUIRE(style.is_valid_short_option("-1"sv));
    REQUIRE(!style.is_valid_short_option("o"sv));
    REQUIRE(!style.is_valid_short_option("-"sv));
    REQUIRE(!style.is_valid_short_option(""sv));

    REQUIRE(style.parse_option_name("--long-option"sv) == "long-option"sv);
    REQUIRE(style.parse_option_name("long-option"sv) == ""sv);
    REQUIRE(style.parse_option_name("-long-option"sv) == ""sv);
    REQUIRE(style.parse_option_name("long-option"sv) == ""sv);
    REQUIRE(style.parse_option_name("--o"sv) == "o"sv);
    REQUIRE(style.parse_option_name("--1"sv) == "1"sv);
    REQUIRE(style.parse_option_name("--"sv) == ""sv);
    REQUIRE(style.parse_option_name(""sv) == ""sv);

    REQUIRE(style.parse_option_name("-option"sv, true) == ""sv);
    REQUIRE(style.parse_option_name("-o"sv, true) == "o"sv);
    REQUIRE(style.parse_option_name("-1"sv, true) == "1"sv);
    REQUIRE(style.parse_option_name("--o"sv, true) == ""sv);
    REQUIRE(style.parse_option_name("-"sv, true) == ""sv);
    REQUIRE(style.parse_option_name(""sv, true) == ""sv);

    REQUIRE(style.is_valid_command_name("command"sv));
    REQUIRE(!style.is_valid_command_name(""sv));
    REQUIRE(!style.is_valid_command_name("--"sv));
    REQUIRE(!style.is_valid_command_name("-"sv));
    REQUIRE(!style.is_valid_command_name("--option"sv));
    REQUIRE(!style.is_valid_command_name("-o"sv));
}
