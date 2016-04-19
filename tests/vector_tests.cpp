#include <Vector.h>
#include "gtest/gtest.h"

TEST(vector_tests, contsuctor_floats) {
    float x = 1.0;
    float y = 2.0;
    float z = 3.0;
    Vector v = Vector(x, y, z);
    EXPECT_EQ(1.0, v.X);
    EXPECT_EQ(2.0, v.Y);
    EXPECT_EQ(3.0, v.Z);
}

TEST(vector__tests, constructor_ints){
    int x = 1.0;
    int y = 2.0;
    int z = 3.0;
    Vector v = Vector(x, y, z);
    EXPECT_EQ(1.0, v.X);
    EXPECT_EQ(2.0, v.Y);
    EXPECT_EQ(3.0, v.Z);
}

TEST(vector_tests, AreEqual)
{
    Vector p = Vector(1,1,1);
    Vector q = Vector(1.0f,1.0f,1.0f);

    bool expect = true;
    bool actual = p == q;

    EXPECT_EQ(expect, actual);
}

TEST(vector_tests, AreNotEqual)
{
    Vector p = Vector(1,0,1);
    Vector q = Vector(1.0f,1.0f,1.0f);

    bool expect = true;
    bool actual = p != q;

    EXPECT_EQ(expect, actual);
}
