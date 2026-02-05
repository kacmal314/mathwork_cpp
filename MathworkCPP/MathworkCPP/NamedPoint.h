#ifndef NAMEDPOINT_H
#define NAMEDPOINT_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// NamedPoint
/// 
/// NamedPoint with * string member data * for coordinate names
/// 
/// # shadow Point member functions

#include "Helper/declarations.h"
#include "Point.h"

namespace MathworkCPP
{
  class NamedPoint : public Point
  {

  protected:

    vectorString names;

  public:

    // C++ shadows functions by name
    // bring base class's function back into scope
    using Point::setCoordinate;
    using Point::operator[];

    NamedPoint(mapStringDouble point = {});
    
		double& operator[] (std::string name) const;
		double& operator[] (std::string name);

    // Point::operator+ is shadowed (C++ shadows by name)
    NamedPoint operator+(Point point) const;
    NamedPoint operator-(Point point) const;
    
    vectorString copyNames() const;
    void removeCoordinate(std::string name);
    void addCoordinate(pairStringDouble coordinate);
    void setCoordinate(std::string name, double value);

  protected:

    int lookupIndex(std::string name) const;

  };

}

#endif // NAMEDPOINT_H