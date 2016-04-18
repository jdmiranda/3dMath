//
// Created by JEREMY Miranda on 4/18/16.
//

#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

 class Vector {
 public:
     Vector(float x, float y, float z);

     bool operator == (Vector v);
     bool operator != (Vector v);

     float X;
     float Y;
     float Z;

     void Print();

};


#endif //MATH_VECTOR_H
