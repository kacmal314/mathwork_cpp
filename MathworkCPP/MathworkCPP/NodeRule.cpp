#include "NodeRule.h"

using namespace MathworkCPP;

//*****************************************************************************

void NodeRule::validate(const std::string & expressionAsString)
{
  std::regex regexRule {this->rule,
                        std::regex_constants::ECMAScript |
                        std::regex_constants::nosubs};

  std::sregex_iterator iterator {expressionAsString.begin(),
                                 expressionAsString.end(),
                                 regexRule};

  if (std::distance(iterator, std::sregex_iterator()) > 0)
  {
    throw Exceptions::ParserException(this->getErrorMessage());
  }

}