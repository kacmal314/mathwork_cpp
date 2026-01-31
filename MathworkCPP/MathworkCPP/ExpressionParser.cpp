#include "ExpressionParser.h"

using namespace MathworkCPP;

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

std::string ExpressionParser::validate(const std::string & expressionAsString)
{
  ExpressionValidator validator;

  return validator.validate(expressionAsString);

}

//*****************************************************************************

BinaryTree ExpressionParser::parse(const std::string & expressionAsString)
{
  if (expressionAsString.empty())
  {
    return BinaryTree();
  }

  std::string validated { this->validate(expressionAsString) };
  
  BinaryTree localTree;

  for (auto const & precedenceLevel : this->symbolArrays)
  {
    for (auto const & symbol : precedenceLevel)
    {
      // *(std::string::begin) == '('
      if (validated.front() == '(' && validated.back() == ')')
      {
        // removing
        // 0  : "("
        // n-1: ")"
        Extended::String::shift(validated);
        validated.pop_back();
      }

      int parenthLevel {};

      for (int i = 0; i < validated.length(); i++)
      {
        if (validated[i] == '(')
        {
          parenthLevel++;
        }

        if (validated[i] == ')')
        {
          parenthLevel--;
        }

        if (parenthLevel > 0)
        {
          continue;
        }

        if (validated.substr(i, symbol.length()) == symbol)
        {
          // 
        }

      }

    }

  }

  return localTree;
}