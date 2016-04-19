//
// Created by JEREMY Miranda on 4/18/16.
//

#ifndef MATH_MATH_H
#define MATH_MATH_H


#include "Vector.h"
#include <vector>

  class Math {
public:

	  /**
	   * Returns a measure of difference between the directions in which two vectors point.
	   */
	 static float Dot(Vector p, Vector q);

	  /**
	   * Returns  a new vector that is perpendicular to both vectors being multiplied.
	   */
	 static Vector Cross(Vector p, Vector q);

	  /**
	   * Returns the length/norm of a vector.
	   */
	  static float Mag(Vector v);

	  /**
	   * Returns true if for every pair (i,j) with i != j, and i dot j  = 0.
	   */
      static bool IsOrthonormal(std::vector<Vector> v);

      /**
       * Returns the Projection of Vector Q onto P
       */
        static Vector Proj(Vector p, Vector q);

      /**
       * Returns the component of P that is perpendicular to Q
       */
        static Vector Perp(Vector p, Vector q);

  private:
	  static float Cross(float a, float b);
	  static float Magnitude(Vector v);
      static float Dot(float a, float b);
      static float Product(float a, float b, float c);
      static Vector Projection(Vector p, Vector q);
      static Vector Perpendicular(Vector p, Vector q);
      static bool IsOrthonormal(Vector p, Vector q);
      static float Sqr(float a);
      static float Div(float a, float b);
      static Vector Mul(float a, Vector v);
      static Vector Less(Vector p, Vector q);
      static Vector More(Vector p, Vector q);



  };


#endif //MATH_MATH_H
