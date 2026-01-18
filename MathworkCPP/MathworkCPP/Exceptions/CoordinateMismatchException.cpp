//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "CoordinateMismatchException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

CoordinateMismatchException::CoordinateMismatchException() : CoordinateException()
{
  
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

CoordinateMismatchException::CoordinateMismatchException(std::string message)
  : CoordinateException(message)
{
  
}



//*****************************************************************************

///
/// 
/// 

void CoordinateMismatchException::act()
{
  // resolve ...

  Exception::IsErrorRaised(false);

}