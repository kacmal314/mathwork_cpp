#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// FunctionValidator
/// 
/// works on: Polynomial
/// works on: FunctionType

#include "Polynomial.h"

#include "Enumerated/FunctionType.h"
#include "Function.h"

namespace MathworkCPP
{
  //-----------------------------------------------------------------------------
  class FunctionValidator
  {

    public:

    static bool is(Function const *function, Enumerated::FunctionType type);

    static bool isOnly(Function const *function, Enumerated::FunctionType type);

    private:

    static bool isConstant(Function const *function);

  };

}
