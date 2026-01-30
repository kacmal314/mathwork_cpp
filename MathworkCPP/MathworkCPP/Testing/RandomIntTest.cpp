#include "RandomIntTest.h"

using namespace MathworkCPP;

//*****************************************************************************

void Testing::RandomIntTest::test()
{
  std::string tested = NEW_PARA;

  tested += NEW_LINE + "//-----------------------------------------------------------------------------";
  tested += NEW_LINE + "Testing class Random";

  tested += NEW_LINE + "//*****************************************************************************";
  tested += NEW_LINE + "Testing randomInt()";

  for (int i = 0; i < 10; i++)
  {
    int random = Random::randomInt(1, 4);
    tested += NEW_LINE + "Drawing random int ... " + std::to_string(random);
  }

  ConsoleInterface console;
  console.log(tested);
}
