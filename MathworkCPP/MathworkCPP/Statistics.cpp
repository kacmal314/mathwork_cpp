//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "Statistics.h"

#include <stdexcept>

using namespace MathworkCPP;

//*****************************************************************************
double Statistics::max(vectorDouble reals)
{
  try
  {

    double max = reals[0];

    for (auto elem : reals)
    {
      if (elem > max)
      {
        max = elem;
      }

    }

    return max;

  }

  catch (std::out_of_range e)

  {

  }
}

//*****************************************************************************
int Statistics::maxIndex(vectorDouble reals)
{
  if (reals.size() <= 0)
  {
    throw std::out_of_range("");
  }

  int maxI    = 0;

  double max  = reals[maxI];

  for (int i = 0; i < reals.size(); i++)
  {
    if (reals[i] > max)
    {
      max = reals[i];
      maxI = i;
    }
  }

  return maxI;

}

//*****************************************************************************
int Statistics::minIndex(vectorDouble reals)
{
  if (reals.size() <= 0)
  {
    throw std::out_of_range("");
  }

  int minI 		= 0;

  double min  = reals[minI];

  for (int i = 0; i < reals.size(); i++)
  {
    if (reals[i] < min)
    {
      min = reals[i];
      minI = i;
    }
  }

  return minI;

}