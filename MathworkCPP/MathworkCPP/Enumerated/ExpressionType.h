#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ExpressionType
/// # work with ExpressionValidator

namespace MathworkCPP
{
  namespace Enumerated
  {
    //-----------------------------------------------------------------------------
    enum class ExpressionType : int
    {
      // EG: 0
      Constant = 0x0,

      // EG: x^2
      Polynomial = 0x1,

      // EG: x
      Linear = 0x2,

      // EG: x^2
      Quadratic = 0x4,

      // EG: x^3
      Cubic = 0x8,

      // EG: X^4
      Quartic = 0x10,

      // useless, no root formulas
      // Quintic
      
      // EG: sin(x)
      Trigonometric = 0x11,

      // EG: sin(X) + x^4
      Mixed = 0x12
    };

  }

}