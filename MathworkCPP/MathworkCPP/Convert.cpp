#ifndef CONVERT_H
#define CONVERT_H

#include "Convert.h"

using namespace MathworkCPP;

//*****************************************************************************

vectorDouble Convert::toNotNull(vectorNullableDouble nullables)
{
  vectorDouble doubles {};

  for (auto const & nullable : nullables)
  {
    if (nullable != std::nullopt)
    {
      doubles.push_back(*nullable);
    }
  }

  return doubles;
}

//*****************************************************************************

std::string Convert::toLower(std::string str)
{
  std::transform(str.begin(), str.end(), str.begin(),
                 // chatgpt: best use "unsigned char" here
                 [](unsigned char const & ch) { return std::tolower(ch); });

  // return copy
  return str;
}

//*****************************************************************************

double Convert::toNumber(std::string str)
{
  double number {};

  try
  {
    number = std::stod(str);
  }
  catch (std::invalid_argument const & exception)
  {
    throw Exceptions::Exception("cannot convert \"" + str.substr(0, 16) + "\" to double");
  }

  return number;
}

//*****************************************************************************

vectorDouble Convert::toArrayDouble(vectorComplexDouble complexArray, bool isReal)
{
  vectorDouble doubles {};

  for (auto const & _complex : complexArray)
  {

    if (isReal)
    {
      doubles.push_back(_complex.real());
    }
    else
    {
      doubles.push_back(_complex.imag());
    }
  }

  return doubles;
}

#endif // CONVERT_H