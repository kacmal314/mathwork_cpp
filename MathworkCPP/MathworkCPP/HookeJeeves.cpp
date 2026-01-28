//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "HookeJeeves.h"

#include "Exceptions/IterationLimitException.h"
#include "Statistics.h"

using namespace MathworkCPP;

//-----------------------------------------------------------------------------
// HOOKEJEEVES

Constrainer HookeJeeves::constrainer {};
int HookeJeeves::iterations;                // not iteration ID, iteration #, how many iterations
int HookeJeeves::maxIterations {1000};      // max iterations
bool HookeJeeves::isMinimizing {true};
Polynomial *HookeJeeves::polynomial {nullptr};     // pointer refers both class and member
double HookeJeeves::deltaDivisor {1.5};
Point HookeJeeves::startPoint;
Point HookeJeeves::pointNow;
Point HookeJeeves::pointPre;
Point HookeJeeves::pointPrePre;
double HookeJeeves::initial_delta {1};
double HookeJeeves::delta {HookeJeeves::initial_delta};
double HookeJeeves::stopDelta {0.001};         // epsilon

//*****************************************************************************
// static class
HookeJeeves::HookeJeeves()
{

}

//*****************************************************************************
void HookeJeeves::setMaxIteration(int maxIteration)
{
  //        this->deltaDivisor
  // static this->deltaDivisor ?
  HookeJeeves::maxIterations = maxIteration;
}

//*****************************************************************************
double HookeJeeves::getDeltaDivisor()
{
  return deltaDivisor;
}

//*****************************************************************************
void HookeJeeves::setDeltaDivisor(double deltaDivisor)
{
  //        this->deltaDivisor
  // static this->deltaDivisor ?
  HookeJeeves::deltaDivisor = deltaDivisor;
}

//*****************************************************************************
// accessor - how many iterations on last findOptimum() ?
int HookeJeeves::getIterations()
{
  return iterations;
}

//*****************************************************************************
Point HookeJeeves::findOptimum(Polynomial &poly, bool isMinimizing)
{
  HookeJeeves::polynomial = &poly;
  HookeJeeves::isMinimizing = isMinimizing;
  HookeJeeves::iterations = 0;
  HookeJeeves::delta = HookeJeeves::initial_delta;  // reset delta to user-input
                                            // every optimum call

  // Reset Points
  HookeJeeves::pointNow = HookeJeeves::startPoint;
  HookeJeeves::pointPre = HookeJeeves::startPoint;
  HookeJeeves::pointPrePre = HookeJeeves::startPoint;

  while ( delta > stopDelta && ++iterations <= maxIterations )
  {
    explore(patternize());          // (A) Exploration ends the Method

    if ( ! verify() )                 // do I need to react ?
    {
      // #1 (A)
      pointNow = pointPre;          // Reset Iteration // First Pattern Move is special
      // #2
      pointPre = pointPrePre;       // Reset Iteration // First Pattern Move is special
      delta /= deltaDivisor * 1.0;  // assert / double

      // (A) Re-Explore Previous Point
      explore(pointNow);

    }

    // Constrain Point ?
    if ( constrainer.isConstrainerApplicable )
    { // yes
      for ( int i = 0; i < poly.countVariables(); i++ )
      { // watch which to constain
        if ( constrainer.getIsVariableApplicable(i) )
        { // this variable is to be constrained
          // constrain both returnal candidates:
          // * pointNow
          // * pointPre

          pointNow.constrain(constrainer.variableStarts, constrainer.variableStops);
          pointPre.constrain(constrainer.variableStarts, constrainer.variableStops);

        }

      }

    }

  }

  // offset iteration count
  iterations--;

  if ( iterations >= maxIterations )
  {
    // Handle Iterations Limit

    throw Exceptions::IterationLimitException();

  }

  return verify() ? pointNow : pointPre; // (A) And return its result

}

//*****************************************************************************
// Is Optimum closer and closer ?
bool HookeJeeves::verify()
{
  return  HookeJeeves::isMinimizing ?
    polynomial->evaluate(pointPre) > polynomial->evaluate(pointNow) :   // pre > now ∵ we go down
    polynomial->evaluate(pointPre) < polynomial->evaluate(pointNow);    // pre < now ∵ we go up, up, up~

}

//*****************************************************************************
// Pp = P2 + ( P2 - P1 )
Point HookeJeeves::patternize()
{
  // First Pattern Move is special
  // do not move, return Initial Point

  static bool isInitialization = true;

  if ( isInitialization )
  {
    isInitialization = false;
    return pointNow;

  }

  // ! Pattern Point doesnt matter !
  // its just auxiliary

  return pointNow + (pointNow - pointPre);

}

//*****************************************************************************
void HookeJeeves::explore(Point patternPoint)
{
  pointPrePre = pointPre;
  pointPre = pointNow;  // (B) remember the PREvious most optimal point
                        // useful for the patterization formula
                        // Pp = P2 + ( P2 - P1 )

  // Now calculate new pointNow ...

  Point pointPlus = patternPoint;
  Point pointZero = patternPoint;
  Point pointNegative = patternPoint;

  for ( int i = 0; i < pointNow.countCoordinates(); i++ ) // each x, y, z, ..
  {
    // prepare P+
    pointPlus.setCoordinate(i, pointPlus.getCoordinate(i) + delta);
    // compute f+
    double fPlus = polynomial->evaluate(pointPlus);

    // compute f0
    double fZero = polynomial->evaluate(pointZero);

    // prepare P-
    pointNegative.setCoordinate(i, pointNegative.getCoordinate(i) - delta);
    // compute f-
    double fNegative = polynomial->evaluate(pointNegative);

    vectorDouble values;
    values.push_back(fPlus);      // Point Plus
    values.push_back(fZero);      // Point Zero
    values.push_back(fNegative);  // Point Negative

    int optimalI = HookeJeeves::isMinimizing ?
      Statistics::minIndex(values) :
      Statistics::maxIndex(values);

    switch ( optimalI )
    {
      case 0: // Point Plus is the most optimal
        pointNow = pointZero = pointNegative = pointPlus;
        break;

      case 1: // Point Zero is the most optimal
        pointNow = pointPlus = pointNegative = pointZero;
        break;

      case 2: // Point Negative is the most optimal
        pointNow = pointPlus = pointZero = pointNegative;
        break;

    }

  }

  // (B) new most optimal point achieved
  // pointNow

}

//*****************************************************************************
// delta of xi
void HookeJeeves::setDelta(double delta)
{
  HookeJeeves::initial_delta = delta;

}


//*****************************************************************************
void HookeJeeves::setStopDelta(double stopDelta)
{
  HookeJeeves::stopDelta = stopDelta;

}

//*****************************************************************************
// initial point
void HookeJeeves::setPoint(Point initialPoint)
{
  HookeJeeves::startPoint = initialPoint;

}