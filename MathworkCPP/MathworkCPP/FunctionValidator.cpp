//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>

#include "FunctionValidator.h"

using namespace MathworkCPP;

//*****************************************************************************
bool FunctionValidator::is(Function const * function,
                           Enumerated::FunctionType type)
{
  return false;
}

//*****************************************************************************
bool FunctionValidator::isOnly(Function const * function,
                               Enumerated::FunctionType type)
{
  return false;
}

//*****************************************************************************
bool FunctionValidator::isConstant(Function const * function)
{
  return false;
}