//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "../Helper/declarations.h"
#include "PolynomialDegreeException.h"

#include <string>

using namespace MathworkCPP::Exceptions;

//*****************************************************************************

/// 
/// empty constructor
/// 

PolynomialDegreeException::PolynomialDegreeException() : Exception()
{
  

  std::string message = "Attention! A polynomial has been found with an invalid degree. "
    "It appears the program may not recognize the calculated degree. "
    " Please ensure you're including all data and the data seems correct for your calculation purposes";
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

PolynomialDegreeException::PolynomialDegreeException(std::string message) : Exception(message)
{
  
}