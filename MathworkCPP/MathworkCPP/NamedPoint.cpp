#include "NamedPoint.h"

using namespace MathworkCPP;

//*****************************************************************************

NamedPoint::NamedPoint(mapStringDouble point)
{
  int coordinatesIndex = 0;

  for (mapStringDouble::iterator ite = point.begin(); ite != point.end(); ite++)
  {
    this->names[coordinatesIndex] = ite->second;
    this->coordinates[coordinatesIndex] = ite->second;

    coordinatesIndex++;
  }
}

//*****************************************************************************

double& NamedPoint::operator[] (std::string name) const
{
  int index { this->lookupIndex(name) };

  double value { this->coordinates[index] };

  return value;
}

//*****************************************************************************

double& NamedPoint::operator[] (std::string name)
{
  int index { this->lookupIndex(name) };

  return this->coordinates[index];
}

//*****************************************************************************

NamedPoint NamedPoint::operator+(Point point) const
{
  point = Point(this->coordinates) + point;

  NamedPoint named { *this };

  for (int i = 0; i < point.countCoordinates(); i++)
  {
    named.setCoordinate(i, point[i]);
  }

  return named;
}

//*****************************************************************************

NamedPoint NamedPoint::operator-(Point point) const
{
  point = Point(this->coordinates) - point;

  NamedPoint named { *this };

  for (int i = 0; i < point.countCoordinates(); i++)
  {
    named.setCoordinate(i, point[i]);
  }

  return named;
}

//*****************************************************************************

vectorString NamedPoint::copyNames() const
{
  return this->names;
}

//*****************************************************************************

int NamedPoint::lookupIndex(std::string name) const
{
  for (int i = 0; i < this->names.size(); i++)
  {
    if (this->names[i] == name)
    {
      return i;
    }
  }
}

//*****************************************************************************

void NamedPoint::removeCoordinate(std::string name)
{
  int index { this->lookupIndex(name) };

  auto & coords { this->coordinates };
  auto & names { this->names};

  coords.erase(coords.begin() + index, coords.begin() + index + 1);
  names.erase(names.begin() + index, names.begin() + index + 1);
}

//*****************************************************************************

void NamedPoint::addCoordinate(pairStringDouble coordinate)
{
  this->names.push_back(coordinate.first);
  this->coordinates.push_back(coordinate.second);
}

//*****************************************************************************

void NamedPoint::setCoordinate(std::string name, double value)
{
  int index { this->lookupIndex(name) };

  this->coordinates[index] = value;
}