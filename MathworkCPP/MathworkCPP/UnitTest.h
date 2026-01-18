

#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// UnitTest
/// 
/// # define static helpers for testing MathworkCPP

#include <string>

#include "Exceptions/SquareMatrixException.h"
#include "Exceptions/ZeroDeterminantException.h"
#include "Extended/String.h"
#include "Helper/declarations.h"
#include "Helper/definitions.h"
#include "ConsoleInterface.h"
#include "Filesystem.h"
#include "Matrix.h"
#include "Polynomial.h"
#include "Random.h"


namespace MathworkCPP
{
	class UnitTest
	{
		public:

			static void testInverseMatrix();
			static std::string testFilesystemClass();
			static std::string testMatrixClass();
      static std::string testRandomClass();
			static std::string testStringClass();

			
	};
	
}
