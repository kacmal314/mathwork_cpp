//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "Helper/declarations.h"
#include "Coefficients.h"

#include <stdexcept>

using namespace MathworkCPP;

//*****************************************************************************
void Coefficients::Add(double element)
{
	coefficients.push_back(element);

}

//*****************************************************************************
void Coefficients::Clear()
{
	coefficients.clear();

}

//*****************************************************************************
int Coefficients::Count()
{
	return this->coefficients.size();

}

//*****************************************************************************
double& Coefficients::operator[](size_t index)
{
	if (index < 0 || index >= coefficients.size())
	{
    throw std::out_of_range("Attention! Cannot access Coefficient that doesn't exist "
      "It doesn't mean the program always malfunctions at this operation "
      "Please, simply close, open, and try whatever task again");
	}

	return coefficients[index];

}

//*****************************************************************************
const double& Coefficients::operator[](size_t index) const
{
	if (index < 0 || index >= coefficients.size())
	{
    throw std::out_of_range("Attention! Cannot access coefficient that doesn't exist "
      "It doesn't mean the program always malfunctions at this operation "
      "Please, simply close, open, and try whatever task again");
	}

	return coefficients[index];

}
