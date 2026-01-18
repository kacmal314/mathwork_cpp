//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "Random.h"

#include <cstdlib> // rand()

using namespace MathworkCPP;

//*****************************************************************************

///
/// min
///   inclusive
///   -Integer +Integer OK
/// end
///   exclusive
///   -Integer +Integer OK
/// 

int Random::randomInt(int min, int end)
{
  return rand() % ( (end) - (min) ) + min;
}