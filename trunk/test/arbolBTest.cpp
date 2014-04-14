#include "gtest/gtest.h"
#include "arbolB.h"

TEST(SampleTest, AssertionTrue) {
    ASSERT_EQ(1, 1);
}

TEST(SumaTest, ExpectTrue) {
    EXPECT_EQ(5, Suma(2, 3));
}

TEST(SumaTest2, ExpectTrue) {
    EXPECT_EQ(6, Suma(3, 3));
}
