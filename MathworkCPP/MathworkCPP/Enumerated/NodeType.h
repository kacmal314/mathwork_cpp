#ifndef ENUMERATED_NODETYPE_H
#define ENUMERATED_NODETYPE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// InputType
/// # models interface input type
/// # models user interface input type

namespace MathworkCPP
{
  namespace Enumerated
  {
    enum class NodeType : NodeTypeType
    {
      Null = 0x0,
      
      Constant = 0x1,

      Variable = 0x2,

      Operator = 0x4,

      Function = 0x8

    };

  }
  
}

#endif // ENUMERATED_NODETYPE_H