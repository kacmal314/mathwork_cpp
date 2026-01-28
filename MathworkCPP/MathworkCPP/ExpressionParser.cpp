#include "ExpressionParser.h"

using namespace MathworkCPP;

//*****************************************************************************

std::string ExpressionParser::preprocess(const std::string & expressionAsString)
{
  std::string trimmed { Extended::String::removeWhiteCharacters(expressionAsString) };

  return trimmed;
}

//*****************************************************************************

BinaryTree ExpressionParser::parse(const std::string & expressionAsString)
{
  this->validate(expressionAsString);

  std::string preprocessed = this->preprocess(expressionAsString);

  BinaryTree localTree;


}