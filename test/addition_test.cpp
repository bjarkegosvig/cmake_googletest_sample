#include <gtest/gtest.h>
#include <cstdint>

extern "C"{
#include "add.h"
}

TEST(AdditionTests, TestInteger42)
{
    const int32_t expected = 42;
    const int32_t actual = add(35, 7);
    ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
