#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// String
/// # define static functions that work on std::string

#include <string>
#include <vector>

namespace MathworkCPP
{
  namespace Extended
  {
    //-----------------------------------------------------------------------------

    ///
    /// Static Class
    /// # static keyword = sealed keyword
    ///

    class String
    {
      ///////////////////////////////////////////////////////////////////////////////
      // PUBLIC

      public:

        static std::vector<size_t>      findAll(
                                          std::string str,
                                          std::string pattern,
                                          int from = 0
                                        );

        static bool          		        isAlpha(char ch);
        static bool          		        isNumerical(char ch);
        static bool          		        isSign(char ch);
        static bool          		        isWhiteCharacter(char ch);
        static std::string              removeCharacter(std::string str, char ch);
        static std::string              removeWhiteCharacters(std::string str);

        static std::string              replaceAll(
                                          std::string str,
                                          std::string pattern,
                                          std::string withPattern,
                                          int from = 0
                                        );
    };
    
  }

}