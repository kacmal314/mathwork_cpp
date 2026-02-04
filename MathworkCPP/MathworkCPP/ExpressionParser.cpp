#include "ExpressionParser.h"

using namespace MathworkCPP;



const ExpressionParser::precedenceLookups ExpressionParser::lookups {
  {
    // () -> calls pointer to OperatorNode
    {"^\\+", [](std::string data) -> Node* { return new OperatorNode("+"); } },
    {"^\\-", [](std::string data) -> Node* { return new OperatorNode("-"); } }
  },

  {
    {"^\\*", [](std::string data) -> Node* { return new OperatorNode("*"); } },
    {"^\\/", [](std::string data) -> Node* { return new OperatorNode("/"); } }
  },

  {
    {"^\\^", [](std::string data) -> Node* { return new OperatorNode("^"); } }
  },

  {
    {"^[s][i][n]", [](std::string data) -> Node* { return new FunctionNode("sin"); } },
    {"^[l][o][g]", [](std::string data) -> Node* { return new FunctionNode("log"); } }
  },

  //
  // variables and constants
  // have HIGHEST precedence
  // think: constant is integral -> independent of everything

  {
    // () -> calls pointer to VariableNode
    // VariableNode has the same precedence as ConstantNode
    // therefore it doesnt matter how we order them
    {"-?[0-9.]+"                  , [](std::string number)   -> Node* { return new ConstantNode(number);   } },
    {"^[a-zA-Z_][a-zA-Z0-9_]*"    , [](std::string variable) -> Node* { return new VariableNode(variable); } }
  }

};

//*****************************************************************************

bool ExpressionParser::is(Enumerated::ExpressionType type)
{
  return false;
}

//*****************************************************************************

bool ExpressionParser::isOnly(Enumerated::ExpressionType type)
{
  return false;
}

//*****************************************************************************

bool ExpressionParser::isConstant()
{
  return false;
}

//*****************************************************************************

std::string ExpressionParser::validate(std::string const & expressionAsString)
{
  ExpressionValidator validator;

  return validator.validate(expressionAsString);

}

//*****************************************************************************

int ExpressionParser::lookupSymbol(std::string & expression,
                                   int expressionIndex,
                                   BinaryTree & tree,
                                   int treeIndex,
                                   std::string const & symbol,
                                   factoryPointer const & lookup)
{
  std::regex symbolRegex {symbol, std::regex_constants::ECMAScript | std::regex_constants::nosubs};

  std::sregex_iterator iterator {expression.begin() + expressionIndex, expression.end(), symbolRegex};

  if ( iterator != std::sregex_iterator() )
  {
    // no match found

    std::smatch match {*iterator};

    std::string data {match.str(0)};

    tree.insert(lookup(data), treeIndex);

    return data.size();
  }

  return 0;

}

//*****************************************************************************

void ExpressionParser::parse(std::string validatedExpression,
                             BinaryTree & tree,
                             int treeIndex)
{
  if ( validatedExpression.empty() )
  {
    // [BASE CASE] base case
    // nothing more to parse
    // returning

    return;
  }

  for ( auto const & precedence : ExpressionParser::lookups )
  {
    for ( auto const & symbolLookup : precedence )
    {
      // *(std::string::begin) == '('
      if ( validatedExpression.front() == '(' && validatedExpression.back() == ')' )
      {
        // removing
        // 0  : "("
        // n-1: ")"
        Extended::String::shift(validatedExpression);
        validatedExpression.pop_back();
      }

      int parenthLevel {};

      for ( int i = 0; i < validatedExpression.length(); i++ )
      {
        if ( validatedExpression[i] == '(' )
        {
          parenthLevel++;
        }

        if ( validatedExpression[i] == ')' )
        {
          parenthLevel--;
        }

        if ( parenthLevel > 0 )
        {
          continue;
        }

        if ( int symbolLength = this->lookupSymbol(validatedExpression, i, tree, treeIndex,
                                symbolLookup.first, symbolLookup.second) )
        {
          //
          // std::string::substr returns new string
          // parse expects: std::string
          //
          // indeks iteracyjny jest jednoczesnie DLUGOSCIA
          // od poczatku string-a (bez elementu pod tym indeksem)
          std::string leftSubstring {validatedExpression.substr(0, i)};
          this->parse(leftSubstring, tree, 2 * treeIndex + 1);

          std::string rightSubstring {validatedExpression.substr(i + symbolLength, std::string::npos)};
          this->parse(rightSubstring, tree, 2 * treeIndex + 2);

          // [BASE CASE] base case
          // node inserted @ given index
          // left child and right child called
          // returning

          return;

        } // if lookupSymbol

      } // for i

    } // for symbolLookup

  } // for precedence

}

//*****************************************************************************

BinaryTree ExpressionParser::parse(const std::string & expressionAsString)
{
  std::string validated {this->validate(expressionAsString)};

  BinaryTree localTree {};

  this->parse(validated, localTree);

  return localTree;
}