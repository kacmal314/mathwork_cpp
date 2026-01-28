#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ExpressionValidator
/// 
/// works on: Polynomial
/// works on: ExpressionType

#include "Polynomial.h"

#include "Enumerated/ExpressionType.h"
#include "Expression.h"

namespace MathworkCPP
{
  //-----------------------------------------------------------------------------
  class ExpressionValidator
  {

    public:

    static bool is(Expression const *expression, Enumerated::ExpressionType type);

    static bool isOnly(Expression const *expression, Enumerated::ExpressionType type);

    private:

    static bool isConstant(Expression const *expression);

  };

}
