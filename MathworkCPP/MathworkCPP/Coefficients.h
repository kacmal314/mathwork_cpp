#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Coefficients
/// 
/// # provide better control over arrays of coefficients
/// 
/// # used by Polynomial

#include "Helper/declarations.h"

namespace MathworkCPP
{
	//-----------------------------------------------------------------------------
	class Coefficients
	{
		public:

			void          Add(double element);
			void          Clear();
			int           Count();

			double &        operator[](size_t index);
			const double &  operator[](size_t index) const;

      Coefficients() = default;
      Coefficients(vectorDouble init) : coefficients(init) {};

		private:
				
			vectorDouble coefficients;
	};

}
