#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Matrix
/// 
/// # model r x c mathematical matrix

#include "Helper/declarations.h"

#include <stdexcept>
#include <string>
#include <vector>

namespace MathworkCPP
{

	//-----------------------------------------------------------------------------
	class Matrix
	{
		public:

      Matrix() = default;
      Matrix(const char *signature);
			Matrix(int rowsCount, int columnsCount);
      Matrix(vector2Double numbers);

      static Matrix     cofactorMatrix(Matrix M);
      double            columnsCount();
      Matrix            copy() const;
      double            determinant();
      void              fill(vector2Double numbers);
			void              getDimensions(
                          vector2Double numbers,
													int &rowsCount,
													int &columnsCount
												);
      Matrix            inverse();
      bool              isSquare();
      static Matrix     minorsMatrix(Matrix M);
			Matrix            operator*(double scalar) const;
			Matrix            operator*(Matrix N) const;

			// [] : vector
			vectorDouble&        operator[](size_t index);

			// [] : const vector
			const vectorDouble&  operator[](size_t index) const;
			void              resize(int rowsCount, int columnsCount);
      double            rowsCount();

      // type Echo
      std::string       toString();
      Matrix            transpose();

		private:

      void              normalize();

			vector2Double     numbers;
      std::string       findLongestElement();
	};

}

