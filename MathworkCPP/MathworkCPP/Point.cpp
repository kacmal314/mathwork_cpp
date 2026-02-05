#include <stdexcept>

#include "Point.h"
#include "Exceptions/CoordinateMismatchException.h"

using namespace MathworkCPP;

//*****************************************************************************
Point::Point()
{

}

//*****************************************************************************

Point::Point(vectorDouble coordinates)
{
  int coordinatesIndex = 0;

  for (vectorDouble::iterator ite = coordinates.begin(); ite != coordinates.end(); ite++)
  {
    this->coordinates[coordinatesIndex++] = *ite;
  }
}

//*****************************************************************************

double& Point::operator[] (size_t index) const
{
  double value { this->coordinates[index] };

  return value;
}

//*****************************************************************************

double& Point::operator[] (size_t index)
{
  return this->coordinates[index];
}

//*****************************************************************************

Point Point::operator- (Point point) const
{
	Point pointReturning;

	if (this->countCoordinates() != point.countCoordinates())
	{
    //
    // throw r-value not x-value
    //
    // compare:
    // Exception::CoordinateException myException = Exception::CoordinateException();
    // throw myException
    throw Exceptions::CoordinateMismatchException();
	}

	for (int i = 0; i < this->countCoordinates(); i++)
  {
    pointReturning.addCoordinate(this->coordinates[i] - point.coordinates[i]);
  }

	return pointReturning;

}

//*****************************************************************************

Point Point::operator+ (Point point) const
{
	Point pointReturning;

	if (this->countCoordinates() != point.countCoordinates())
	{
    throw Exceptions::CoordinateMismatchException();
	}

	for (int i = 0; i < this->countCoordinates(); i++)
  {
    pointReturning.addCoordinate(this->coordinates[i] + point.coordinates[i]);
  }

	return pointReturning;

}

//*****************************************************************************
// constrain type: clamp
void Point::constrain(vectorDouble starts, vectorDouble stops)
{
	if (starts.size() != stops.size())
	{
		// Handle unmatched vector sizes ...

	}

	// Starts Stops sizes match !

	if (starts.size() != coordinates.size())
	{
		// Handle unmatched constain-point coordinates ...

	}

	// Coordinates match !

	for (int i = 0; i < coordinates.size(); i++)
	{ // Constrain Each Coordinate

		// constrain lower bound
		if (coordinates[i] < starts[i])
			coordinates[i] = starts[i];

		// constain upper bound
		if (coordinates[i] > stops[i])
			coordinates[i] = stops[i];

	} // fori

}

//*****************************************************************************
vectorDouble Point::copyCoordinates()
{
	return coordinates;
}

//*****************************************************************************
void Point::setCoordinate(int index, double value)
{
	coordinates[index] = value;
}

//*****************************************************************************
int Point::countCoordinates() const
{
	return coordinates.size();
}

//*****************************************************************************
void Point::removeCoordinate(int index)
{
	if (index >= coordinates.size())
	{
    throw std::out_of_range("");
	}

	// REMOVE i-ELEMENT, RESIZE
	coordinates.erase(coordinates.begin() + index);

}

//*****************************************************************************
void Point::addCoordinate(double coord)
{
	coordinates.push_back(coord);
}
