#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Filesystem
/// 
/// # wrap around: std::fstream

// include one and access everybody
// BAD IDEA: NOTE: SELF-INCLUSION
// #include "../MathworkCPP.h"

#include <string>

namespace MathworkCPP
{
  class Filesystem
  {
    ///////////////////////////////////////////////////////////////////////////////
    // PUBLIC

    public:

      static std::string          filename(std::string path, bool withExtension = true);
  };
}