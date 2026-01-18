//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "PowerException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

PowerException::PowerException() : Exception()
{
  
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

PowerException::PowerException(std::string message) : Exception(message)
{
  
}