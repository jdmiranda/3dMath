//
// Created by JEREMY Miranda on 4/18/16.
//

#include "Math.h"
#include<math.h>



  float Math:: Dot(float a, float b)
{
    return a * b;
}

  float Math::Product(float a, float b, float c = 0.0f)
{
    return a + b + c;
}

 float Math::Cross(float a, float b)
{
    return a - b;
}

float Math:: DotProduct(Vector p, Vector q)
{
    return Product(Dot(p.X, q.X), Dot(p.Y, q.Y), Dot(p.Z, q.Z));
}

Vector Math::CrossProduct(Vector p, Vector q) {
    float x = Cross(Dot(p.Y, q.Z), Dot(p.Z, q.Y));
    float y = Cross(Dot(p.Z, q.X), Dot(p.X, q.Z));
    float z = Cross(Dot(p.X, q.Y), Dot(p.Y, q.X));
    return Vector(x,y,z);

}

float Math::Magnitude(Vector v) {
    float p = 2.0f;
    return sqrtf(pow(v.X,p) + pow(v.Y,p) + pow(v.Z,p));
}

float Math::Mag(Vector v)
{
    return Magnitude(v);
}

bool Math::IsOrthonormal(Vector p, Vector q) {
    int i = 0;
    if (p == q)
        i = 1;

    return (DotProduct(p,q) == i);
}

bool Math::IsOrthonormal(std::vector<Vector> v)
{
    long length = v.size();
    if (length <= 0) return true;

    if (length == 1)
    {
        return IsOrthonormal(v[0], v[0]);
    }
    else
    {
        int remaining = length - 1;
        std::vector<Vector> vectors;
        for (int i = 0; i < remaining; i++)
        {
            if (IsOrthonormal(v[0], v[i+1]))
            vectors.push_back(Vector(v[i].X, v[i].Y, v[i].Z));
        }

        return IsOrthonormal(vectors);
    }
}














