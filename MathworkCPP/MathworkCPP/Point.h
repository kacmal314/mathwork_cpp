#ifndef POINT_H
#define POINT_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Point
/// 
/// # store N real coordinates (real numbers)
/// # not ComplexPoint

#include "Helper/declarations.h"

namespace MathworkCPP
{
	//-----------------------------------------------------------------------------

	class Point
	{
		protected:

			vectorDouble coordinates;

		public:

      Point() = default;
      Point(vectorDouble coordinates);
      
      // when object is constant
			double& operator[] (size_t index) const;
			double& operator[] (size_t index);
			Point operator- (Point point) const;
			Point operator+ (Point point) const;

			void constrain(vectorDouble starts, vectorDouble stops);
			vectorDouble copyCoordinates();
			int countCoordinates() const;
			void removeCoordinate(int index);
      void setCoordinate(int index, double value);
			void addCoordinate(double coord);

	};
	
}

#endif // POINT_H
