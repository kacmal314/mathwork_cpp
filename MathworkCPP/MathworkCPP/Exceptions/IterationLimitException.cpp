//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "IterationLimitException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

IterationLimitException::IterationLimitException() : Exception()
{
  
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

IterationLimitException::IterationLimitException(std::string message) : Exception(message)
{
  this->message = "Iterations Limit reached, precision compromised";
}