#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Constrainer Class
/// # used by HookeJeeves
/// # provide argument ranges to iterative algorithms

#include "Helper/declarations.h"

namespace MathworkCPP
{
	//-----------------------------------------------------------------------------
	// Collect Constrainer-related Data Members
	class Constrainer
	{

		///////////////////////////////////////////////////////////////////////////////
		public:

      Constrainer();
      ~Constrainer();

			///
			/// variableStarts is counter
			/// counter counts elements
			///

			vectorDouble    	variableStarts            = vectorDouble();
					
			vectorDouble    	variableStops             = vectorDouble();
			bool        	    isConstrainerApplicable   = false;
					
			bool        	    getIsVariableApplicable(int index);
			void        	    setIsVariableApplicable(int iSize);
			void        	    addIsVariableApplicable(bool isApplicable);

		///////////////////////////////////////////////////////////////////////////////
		private:

			bool        *isVariableApplicable   = nullptr; // array of flags
			int    			index                   = 0;

	};
	
}

