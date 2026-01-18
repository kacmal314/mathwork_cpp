//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "Extended/String.h"
#include "Filesystem.h"

using namespace MathworkCPP;

//*****************************************************************************

///
/// desc
///   input: "C:\my\path\filename.txt"
///   output: "filename.txt"
///   output: "filename"

std::string Filesystem::filename(std::string path, bool withExtension)
{
  // backslashes -> slashes
  std::string filename = Extended::String::replaceAll(path, "\\", "/");

  int lastSlashIndex = filename.rfind('/', std::string::npos);
  
  filename = filename.substr(lastSlashIndex + 1);

  if ( ! withExtension)
  {
    int lastDotIndex = filename.rfind('.', std::string::npos);

    filename = filename.substr(0, lastDotIndex); // without the dot
  }

  return filename;

}