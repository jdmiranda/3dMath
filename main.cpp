#include <iostream>
#include <vector>
#include <Math3D.h>

using namespace std;

int main()
{
    Vector p = Vector(2, 2, 1);
    Vector q = Vector(1, -2, 0);

    vector<Vector> vArray = {p,q};
    cout << Math3D::IsOrthonormal(vArray);
    string s;
    cin >> s;
}