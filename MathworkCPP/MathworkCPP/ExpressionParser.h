#ifndef EXPRESSIONPARSER_h
#define EXPRESSIONPARSER_h

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ExpressionParser
/// 
/// # define expression parsing

#include <regex>
#include <map>
#include <vector>
#include <string>
#include <functional> // function, unique_ptr

#include "ConstantNode.h"
#include "VariableNode.h"
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

    using factoryPointer = Node* (*) (std::string);
    
    // procedure pointer returning Node*
    using mapStringFactory = std::map<std::string, factoryPointer>;

    using precedenceLookups = std::vector<mapStringFactory>;

    ///
    /// precedence
    /// 
    /// # 0: +, -   LOWEST PRECEDENCE
    /// 
    /// # 1: *, /   HIGHER PRECEDENCE
    /// 
    /// ...
    
    static const precedenceLookups lookups;

  public:

    BinaryTree parse(std::string const & expressionAsString);

    bool is(Enumerated::ExpressionType type);

    bool isOnly(Enumerated::ExpressionType type);

  private:

    ///
    /// returns: symbol length if found
    /// 
    /// * otherwise: 0

    int lookupSymbol(std::string & expression,
                      int expressionIndex,
                      BinaryTree & tree,
                      int treeIndex,
                      std::string const & symbol,
                      factoryPointer const & lookup);

    void parse(std::string validatedExpression,
               BinaryTree & tree,
               int treeIndex = 0);

    std::string validate(std::string const & expressionAsString);

    bool isConstant();
  };
}

#endif // EXPRESSIONPARSER_h
