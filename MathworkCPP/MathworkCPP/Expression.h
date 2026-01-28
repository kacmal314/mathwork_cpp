#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Expression
/// 
/// # model multivariable mathematical expression

#include <string>

#include "Point.h"

namespace MathworkCPP
{
  class Expression
  {

    std::string expression {};

  public:

    virtual double evaluate(Point X);

  };
}
