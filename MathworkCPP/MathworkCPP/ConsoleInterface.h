#pragma once

#include <string>

#include "Matrix.h"
#include "Interface.h"

namespace MathworkCPP
{

  class ConsoleInterface : Interface
  {
    public:

      void                  log(std::string message = "", bool prependNewLine = false);
      std::string           read();

    private:

      void                  clear();
  };

}
