#include <iostream>
#include "Vector/Vector.h"
#include "Vector/Math.h"

using namespace std;

int main()
{
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);

    vector<Vector> vArray = {p,q};
    cout << Math::IsOrthonormal(vArray);

    string s;
    cin >> s;
}