#include "MatrixTest.h"

using namespace MathworkCPP;

//*****************************************************************************

void Testing::MatrixTest::test()
{
  std::string tested = NEW_PARA;

  tested += NEW_LINE + "//-----------------------------------------------------------------------------";
  tested += NEW_LINE + "Testing class Matrix";

  Matrix M1 = Matrix({
    {4}
  });

  Matrix M4 = Matrix({
    {1, 2},
    {3, 4}
  });

  Matrix M9 = Matrix({
    {1,9,2}, 
    {8,3,7},
    {4,6,5}
  });

  Matrix M12 = Matrix({
    {4,5,6,1},
    {7,8,9,9},
    {2,3,4,1}
  });

  Matrix M25 = Matrix({
    {4,5,6,1,2},
    {7,8,9,9,1},
    {2,3,4,1,5},
    {5,6,7,9,9},
    {5,6,7,3,4}
  });

  Matrix M25B = Matrix({
    {1,2,3,4,5},
    {0,1,0,2,1},
    {4,0,3,1,0},
    {2,3,0,1,4},
    {1,0,5,0,3}
  });

  tested += NEW_PARA + "//*****************************************************************************";
  tested += NEW_LINE + "Testing operator*(Matrix)";

  Matrix M25_M25B = M25 * M25B;

  tested += NEW_PARA;

  tested += NEW_LINE;
  tested += NEW_LINE + "M25 * M25B = ";
  tested += NEW_LINE + M25_M25B.toString();

  Matrix M9_M12 = M9 * M12;

  tested += NEW_PARA;

  tested += NEW_LINE;
  tested += NEW_LINE + "M9 * M12 = ";
  tested += NEW_LINE + M9_M12.toString();

  tested += NEW_PARA + "//*****************************************************************************";
  tested += NEW_LINE + "Testing determinant()";

  double M1det = M1.determinant(); // determinant = 4

  double M4det = M4.determinant(); // determinant = -2

  double M9det = M9.determinant(); // determinant = -63

  // double M12det = M12.determinant(); // determinant = NOPE

  double M25det = M25.determinant(); // determinant = 0

  double M25Bdet = M25B.determinant(); // determinant = -130

  tested += NEW_PARA;

  // add new matrix signature
  tested += NEW_LINE;
  tested += M1.toString();
  tested += NEW_LINE + "det(M1) = " + std::to_string(M1det);

  // add new matrix signature
  tested += NEW_LINE;
  tested += M4.toString();
  tested += NEW_LINE + "det(M4) = " + std::to_string(M4det);

  // add new matrix signature
  tested += NEW_LINE;
  tested += M9.toString();
  tested += NEW_LINE + "det(M9) = " + std::to_string(M9det);

  // add new matrix signature
  tested += NEW_LINE;
  tested += M25.toString();
  tested += NEW_LINE + "det(M25) = " + std::to_string(M25det);

  // add new matrix signature
  tested += NEW_LINE;
  tested += M25B.toString();
  tested += NEW_LINE + "det(M25B) = " + std::to_string(M25Bdet);

  tested += NEW_PARA + "//*****************************************************************************";
  tested += NEW_LINE + "Testing inverse()";

  tested += NEW_LINE;
  tested += NEW_LINE + "M4 is";
  tested += NEW_LINE + M4.toString();
  tested += NEW_LINE;
  tested += NEW_LINE + "inv(M4) is";
  tested += NEW_LINE + M4.inverse().toString();

  tested += NEW_LINE;
  tested += NEW_LINE + "M9 is";
  tested += NEW_LINE + M9.toString();
  tested += NEW_LINE;
  tested += NEW_LINE + "inv(M9) is";
  tested += NEW_LINE + M9.inverse().toString();

  tested += NEW_LINE;
  tested += NEW_LINE + "M12 is";
  tested += NEW_LINE + M12.toString();
  tested += NEW_LINE;
  tested += NEW_LINE + "inv(M12) is";

  tested += NEW_LINE;

  try
  {
    // exceptional call
    tested += (NEW_LINE + M12.inverse().toString());
  }
  catch (Exceptions::SquareMatrixException e)
  {
    tested += NEW_LINE + e.Message();
  }

  tested += NEW_LINE;
  tested += NEW_LINE + "M25 is";
  tested += NEW_LINE + M25.toString();
  tested += NEW_LINE;
  tested += NEW_LINE + "inv(M25) is";

  try
  {
    tested += NEW_LINE + M25.inverse().toString();
  }
  catch (Exceptions::ZeroDeterminantException e)
  {
    tested += NEW_LINE + e.Message();
  }

  tested += NEW_LINE;
  tested += NEW_LINE + "M25B is";
  tested += NEW_LINE + M25B.toString();
  tested += NEW_LINE;
  tested += NEW_LINE + "inv(M25B) is";
  tested += NEW_LINE + M25B.inverse().toString();

  ConsoleInterface console;

  console.log(tested);
}
