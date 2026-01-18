#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Convert
/// # handle standard type conversions
/// # handle program-specific type dilemmas

#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <optional>

#include "Exceptions/Exception.h"
#include "Helper/declarations.h"

namespace MathworkCPP
{
	//-----------------------------------------------------------------------------
	class Convert
	{
		public:

			static vectorDouble toNotNull(vectorNullableDouble nulls);
			static std::string toLower(std::string str);
			static double toNumber(std::string str);
      static vectorDouble toArrayDouble(vectorComplexDouble complexArray, bool isReal);

	};
	
}

