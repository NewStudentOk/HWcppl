#include <iostream>
#include "list.cpp"
#include <./catch2/catch_test_macros.hpp>
#include <./catch2/catch_session.hpp>

TEST_CASE("list", "[Task_1]")
{
    List test;

    SECTION("Test function PushBack")
    {
        test.PushBack(2);
        test.PushBack(3);
        CHECK(test.PopBack() == 3);
        test.PushBack(9);
        CHECK(test.PopBack() == 9);
        test.PushBack(10);
        CHECK(test.PopFront() == 2);
    }

    SECTION("Test function PushFront")
    {
        test.PushFront(2);
        test.PushFront(3);
        CHECK(test.PopFront() == 3);
        test.PushBack(1);
        test.PushFront(5);
        CHECK(test.PopFront() == 5);
        test.PushFront(10);
        CHECK(test.PopBack() == 1);
    }

    SECTION("Test function PopBack")
    {
        test.PushBack(1);
        CHECK(test.PopBack() == 1);
        test.PushBack(2);
        test.PushBack(5);
        test.PushBack(3);
        CHECK(test.PopBack() == 3);
    }

    SECTION("Test function PopFront")
    {
        test.PushBack(1);
        CHECK(test.PopFront() == 1);
        test.PushBack(2);
        test.PushBack(5);
        test.PushBack(3);
        CHECK(test.PopFront() == 2);
    }

    SECTION("Throws Exceptions") {
        test.Clear();
        CHECK_THROWS(test.PopBack());
        CHECK_THROWS(test.PopFront());
    }

}


int main()
{
    return Catch::Session().run();
}
