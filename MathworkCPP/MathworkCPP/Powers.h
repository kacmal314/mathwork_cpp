#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Powers
/// 
/// # provide better control over arrays of powers
/// 
/// # used by Polynomial

#include "Helper/declarations.h"

namespace MathworkCPP
{
  //-----------------------------------------------------------------------------
  class Powers
  {
    public:

    Powers();

    // INITIALIZER LIST
    Powers(initializerNullableDouble init);

    void Add(nullableDouble element);
    void Clear();
    int Count();
    vectorNullableDouble getPowers();
    double &operator[](size_t index); // (A) should return primitive: double
    const double &operator[](size_t index) const;
    private:

    vectorNullableDouble powers; // (A) should contain primitives: double


  };

}

