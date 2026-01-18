#pragma once

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
		///////////////////////////////////////////////////////////////////////////////
		public:

      Point();
      Point(initializerDouble init);

			void                constrain(vectorDouble starts, vectorDouble stops);
			vectorDouble        getCoordinates();
			void                setCoordinate(int index, double value);
			Point               operator- (Point point);
			Point               operator+ (Point point);
			int            			countCoordinates();
			void                removeCoordinate(int index);
			double            	getCoordinate(int index);
			void                addCoordinate(double coord);

		///////////////////////////////////////////////////////////////////////////////
		protected:

		///////////////////////////////////////////////////////////////////////////////
		private:

			vectorDouble        coordinates;

	};
	
}

