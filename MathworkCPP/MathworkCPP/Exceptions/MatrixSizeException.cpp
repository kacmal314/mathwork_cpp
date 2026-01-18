//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "MatrixSizeException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

MatrixSizeException::MatrixSizeException() : Exception()
{
  
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

MatrixSizeException::MatrixSizeException(std::string message) : Exception(message)
{
  
}