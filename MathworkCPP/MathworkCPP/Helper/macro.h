#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// preprocessor macros

#define dump(A) (std::cout << "\n" << (#A) << "=" << (A))

#define whereAmI() (std::cout << "Currently in function " << __func__ << "() on line " << __LINE__)
