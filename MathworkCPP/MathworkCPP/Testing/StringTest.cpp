#include "StringTest.h"

using namespace MathworkCPP;

//*****************************************************************************

void Testing::StringTest::test()
{
  std::string tested = NEW_PARA;
  std::string tmp = "";
  std::string pattern = "";

  tested += NEW_LINE + "//-----------------------------------------------------------------------------";
  tested += NEW_LINE + "Testing class String";

  tested += NEW_LINE + "//*****************************************************************************";
  tested += NEW_LINE + "Testing findAll()";
  
  tmp = "Ala ma kota Ala ma psa Ala nie ma bazanta";
  pattern = tmp.substr(0, 3);

  std::vector<size_t> finds = Extended::String::findAll(tmp, pattern, 0);

  tested  += NEW_LINE + "String: " + tmp;
  tested  += NEW_LINE + "Pattern: " + pattern;
  tested  += NEW_LINE + "Indices:";

  for (auto elem : finds)
  {
    tested += " " + std::to_string(elem);
  }

  tested += NEW_LINE + "//*****************************************************************************";
  tested += NEW_LINE + "Testing replaceAll()";

  tmp = "Compiler ignores 'inline function' if it is 'too large'";
  pattern = "'";

  std::string replaced = Extended::String::replaceAll(tmp, pattern, "*");

  tested  += NEW_LINE + "String: " + tmp;
  tested  += NEW_LINE + "Pattern: " + pattern;
  tested  += NEW_LINE + "Replaced: " + replaced;

  ConsoleInterface console;
  console.log(tested);
}
