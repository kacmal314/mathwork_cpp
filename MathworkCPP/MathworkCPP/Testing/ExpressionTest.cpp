#include "ExpressionTest.h"

using namespace MathworkCPP;

//*****************************************************************************

void Testing::ExpressionTest::test() /* override - tutaj juz nie dajesz */
{
  ConsoleInterface console;

  console.log(NEW_PARA);
  console.log("//-----------------------------------------------------------------------------", true);
  console.log("Testing class ExpressionTest", true);

  try
  {
    Expression invalid { "$@" }; // throw exception
  }
  catch (Exceptions::ParserException e)
  {
    console.log(e.getMessage(), true);
  }
  
  Expression squared { " z^2+y^2" };      // [+ ^ ^ z 2 y 2 ]
  Expression parenth { "(2 + 2)* 2" };    // [* + 2 2 2]
  Expression sinefun { "(sind(x))^2*2" };  // [* ^ 2 sind 2 null x]

  console.log<std::string>(" z^2+y^2 = ");
  console.log<double>(squared.evaluate({{"z", 4}, {"y", 8}}), false); // 80.0
  
  console.log("(2 + 2)* 2 = ");
  console.log(parenth.evaluate(), false); // 8.0

  console.log("(sind(x))^2*2 = ");
  console.log(sinefun.evaluate({{"x", 90}}), false); // 0.0060008
  
}
