//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>

#include "ExpressionValidator.h"

using namespace MathworkCPP;

//*****************************************************************************
bool ExpressionValidator::is(Expression const * expression,
                           Enumerated::ExpressionType type)
{
  return false;
}

//*****************************************************************************
bool ExpressionValidator::isOnly(Expression const * expression,
                               Enumerated::ExpressionType type)
{
  return false;
}

//*****************************************************************************
bool ExpressionValidator::isConstant(Expression const * expression)
{
  return false;
}