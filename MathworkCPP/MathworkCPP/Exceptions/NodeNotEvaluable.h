#ifndef EXCEPTIONS_NODENOTEVALUABLE_H
#define EXCEPTIONS_NODENOTEVALUABLE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// NodeNotEvaluable

#include "Exception.h"

namespace MathworkCPP
{
  namespace Exceptions
  {
    class NodeNotEvaluable : public Exception
    {
      public:

        NodeNotEvaluable() {};
        NodeNotEvaluable(std::string message) {};
    };
  }
}

#endif EXCEPTIONS_NODENOTEVALUABLE_H