#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Function
/// 
/// # model multivariable mathematical function

#include "Point.h"

namespace MathworkCPP
{
  class Function
  {
    public:

    virtual double f(Point X);

  };
}
