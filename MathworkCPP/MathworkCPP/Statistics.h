

#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Statistics
/// 
/// # define common statistics function such as: max, argmax, etc

#include "Helper/declarations.h"

namespace MathworkCPP
{
  //-----------------------------------------------------------------------------
  class Statistics
  {
    public:

      static double                     max(vectorDouble reals);
      static int                        maxIndex(vectorDouble reals);
      static int                        minIndex(vectorDouble reals);

  };

}