#include <iostream>
#include "list.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("list", "[Task_1]")
{
    List test;
    SECTION("Size") {
        CHECK(test.Size() == 0);
        test.PushBack(1);
        test.PushBack(2);
        test.PushBack(3);
        CHECK(test.Size() == 3);
    }
    SECTION("Empty") {
        CHECK(test.Empty() == true);
        test.PushBack(1);
        test.PushBack(2);
        CHECK(test.Empty() == false);
    }
    SECTION("Clear") {
        test.Clear();
        CHECK(test.Size() == 0);
    }

}


int main()
{
    return Catch::Session().run();
}
