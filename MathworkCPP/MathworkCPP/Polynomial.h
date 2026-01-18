#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Polynomial
/// # model function of type: polynomial
/// # derive from class: Function

#include <string>

#include "Statistics.h"
#include "Convert.h"
#include "Powers.h"
#include "Coefficients.h"
#include "Exceptions/SolvingFunctionException.h"
#include "Exceptions/PolynomialDegreeException.h"
#include "Exceptions/CoordinateMismatchException.h"
#include "Enumerated/FunctionType.h"
#include "Function.h"
#include "Point.h"

namespace MathworkCPP
{
	//-----------------------------------------------------------------------------
	class Polynomial : Function
	{
    private:

      using vectorPoint = std::vector<Point>;

      std::string variableNames {};
      Coefficients coefficients {};
      std::vector<Powers> powers {};

    public:

      Polynomial();
      ~Polynomial();
      void addExpression(double coefficient, vectorNullableDouble powers);
      void addVariableName(char variable);
      int countExpressions();
      int countVariables();
      double degree();
      double f(Point X) override;
      std::string getVariableNames();
      void reset();
      vectorPoint solve(
        Point inclusiveX1,
        Point inclusiveX2,
        double y,
        double precision
      );
      vectorPoint solveLinear(double y = 0);
      vectorPoint solveQuadratic(double y = 0);      
  };
}
