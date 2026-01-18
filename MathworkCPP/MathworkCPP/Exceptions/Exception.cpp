//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// nie piszmy w opisie pliku rzeczy oczywistych

#include "Exception.h"

#include <string>

using namespace MathworkCPP::Exceptions;

bool Exception::isErrorRaised = false;
bool Exception::isWarningRaised = false;

//*****************************************************************************

/// 
/// empty constructor
/// 

Exception::Exception()
{
  this->message = "Attention! Un unknown problem has occured. "
    "Please close this program as safely as possible "
    "and try opening it again.";
}

//*****************************************************************************

/// 
/// 1 arg constructor
/// 

Exception::Exception(std::string message)
{
  this->message = message;
}

//*****************************************************************************
void Exception::IsErrorRaised(bool isError)
{
  Exception::isErrorRaised = isError;
}

//*****************************************************************************
bool Exception::IsErrorRaised()
{
  return Exception::isErrorRaised;
}

//*****************************************************************************
void Exception::IsWarningRaised(bool isWarning)
{
  Exception::isWarningRaised = isWarning;
}

//*****************************************************************************
bool Exception::IsWarningRaised()
{
  return Exception::isWarningRaised;
}

//*****************************************************************************
std::string Exception::Message()
{
  return this->message;
}