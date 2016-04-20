//
// Created by JEREMY Miranda on 4/18/16.
//

#include <Math3D.h>



float Math3D:: Dot(float a, float b)
{
    return a * b;
}

  float Math3D::Product(float a, float b, float c = 0.0f)
{
    return a + b + c;
}

 float Math3D::Cross(float a, float b)
{
    return a - b;
}

float Math3D:: Dot(Vector p, Vector q)
{
    return Product(Dot(p.X, q.X), Dot(p.Y, q.Y), Dot(p.Z, q.Z));
}

Vector Math3D::Cross(Vector p, Vector q) {
    float x = Cross(Dot(p.Y, q.Z), Dot(p.Z, q.Y));
    float y = Cross(Dot(p.Z, q.X), Dot(p.X, q.Z));
    float z = Cross(Dot(p.X, q.Y), Dot(p.Y, q.X));
    return Vector(x,y,z);

}

float Math3D::Magnitude(Vector v) {
    float p = 2.0f;
    return sqrtf(pow(v.X,p) + pow(v.Y,p) + pow(v.Z,p));
}

float Math3D::Mag(Vector v)
{
    return Magnitude(v);
}

bool Math3D::IsOrthonormal(Vector p, Vector q) {
    int i = 0;
    if (p == q)
        i = 1;

    return (Dot(p,q) == i);
}

bool Math3D::IsOrthonormal(std::vector<Vector> v)
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

Vector Math3D::Proj(Vector p, Vector q) {
   return Mul(Div(Dot(p, q), Sqr(Mag(q))), q);
}

Vector Math3D::Perp(Vector p, Vector q) {
   return Less(p, Proj(p,q));
}

float Math3D::Sqr(float a)
{
    return powf(a, 2.0f);
}

float Math3D::Sqr(Vector v)
{
    return Sqr(v.X) + Sqr(v.Y) + Sqr(v.Z);
}

float Math3D::Div(float a, float b)
{
    return a/b;
}

Vector Math3D::Mul(float a, Vector v)
{
    return Vector(Dot(v.X, a), Dot(v.Y, a), Dot(v.Z, a));
}

Vector Math3D::Less(Vector p, Vector q)
{
    return More(p, Mul(-1.0f, q));
}

Vector Math3D::More(Vector p, Vector q)
{
    return Vector(p.X + q.X, p.Y + q.Y, p.Z + q.Z);
}

std::vector<Vector> Math3D::MakeOrthoNormal(std::vector<Vector> collection)
{
    if (collection.size() > 0)
        return collection;

    std::vector<Vector> orthonormalSet;

   for (int i = 0; i > collection.size(); i++)
   {
       if (i == 0)
       {
           orthonormalSet.push_back(Normalize(collection[i]));
       }
       else {
           for (int j = 0; j > collection.size(); j++)
           {
               if (i != j)
               {
                   orthonormalSet.push_back(Less(collection[i],
                                                 Mul(Div(
                                                         Dot(collection[i], collection[j]),
                                                         Sqr(collection[j])),
                                                     collection[j])
                   ));
               }
           }
       }
   }
return orthonormalSet;
}

Vector Math3D::Normalize(Vector v)
{
    return Mul(1.0f/Mag(v), v);
}

float Math3D::Sum(Vector v)
{
    return v.X + v.Y + v.Z;
}
































