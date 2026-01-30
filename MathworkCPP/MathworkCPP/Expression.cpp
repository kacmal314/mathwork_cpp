#include "Expression.h"

using namespace MathworkCPP;

//*****************************************************************************

Expression::Expression(std::string const & expressionAsString)
  : expressionAsString(expressionAsString)
  , expressionAsTree(this->parser.parse(this->expressionAsString)) {}

//*****************************************************************************

double Expression::evaluate(Point X)
{
  return 0;
}
