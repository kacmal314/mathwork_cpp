#include "FileNameTest.h"

using namespace MathworkCPP;

//*****************************************************************************

void Testing::FileNameTest::test() /* override - tutaj juz nie dajesz */
{
  ConsoleInterface console;

  console.log(NEW_PARA);
  console.log(NEW_LINE + "//-----------------------------------------------------------------------------");
  console.log(NEW_LINE + "Testing class Filesystem");

  console.log(NEW_LINE + "//*****************************************************************************");
  console.log(NEW_LINE + "Testing filename()");

  std::string pathfile = "C:\\XAMPP\\php\\sendmail.exe";
  
  console.log(NEW_LINE + "filename: " + pathfile);
  console.log(NEW_LINE + "extracted basename: " + Filesystem::filename(pathfile, false));
  console.log(NEW_LINE + "extracted basename.ext: " + Filesystem::filename(pathfile));
}
