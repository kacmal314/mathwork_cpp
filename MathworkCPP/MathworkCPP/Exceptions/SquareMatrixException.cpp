//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "SquareMatrixException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

SquareMatrixException::SquareMatrixException() : Exception()
{
  

  this->message = "# of Columns and # of Rows have to be equal";
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

SquareMatrixException::SquareMatrixException(std::string message) : Exception(message)
{
  
}