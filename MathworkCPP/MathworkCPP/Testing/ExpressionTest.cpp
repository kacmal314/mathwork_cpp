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
    Expression invalid { "$@" };            // throw exception
  }
  catch (Exceptions::ParserException e)
  {
    console.log(e.getMessage(), true);
  }
  
  Expression squared { " z^2+y^2" };      // [+ ^ ^ z 2 y 2 ]
  Expression parenth { "(2 + 2)* 2" };    // [* + 2 2 2]
  Expression sinefun { "(sin(x))^2*2" };  // [* ^ 2 sin 2 null x]

  squared.evaluate({{"z", 4}, {"y", 8}});   // double(80)
  parenth.evaluate();                       // double(8)
  sinefun.evaluate({{"x", 3.14}});          // double(0.00600080060054297305308321210152)
}
