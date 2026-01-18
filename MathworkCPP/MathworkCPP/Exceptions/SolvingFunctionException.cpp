//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "SolvingFunctionException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

SolvingFunctionException::SolvingFunctionException() : Exception()
{
  

  this->message = "Attention! I have encountered an unsolvable equation. "
    "Perhaps the used method is invalid, perhaps the input. "
    "Please ensure all a reasonable method is selected and all required inputs are in place.";
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

SolvingFunctionException::SolvingFunctionException(std::string message) : Exception(message)
{
  
}