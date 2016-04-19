#include <Math3D.h>
#include "gtest/gtest.h"
#include <vector.h>

TEST(math3d_tests, Dot)
{
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);

    float actual = Math3D::Dot(p,q);
    float expect = -2;

    EXPECT_EQ(expect, actual);
}

TEST(math3d__tests, Cross)
{
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);

    Vector actual = Math3D::Cross(p,q);
    Vector expect = Vector(2, 1, -6);

    EXPECT_EQ(expect.X, actual.X);
    EXPECT_EQ(expect.Y, actual.Y);
    EXPECT_EQ(expect.Z, actual.Z);
}

TEST(math3d_tests, Magnitude)
{
    Vector v = Vector(2, 2, 1);

    float expect = 3;
    float actual = Math3D::Mag(v);

    EXPECT_EQ(expect, actual);
}

TEST(math_tests, IsOrthonormal)
{
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);
    std::vector<Vector> collection = {p,q};

    bool expect = true;
    bool actual = Math3D::IsOrthonormal(collection);

    EXPECT_EQ(expect, actual);
}

TEST(math_tests, Projection)
{
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);
    float x = -4.0/9.0;
    float y = -4.0/9.0;
    float z = -2.0/9.0;

    Vector expect = Vector (x, y, z);
    Vector actual = Math3D::Proj(q,p);

    EXPECT_EQ(expect.X, actual.X);
    EXPECT_EQ(expect.Y, actual.Y);
    EXPECT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, Perpindicular) {
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);
    float x = 13.0/9.0;
    float y = -14.0/9.0;
    float z = 2.0/9.0;

    Vector expect = Vector(x, y, z);
    Vector actual = Math3D::Perp(q, p);

    EXPECT_EQ(expect.X, actual.X);
    EXPECT_EQ(expect.Y, actual.Y);
    EXPECT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, More)
{
    Vector p = Vector (1, 1, 1);
    Vector q = Vector (2, 2, 2);

    Vector expect = Vector (3, 3, 3);
    Vector actual = Math3D::More(p, q);

    EXPECT_EQ(expect.X, actual.X);
    EXPECT_EQ(expect.Y, actual.Y);
    EXPECT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, Less)
{
    Vector p = Vector (1, 1, 1);
    Vector q = Vector (2, 2, 2);

    Vector expect = Vector (1, 1, 1);
    Vector actual = Math3D::Less(q, p);

    EXPECT_EQ(expect.X, actual.X);
    EXPECT_EQ(expect.Y, actual.Y);
    EXPECT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, Mul)
{
    Vector p = Vector (1.0f, 2.0f, 0.5f);
    float scalar = 0.5f;

    Vector expect = Vector (0.5f, 1.0f, 0.25f);
    Vector actual = Math3D::Mul(scalar, p);

    EXPECT_EQ(expect.X, actual.X);
    EXPECT_EQ(expect.Y, actual.Y);
    EXPECT_EQ(expect.Z, actual.Z);
}