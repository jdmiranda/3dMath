#include <Math3D.h>
#include "gtest/gtest.h"

TEST(math_tests, Dot)
{
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);

    float actual = Math3D::Dot(p,q);
    float expect = -2.0f;

    EXPECT_FLOAT_EQ(expect, actual);
}

TEST(math_tests, Cross)
{
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);

    Vector actual = Math3D::Cross(p,q);
    Vector expect = Vector(2, 1, -6);

    EXPECT_FLOAT_EQ(expect.X, actual.X);
    EXPECT_FLOAT_EQ(expect.Y, actual.Y);
    EXPECT_FLOAT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, Magnitude)
{
    Vector v = Vector(2, 2, 1);

    float expect = 3.0f;
    float actual = Math3D::Mag(v);

    EXPECT_FLOAT_EQ(expect, actual);
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

    EXPECT_FLOAT_EQ(expect.X, actual.X);
    EXPECT_FLOAT_EQ(expect.Y, actual.Y);
    EXPECT_FLOAT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, Perpindicular) {
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);
    float x = 13.0/9.0;
    float y = -14.0/9.0;
    float z = 2.0/9.0;

    Vector expect = Vector(x, y, z);
    Vector actual = Math3D::Perp(q, p);

    EXPECT_FLOAT_EQ(expect.X, actual.X);
    EXPECT_FLOAT_EQ(expect.Y, actual.Y);
    EXPECT_FLOAT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, More)
{
    Vector p = Vector (1, 1, 1);
    Vector q = Vector (2, 2, 2);

    Vector expect = Vector (3, 3, 3);
    Vector actual = Math3D::More(p, q);

    EXPECT_FLOAT_EQ(expect.X, actual.X);
    EXPECT_FLOAT_EQ(expect.Y, actual.Y);
    EXPECT_FLOAT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, Less)
{
    Vector p = Vector (1, 1, 1);
    Vector q = Vector (2, 2, 2);

    Vector expect = Vector (1, 1, 1);
    Vector actual = Math3D::Less(q, p);

    EXPECT_FLOAT_EQ(expect.X, actual.X);
    EXPECT_FLOAT_EQ(expect.Y, actual.Y);
    EXPECT_FLOAT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, Mul)
{
    Vector p = Vector (1.0f, 2.0f, 0.5f);
    float scalar = 0.5f;

    Vector expect = Vector (0.5f, 1.0f, 0.25f);
    Vector actual = Math3D::Mul(scalar, p);

    EXPECT_FLOAT_EQ(expect.X, actual.X);
    EXPECT_FLOAT_EQ(expect.Y, actual.Y);
    EXPECT_FLOAT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, MakeOrthoNormal)
{
    Vector p = Vector(-1, 1, 0);
    Vector q = Vector(-1, 0, 1);
    std::vector<Vector> collection = {p,q};
}

TEST(math_tests, Normalize01)
{
    float x = sqrtf(2.0f)/2.0f;
    float y = x;
    float z = 0.0f;

    Vector v = Vector (x,y,z);
    std::vector<Vector> collection = {v};

    Vector expect = Vector(x,y,z);
    collection[0] = Math3D::Normalize(v);
    Vector actual = collection[0];

    EXPECT_FLOAT_EQ(expect.X, actual.X);
    EXPECT_FLOAT_EQ(expect.Y, actual.Y);
    EXPECT_FLOAT_EQ(expect.Z, actual.Z);
}

TEST(math_tests, Orthogonalize)
{
    float x = -1;
    float y = 1;
    float z = -1;

    Vector p = Vector(sqrtf(2.0f), sqrtf(2.0f), 0.0f);
    Vector q = Vector (x,y,z);
    std::vector<Vector> collection = {p,q};

    Vector expect = Vector(x,y,z);
    collection = Math3D::MakeOrthoNormal(collection);
    Vector actual = collection[0];

    EXPECT_FLOAT_EQ(expect.X, actual.X);
    EXPECT_FLOAT_EQ(expect.Y, actual.Y);
    EXPECT_FLOAT_EQ(expect.Z, actual.Z);
}