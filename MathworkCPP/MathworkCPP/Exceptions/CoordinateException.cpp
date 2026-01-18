//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "CoordinateException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

CoordinateException::CoordinateException() : Exception()
{
  
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

CoordinateException::CoordinateException(std::string message) : Exception(message)
{
  
}