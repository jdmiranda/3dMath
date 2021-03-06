//
// Created by JEREMY Miranda on 4/18/16.
//

#ifndef MATH_MATH3D_H
#define MATH_MATH3D_H


#include "Vector.h"
#include <vector>
#include <math.h>

  class Math3D {
public:

	  /**
	   * Returns a measure of difference between the directions in which two vectors point. cos a
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

      /**
       * Returns a scalar vector.
       */
      static Vector Mul(float a, Vector v);

      /**
       * Returns the difference between two vectors.
       */
      static Vector Less(Vector p, Vector q);

      /**
       * Returns the result of two vectors.
       */
      static Vector Sum(Vector p, Vector q);
/*
 *
 * Returns the orthonormal basis for the set using the Gram-Schmidt Orthogonalization
 */
      static std::vector<Vector> MakeOrthoNormal(std::vector<Vector> collection);
      static float Sum(Vector v);
      static Vector Normalize(Vector v);


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

      static float Sqr(Vector v);
  };


#endif //MATH_MATH3D_H
