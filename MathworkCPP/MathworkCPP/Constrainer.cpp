//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "Constrainer.h"

#include <stdexcept>

using namespace MathworkCPP;

//-----------------------------------------------------------------------------
// CONSTRAINER

//*****************************************************************************
Constrainer::Constrainer()
{
	// This Constructor is obligatory - Programmer discretion is advised

}

//*****************************************************************************
Constrainer::~Constrainer()
{
	// Garbage Collected
	if (isVariableApplicable != nullptr)
  {
    delete[] isVariableApplicable;
  }

}

//*****************************************************************************
bool Constrainer::getIsVariableApplicable(int index)
{
	if (index >= variableStarts.size())
	{
		throw std::out_of_range("");
	}

	return isVariableApplicable[index];

}

//*****************************************************************************
void Constrainer::setIsVariableApplicable(int iSize)
{
	// Garbage Collected
	if (isVariableApplicable != nullptr)
  {
    delete[] isVariableApplicable;
  }

	// Re-allocate variables-space memory
	isVariableApplicable = new bool[iSize];

	// set index
	index = 0;

}

//*****************************************************************************
void Constrainer::addIsVariableApplicable(bool isApplicable)
{
	if (index >= variableStarts.size())
	{
		// Handle Constrainer IndexOutOfRange ...
    throw std::out_of_range("");
	}

	// add applicability information
	isVariableApplicable[index] = isApplicable;

	// offset index
	index++;

}
