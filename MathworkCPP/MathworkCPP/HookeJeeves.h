#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// HookeJeeves
/// 
/// # implement direct search optimization algorithm called HookeJeeves Method
/// 
/// # return point of arguments (coordinates) that optimize function
/// 
/// Hooke-Jeeves Method
/// 
/// #0 Iteration: Pattern Move (initial 			point		) -> Exploratory Move
/// 
///			Pattern Move: here we actually dont move (Think: default parameter)
/// 
/// #N Iteration: Pattern Move (exploratory 	point #N-1) -> Exploratory Move
/// 
///			Pattern Move: here we use the pattern formula

#include "Constrainer.h";
#include "Polynomial.h";
#include "Point.h";

namespace MathworkCPP
{
	//-----------------------------------------------------------------------------
	class HookeJeeves
	{
		public:

			static Constrainer constrainer;
			static void setMaxIteration(int maxIteration);
			static double getDeltaDivisor();
			static void setDeltaDivisor(double deltaDivisor);
			static int getIterations();
			static Point findOptimum(Polynomial &poly, bool isMinimizing = true);
			static void setDelta(double delta);
        
      // delta of xi
			static void setStopDelta(double stopDelta);
				
      // initial point
      static void setPoint(Point initialPoint);

		private:

      HookeJeeves();

			static int iterations;
			static int maxIterations;
			static bool isMinimizing;
			static Polynomial *polynomial;
			static double deltaDivisor;
			static Point startPoint;

      // EXPLORATORY POINT k
			static Point pointNow;

      // EXPLORATORY POINT k-1
			static Point pointPre;

      // Useful: Reset Iteration
			static Point pointPrePre;

			static double initial_delta;
			static double delta;

      // epsilon
			static double stopDelta;

      // Is Optimum closer and closer ?
			static bool verify();

      // Pp = P2 + ( P2 - P1 )
			static Point patternize();

			static void explore(Point patternPoint);

	};
	
}

