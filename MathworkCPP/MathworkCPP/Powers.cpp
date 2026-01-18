//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "Powers.h"

#include "Exceptions/PowerException.h"

using namespace MathworkCPP;

//*****************************************************************************

// CONSTRUCTOR

Powers::Powers()
{
  
}

//*****************************************************************************

// CONSTRUCTOR + INITIALIZER LIST

Powers::Powers(initializerNullableDouble init)
{
  // Check if ok ...

  for (auto element : init)
  {
    if (element < 0.0)
    {
      // ... Cancel initialization if bad ...
      throw Exceptions::PowerException("The Power doesn't exist, bad index");

    }

  }

  // ... Initialize if good

  for (auto element : init)
  {
    powers.push_back(element);

  }

}

//*****************************************************************************

void Powers::Add(nullableDouble element)
{
	if (element < 0.0)
	{
    throw Exceptions::PowerException("The Power doesn't exist, bad index");

	}

	this->powers.push_back(element);

}

//*****************************************************************************

void Powers::Clear()
{
	this->powers.clear();

}

//*****************************************************************************

int Powers::Count()
{
	return this->powers.size();

}

//*****************************************************************************

vectorNullableDouble Powers::getPowers()
{
  return this->powers;
}

//*****************************************************************************

// size_t = unsigned (compiler-dependent) integer

double& Powers::operator[](size_t index)
{
	if (index < 0 || index >= powers.size())
	{
    throw Exceptions::PowerException("The Power doesn't exist, bad index");

	}

	return *(powers[index]);

}

//*****************************************************************************

// CONST REFERENCE at NORMAL OBJECT

const double& Powers::operator[](size_t index) const
{
	if (index < 0 || index >= powers.size())
	{
    throw Exceptions::PowerException("The Power doesn't exist, bad index");

	}

	return *(powers[index]);

}
