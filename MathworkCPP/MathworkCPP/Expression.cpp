#include "Expression.h"

using namespace MathworkCPP;

//*****************************************************************************

Expression::Expression(std::string const & expressionAsString)
  : expressionAsString(expressionAsString)
  , expressionAsTree(this->parser.parse(this->expressionAsString)) {}

//*****************************************************************************

double Expression::evaluate(NamedPoint variables)
{
  this->expressionAsTree.postorder(2); // x

  return 0;
}
