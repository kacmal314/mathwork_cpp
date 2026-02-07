
#include <iostream>

#include "MathworkCPP.h"

using namespace MathworkCPP;

int main()
{
  try
  {
    //test(new Testing::InverseMatrixTest {});
    //test(new Testing::MatrixTest {});
    //test(new Testing::FileNameTest {});
    //test(new Testing::RandomIntTest {});
    //test(new Testing::StringTest {});
    test(new Testing::ExpressionTest {});

    return 0;
  }
  catch (std::out_of_range ex)
  {
    std::cout << std::endl << ex.what() << std::flush;

    //
    // cannot repair this error
    // best terminate application
    // prevent damage to filesystem or other
    // 
    // programmer exceptions: dont handle

    throw ex;
  }
  catch (Exceptions::Exception ex)
  {
    std::cout << std::endl << ex.getMessage() << std::flush;

    throw ex;
  }
  
}