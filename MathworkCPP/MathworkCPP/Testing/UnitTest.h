#ifndef UNITTEST_H
#define UNITTEST_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// UnitTest

#include <string>

#include "../ConsoleInterface.h"
#include "../Helper/declarations.h"
#include "../Helper/definitions.h"

namespace MathworkCPP
{
  namespace Testing
  {
	  class UnitTest
	  {
		  public:

        virtual void test() = 0;
	  };
  }
}

#endif // UNITTEST_H
