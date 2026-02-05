#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Polynomial
/// # model function of type: polynomial
/// # derive from class: Expression

#include <string>

#include "Statistics.h"
#include "Convert.h"
#include "Powers.h"
#include "Coefficients.h"
#include "Exceptions/SolvingFunctionException.h"
#include "Exceptions/PolynomialDegreeException.h"
#include "Exceptions/CoordinateMismatchException.h"
#include "Enumerated/ExpressionType.h"
#include "Expression.h"
#include "Point.h"

namespace MathworkCPP
{
	//-----------------------------------------------------------------------------

	class Polynomial : public Expression
	{
    private:

      using vectorPoint = std::vector<Point>;

      std::string variableNames {};

      Coefficients coefficients {};
      std::vector<Powers> powers {};

    public:

      Polynomial() : Expression() {}; // delagated, finishing intialization list;
      ~Polynomial() {};

      void addExpression(double coefficient, vectorNullableDouble powers);

      void addVariableName(char variable);

      int countExpressions();

      int countVariables();

      double degree();

      double evaluate(Point point);

      std::string getVariableNames();

      void reset();

      vectorPoint solve(Point inclusiveX1,
                        Point inclusiveX2,
                        double y,
                        double precision);

      vectorPoint solveLinear(double y = 0);

      vectorPoint solveQuadratic(double y = 0);
  };
}

#endif // POLYNOMIAL_H