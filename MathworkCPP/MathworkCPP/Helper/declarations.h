#pragma once

#include <complex>
#include <initializer_list>
#include <map>
#include <string>
#include <vector>
#include <optional>

//
// namespace DEFINITIONS
//

namespace MathworkCPP { namespace Exceptions {} }
namespace MathworkCPP { namespace Enumerated {} }
namespace MathworkCPP { namespace Extended {} }

//
// type DECLARATIONS
//

using complexDouble  	= std::complex<double>;

using mapCharBool  	= std::map<char, bool>;       // variables in expressions may be null - non-existing
using pairCharBool 	= std::pair<char, bool>;      // C++ doesnt provide primitive null datatypes
                                                  // solution: auxiliary activity variable
                                                  // Think: Maths/Optimization/Parser::class

using mapCharString 	= std::map<char, std::string>;
using pairCharString 	= std::pair<char, std::string>;

using mapStringDouble 	= std::map<std::string, double>;
using pairStringDouble 	= std::pair<std::string, double>;

using mapStringString 	= std::map<std::string, std::string>;
using pairStringString 	= std::pair<std::string, std::string>;

using vectorString = std::vector<std::string>;
using vector2String = std::vector<vectorString>;

using vectorBool = std::vector<bool>;
using vector2Bool = std::vector<vectorBool>;

using vectorDouble = std::vector<double>;
using nullableDouble = std::optional<double>;
using vectorNullableDouble = std::vector<nullableDouble>;
using vector2Double = std::vector<vectorDouble>;

using vectorInt = std::vector<int>;
using vector2Int = std::vector<vectorInt>;

using vectorComplexDouble = std::vector<complexDouble>;

using initializerDouble = std::initializer_list<double>;
using initializerNullableDouble = std::initializer_list<nullableDouble>;
using initializerDoubleIterator = std::initializer_list<double>::iterator;
using initializerVectorDouble = std::initializer_list<vectorDouble>;

//
// global DECLARATIONS
//

#define TESTING 1
#define RUNTIME 2
#define DEBUG 3

#define MODE RUNTIME