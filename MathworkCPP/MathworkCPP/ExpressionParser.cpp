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
  std::string validated { this->validate(expressionAsString) };

  BinaryTree localTree;

  return localTree;
}