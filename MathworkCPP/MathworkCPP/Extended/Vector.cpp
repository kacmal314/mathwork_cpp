//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "Vector.h"

using namespace MathworkCPP::Extended;

//*****************************************************************************

///
/// desc
///   input:  [1, 2, 3]
///   output: [3, 2, 1]
/// 

template <typename T>
std::vector<T> Vector::reverse(std::vector<T> toReverse)
{
  std::vector<T> reversed = toReverse;
  for (int i = 0; i < reversed.size() / 2; i++)
  {
    int tmp = reversed[i];
    reversed[i] = reversed[reversed.size() - 1 - i];
    reversed[reversed.size() - 1 - i] = tmp;
  }

  return reversed;
}