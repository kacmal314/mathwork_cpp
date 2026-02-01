#ifndef EXPRESSIONPARSER_h
#define EXPRESSIONPARSER_h

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ExpressionParser
/// 
/// # define expression parsing

#include <map>
#include <vector>
#include <string>
#include <functional> // function, unique_ptr

#include "FunctionNode.h"
#include "OperatorNode.h"
#include "Extended/String.h"
#include "Helper/declarations.h"
#include "Enumerated/ExpressionType.h"
#include "ExpressionValidator.h"
#include "BinaryTree.h"

namespace MathworkCPP
{

  //-----------------------------------------------------------------------------

  //
  // parsing is not: removing whitespace
  // parsing is not: preprocessing

  class ExpressionParser
  {
    // std::any_callable<return_type>
    // () -> means return type is pointer to callable function
    // using factory = std::function<std::unique_ptr<Node>(void)>;
    
    // procedure pointer returning Node*
    using mapStringFactory = std::map<std::string, Node* (*) (void)>;

    using precedenceLookups = std::vector<mapStringFactory>;

    ///
    /// inverse precedence
    /// 
    /// # 0: +, -
    /// 
    /// # 1: *, /
    /// 
    /// ...
    
    precedenceLookups lookups {
      {
        // () -> calls pointer to OperatorNode
        {"+", [] (void) -> Node* { return new OperatorNode(); } },
        {"-", [] (void) -> Node* { return new OperatorNode(); } }
      },

      {
        {"*", [] (void) -> Node* { return new OperatorNode(); } },
        {"/", [] (void) -> Node* { return new OperatorNode(); } }
      },

      {
        {"/", [] (void) -> Node* { return new OperatorNode(); } }
      },

      {
        {"sin", [] (void) -> Node* { return new FunctionNode(); } },
        {"log", [] (void) -> Node* { return new FunctionNode(); } }
      }

    };

  public:

    BinaryTree parse(const std::string &expressionAsString);

    bool is(Enumerated::ExpressionType type);

    bool isOnly(Enumerated::ExpressionType type);

  private:

    std::string validate(const std::string &expressionAsString);

    bool isConstant();
  };
}

#endif // EXPRESSIONPARSER_h
