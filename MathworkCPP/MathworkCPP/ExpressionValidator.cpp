//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>

#include "ExpressionValidator.h"

using namespace MathworkCPP;

//*****************************************************************************

std::string ExpressionValidator::preprocess(const std::string & expressionAsString)
{
  std::string trimmed { Extended::String::removeWhiteCharacters(expressionAsString) };

  return trimmed;
}

//*****************************************************************************

std::string ExpressionValidator::validate(const std::string & expressionAsString)
{
  std::string preprocessed { this->preprocess(expressionAsString) };

  for (auto rule : this->rules)
  {
    rule.validate(preprocessed);
  }

  return preprocessed;

}