#ifndef EXCEPTIONS_NODENOTFOUND_H
#define EXCEPTIONS_NODENOTFOUND_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// NodeNotFound
/// 
/// # used by BinaryTree::find

#include "Exception.h"

namespace MathworkCPP
{
  namespace Exceptions
  {
    class NodeNotFound : public Exception
    {
      public:

        NodeNotFound() {};
        NodeNotFound(std::string message) {};
    };
  }
}

#endif EXCEPTIONS_NODENOTFOUND_H