//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "ZeroDeterminantException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

ZeroDeterminantException::ZeroDeterminantException() : Exception()
{
  this->message = "Attention! Matrix's Determinant cannot be zero";
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

ZeroDeterminantException::ZeroDeterminantException(std::string message)
  : Exception(message)
{
  
}