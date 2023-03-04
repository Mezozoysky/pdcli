#include <catch2/catch_test_macros.hpp>

#include <pd/cli/from_string.hpp>

using namespace std::literals;
using namespace pd::cli;


TEST_CASE("from_string<T> basic usage", "[from_string]")
{
    SECTION("empty")
    {
    }

    SECTION("T = std::string")
    {
        std::string str{from_string("some string"sv)};
        REQUIRE(str == "some string"s);
        str = from_string(""sv);
        REQUIRE(str.size() == 0);
    }

    SECTION("T = bool")
    {
        bool b{from_string<bool>("true"sv)};
        REQUIRE(b == true);
        b = from_string<bool>("false"sv);
        REQUIRE(b == false);
        b = from_string<bool>("TRUE"sv);
        REQUIRE(b == true);
        b = from_string<bool>("FALSE"sv);
        REQUIRE(b == false);
        b = from_string<bool>("True"sv);
        REQUIRE(b == true);
        b = from_string<bool>("False"sv);
        REQUIRE(b == false);
        b = from_string<bool>("TrUe"sv);
        REQUIRE(b == true);
        b = from_string<bool>("FaLsE"sv);
        REQUIRE(b == false);
        b = from_string<bool>("t"sv);
        REQUIRE(b == true);
        b = from_string<bool>("f"sv);
        REQUIRE(b == false);
        b = from_string<bool>("T"sv);
        REQUIRE(b == true);
        b = from_string<bool>("F"sv);
        REQUIRE(b == false);
        b = from_string<bool>("on"sv);
        REQUIRE(b == true);
        b = from_string<bool>("off"sv);
        REQUIRE(b == false);
        b = from_string<bool>("ON"sv);
        REQUIRE(b == true);
        b = from_string<bool>("OFF"sv);
        REQUIRE(b == false);
        b = from_string<bool>("On"sv);
        REQUIRE(b == true);
        b = from_string<bool>("Off"sv);
        REQUIRE(b == false);
        b = from_string<bool>("oN"sv);
        REQUIRE(b == true);
        b = from_string<bool>("oFF"sv);
        REQUIRE(b == false);
    }

    SECTION("T = int")
    {
        int i{from_string<int>("22"sv)};
        REQUIRE(i == 22);
        i = from_string<int>("0"sv);
        REQUIRE(i == 0);
    }
    SECTION("T = long")
    {
        long i{from_string<long>("22"sv)};
        REQUIRE(i == 22l);
        i = from_string<long>("0"sv);
        REQUIRE(i == 0l);
    }
    SECTION("T = unsigned long")
    {
        unsigned long i{from_string<unsigned long>("22"sv)};
        REQUIRE(i == 22ul);
        i = from_string<unsigned long>("0"sv);
        REQUIRE(i == 0ul);
    }
    SECTION("T = long long")
    {
        long long i{from_string<long long>("22"sv)};
        REQUIRE(i == 22ll);
        i = from_string<long long>("0"sv);
        REQUIRE(i == 0ll);
    }
    SECTION("T = unsigned long long")
    {
        unsigned long long i{from_string<unsigned long long>("22"sv)};
        REQUIRE(i == 22ull);
        i = from_string<unsigned long long>("0"sv);
        REQUIRE(i == 0ull);
    }


    SECTION("T = float")
    {
        float f{from_string<float>("3.1415926"sv)};
        REQUIRE(f == 3.1415926f);
        f = from_string<float>("0.0"sv);
        REQUIRE(f == 0.0f);
    }
    SECTION("T = double")
    {
        double f{from_string<double>("3.1415926"sv)};
        REQUIRE(f == 3.1415926);
    }
    SECTION("T = long double")
    {
        long double f{from_string<long double>("3.14159265358979323846264338328"sv)};
        REQUIRE(f == 3.14159265358979323846264338328l);
    }
}

