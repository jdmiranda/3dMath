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
	 static float DotProduct(Vector p, Vector q);

	  /**
	   * Returns  a new vector that is perpendicular to both vectors being multiplied.
	   */
	 static Vector CrossProduct(Vector p, Vector q);

	  /**
	   * Returns the length/norm of a vector.
	   */
	  static float Mag(Vector v);

	  /**
	   * Returns true if for every pair (i,j) with i != j, and i dot j  = 0.
	   */
	  static bool IsOrthonormal(Vector p, Vector q);
      static bool IsOrthonormal(std::vector<Vector> v);

  private:
	  static float Cross(float a, float b);
	  static float Magnitude(Vector v);
      static float Dot(float a, float b);
      static float Product(float a, float b, float c);

  };


#endif //MATH_MATH_H
