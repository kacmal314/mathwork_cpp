#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Convert
/// 
/// # handle standard type conversions
/// 
/// # handle program-specific type dilemmas

#include <map>
#include <initializer_list>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <optional>

#include "Node.h"
#include "Exceptions/Exception.h"
#include "Helper/declarations.h"

namespace MathworkCPP
{
	//-----------------------------------------------------------------------------
	class Convert
	{
		public:

      static vectorDouble toVectorDouble(Node::vectorNodep nodep);

      template <typename Tkey, typename Tvalue>
      static std::map<Tkey, Tvalue> toMap(
        // std::pair has first argument "const"
        // otherwise: compiler error
        std::initializer_list<std::pair<const Tkey, Tvalue>> initializer)
      {
        return std::map<Tkey, Tvalue>(initializer);
      }

      static vectorDouble toArrayDouble(vectorComplexDouble complexArray, bool isReal);
			static vectorDouble toNotNull(vectorNullableDouble nulls);

			static std::string toLower(std::string str);

			static double toNumber(std::string str);

	};
	
}

