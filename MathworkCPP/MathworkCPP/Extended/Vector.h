

#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Vector
/// # define static functions that work on std::vector

#include <vector>

namespace MathworkCPP
{
  namespace Extended
  {
    //-----------------------------------------------------------------------------

    ///
    /// Static Class
    /// # static keyword = sealed keyword
    ///

    class Vector
    {
      template <typename T>
      static std::vector<T> reverse(std::vector<T> toReverse);

    };

  }

}