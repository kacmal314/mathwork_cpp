//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "String.h"

#include <string>
#include <vector>

using namespace MathworkCPP::Extended;

//*****************************************************************************
	
///
/// desc
///   std::vector contains indexes where find() succeeded
/// return
///   std::vector
///

std::vector<size_t> String::findAll(std::string str, std::string pattern, int from)
{
	std::vector<size_t> finds = std::vector<size_t>();
		
	while (str.find(pattern, from) != std::string::npos)
	{
		finds.push_back(str.find(pattern, from));
		from = finds.back() + 1;
			
	}
		
	// (!) is std::vector empty
		
	return finds;
		
}

//*****************************************************************************
bool String::isWhiteCharacter(char ch)
{
  return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');

}

//*****************************************************************************
bool String::isSign(char ch)
{
  return (ch == '-' || ch == '+');

}

//*****************************************************************************
bool String::isNumerical(char ch)
{
  return (ch >= '0') && (ch <= '9') || (ch == '.');

}

//*****************************************************************************
bool String::isAlpha(char ch)
{
  if (ch < 97)
    ch = ch + 32; // convert to lowercase

  return (ch >= 97) && (ch <= 122);

}

//*****************************************************************************
std::string String::removeCharacter(std::string str, char ch)
{
  std::string ret {""};
  for (auto curCh : str)
    if (curCh != ch)
      ret += curCh;

  return ret;

}

//*****************************************************************************
std::string String::removeWhiteCharacters(std::string str)
{
  std::string ret {""};
  for (auto ch : str)
    if (! isWhiteCharacter(ch))
      ret += ch;

  return ret;

}

//*****************************************************************************

//
//
//

std::string String::replaceAll(
  std::string str,
  std::string pattern,
  std::string withPattern,
  int from
)
{
  from = str.find(pattern, from);

  while (from != std::string::npos)
  {
    // std::string::replace(od kad, ile, czym)
    str.replace(from, pattern.length(), withPattern);
    from = str.find(pattern, from + 1);
  }

  return str;
}