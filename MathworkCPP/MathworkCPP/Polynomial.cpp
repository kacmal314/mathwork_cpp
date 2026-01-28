//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "Polynomial.h"

using namespace MathworkCPP;

//*****************************************************************************
Polynomial::Polynomial()
{

}

//*****************************************************************************
Polynomial::~Polynomial()
{

}

//*****************************************************************************
void Polynomial::addExpression(double coefficient, vectorNullableDouble powers)
{
  // Add coefficient
  coefficients.Add(coefficient);

  // Add ordered powers
  // Think: Parser.cpp
  // std::set

  Powers element;
  for ( auto & power : powers )
  {
    element.Add(power); // Add powers in this expression of variables x y z ..
  }

  this->powers.push_back(element);

}

//*****************************************************************************
void Polynomial::addVariableName(char variable)
{
  this->variableNames += variable;

}

//*****************************************************************************
int Polynomial::countExpressions()
{
  return coefficients.Count();

}

//*****************************************************************************
int Polynomial::countVariables()
{
  return variableNames.size();

}

//*****************************************************************************
double Polynomial::degree()
{
  try
  {
    int max = this->powers[0][0];

    for (auto powerBox : this->powers)
    {
      auto powerBoxNotNulls = Convert::toNotNull(powerBox.getPowers());

      int curMax = Statistics::max(powerBoxNotNulls);

      if (max < curMax)
      {
        max = curMax;
      }
    }

    // Return max power

    return max;
  }
  catch (std::out_of_range)
  {
    return 0.0;
  }
  catch (...)
  {
    throw;
  }

}

//*****************************************************************************
double Polynomial::evaluate(Point X)
{
  if (X.countCoordinates() != countVariables())
  {
    throw Exceptions::CoordinateMismatchException();
  }

  double y = 0.0;

  // sum expressions
  for (int index = 0; index < countExpressions(); index++)
  {

    // sum variables in expression
    double expression = coefficients[index];

    // account for each Argument primitive (x, y, z, ..)
    for (int i = 0; i < X.countCoordinates(); i++)
    {
      // std::optional::operator!
      if ( ! powers[index][i] )
      {
        continue;
      }

      // EG if -0.5^0.5 = sqrt(-0.5)
      if (X.getCoordinate(i) < 0 &&
          powers[index][i] != (int)powers[index][i])
      {
        throw Exceptions::Exception("cmath pow(double, double) doesnt support complex numbers");
      }

      // double * double
      expression *= std::pow(X.getCoordinate(i), powers[index][i]);

    }

    // sum expressions
    y += expression;

  }

  return y;

}

//*****************************************************************************
std::string Polynomial::getVariableNames()
{
  return variableNames;

}

//*****************************************************************************
void Polynomial::reset()
{

  // clear Coefficients
  coefficients.Clear();

  // clear vector<Powers>
  powers.clear();

  variableNames = "";

}

//*****************************************************************************

///
/// desc
///   return Point::class containing REAL roots of Polynomial
///   input: x-domain [start, end) ;  precision
///   output: [1, 3.14, 4]
/// 

Polynomial::vectorPoint Polynomial::solve(
  Point inclusiveX1,
  Point inclusiveX2,
  double y,
  double precision
)
{

  vectorPoint roots;

  try
  {

    // degree of polynomial is integer
    switch ((int)this->degree())
    {
      case 1:

        roots = this->solveLinear();

        break;

      case 2:

        roots = this->solveQuadratic();

        break;

      default:

        throw Exceptions::PolynomialDegreeException();

    }

  }
  catch (Exceptions::PolynomialDegreeException)
  {
    throw;
  }
  catch (...)
  {
    throw;
  }

  return roots;
}

//*****************************************************************************

///
/// linear signature
///   a x1 + b x2 + c
/// linear formula
///   only real roots
///   can never be complex
/// 

Polynomial::vectorPoint Polynomial::solveLinear(double y)
{

  if (this->countExpressions() > 3)
  {
    // Required: a x1 + b x2 + c
    // Required: 3 expressions MAX

    std::string count = std::to_string(this->countExpressions());

    throw Exceptions::SolvingFunctionException(
      "Attention! Linear function cannot be solved."
      "Count of Expressions is too great: " + count +
      "Notice y=" + std::to_string(y)
    );
  }

  double a {};
  double b {};
  double c {};

  // a x1 + b x2 + c = y
  // uklad rownan nieokreslony

  for (int i = 0; i < this->countExpressions(); i++)
  {
    vectorNullableDouble curPows = this->powers[i].getPowers();

    for (int j = 0; j < curPows.size(); j++)
    {
      if ( ! curPows[j])
      {
        continue;
      }

      double curPow = *(curPows[j]);
      int curPowInt = (int)curPow;

      if (curPow != curPowInt)
      {
        throw Exceptions::PolynomialDegreeException(
          "Attention! Cannot solve linear equation."
          "Expression contains a power expression of degree: " + std::to_string(curPow) + "."
          "Please review Your input on the selected operation"
        );

      }

      switch (curPowInt)
      {
        case 1:

          a = this->coefficients[i];

          break;

        case 0:

          b = this->coefficients[i];

          break;

        default:

          throw Exceptions::PolynomialDegreeException(
            "Attention! Cannot solve linear equation."
            "Expression contains a power expression of degree: " +
            std::to_string(curPowInt) + "."
            "Please review Your input on the selected operation"
          );

      }
    }



  }

  vectorPoint roots {};

  Point X = Point({(y - b) / a});

  roots.push_back(X);

  return roots;


}

//*****************************************************************************

///
/// quadratic signature
///   a x1^2 + b x2^2 + c x1x2 + d x1 + e x2 + f
/// quadratic equation
/// 

Polynomial::vectorPoint Polynomial::solveQuadratic(double y)
{
  // x1 = -b + sqrt(b^2 - 4ac) / 2a
  // x2 = -b - sqrt(b^2 - 4ac) / 2a

  int a = 0;
  int b = 0;
  int c = 0;

  Polynomial::vectorPoint P;

  return P;

}