//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "Matrix.h"
#include "Helper/definitions.h"

#include "Exceptions/MatrixSizeException.h"
#include "Exceptions/SquareMatrixException.h"
#include "Exceptions/ZeroDeterminantException.h"

#include "Extended/String.h"

#include <regex>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace MathworkCPP;

///////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS

/// 
/// const
///   class instatnce has to be const
///   otherwise global function overload wont work
///   therefore
///     Matrix::operator*(double) const
///     has to be const too
/// 

Matrix operator*(double scalar, const Matrix M)
{
  return M * scalar;
}

///////////////////////////////////////////////////////////////////////////////
// PUBLIC

//*****************************************************************************

//
// reading 2d matrix
//
// signature: {{1,2},{3,4}}
// regex: {.*?}[,}] gives (!) notice: "?" is not supported in std::regex
// regex: }[,}] gives
//   "},"
//   "},"
//   "}}"
// regex: \d+[,}] gives
//   "1,"
//   "2}"
//   "9,"
//   "0}"
//   "3,"
//   "4}"

Matrix::Matrix(const char *signature)
{
  std::string signature_ = signature;

  signature_ = Extended::String::removeWhiteCharacters(signature_);

  //
  // https://cplusplus.com/reference/regex/basic_regex/basic_regex/
  // std::regex is actually: std::basic_regex::basic_regex
  std::regex rowRegex("[}][,}]", std::regex_constants::ECMAScript);
  std::sregex_iterator rowsIterator = std::sregex_iterator(signature_.begin(), signature_.end(), rowRegex);

  //
  // https://cplusplus.com/reference/regex/regex_iterator/regex_iterator/
  // The default constructor (1) constructs an end-of-sequence iterator.
  // This value shall not be dereferenced.
  std::sregex_iterator rowsEnd = std::sregex_iterator();

  size_t rowsCount = std::distance(rowsIterator, rowsEnd);

  std::regex elementRegex = std::regex("-?[0-9.]+", std::regex_constants::ECMAScript);
  std::sregex_iterator elementsIterator = std::sregex_iterator(signature_.begin(), signature_.end(), elementRegex);
  std::sregex_iterator elementsEnd = std::sregex_iterator();

  size_t elementsCount = std::distance(elementsIterator, elementsEnd);

  int columnsCount = elementsCount / rowsCount;
  this->resize(rowsCount, columnsCount);

  int i = 0;

  while (elementsIterator != elementsEnd)
  {
    std::smatch match = *elementsIterator;

    // selecting: first match
    // 1
    // 2
    // 9
    // 0
    // 3
    // 4
    std::string matchStr = match.str(0);

    // return -> increment -> modulus
    this->numbers[i / columnsCount][i % columnsCount] = std::stod(matchStr);

    // dont inline increment in a sequence of operator[]
    i++;

    elementsIterator++;
  }

}

//*****************************************************************************

/**
* Contructor
*/

Matrix::Matrix(int rowsCount, int columnsCount)
{
  resize(rowsCount, columnsCount);
}

//*****************************************************************************

/**
* Contructor
*/

Matrix::Matrix(vector2Double numbers)
{
  fill(numbers);
}

//*****************************************************************************

/**
* desc
* 
*   convert
* 
*     | 1 2 3 |    | +1 -2 +3 |
*     | 4 5 6 | => | -4 +5 -6 |
*     | 7 8 9 |    | +7 -8 +9 |
*/

Matrix Matrix::cofactorMatrix(Matrix M)
{
  Matrix N = M.copy();
  for (int row = 0; row < N.rowsCount(); row++)
  {
    for (int column = 0; column < N.rowsCount(); column++)
    {
      N[row][column] *= pow(-1.0, row + column);
    }
  }

  return N;

}

//*****************************************************************************
double Matrix::columnsCount()
{
  if (numbers.size() == 0)
  {
    // zero rows
    return 0;
  }

  return numbers[0].size();
}

//*****************************************************************************

/**
* return
*   automatic object of this pointer
*/

Matrix Matrix::copy() const
{
  return Matrix(numbers);
}

//*****************************************************************************
double Matrix::determinant()
{
  if (this->rowsCount() != this->columnsCount())
  {
    throw new Exceptions::SquareMatrixException();
  }

  if (rowsCount() == 1 && columnsCount() == 1)
  {
    // wyznacznik ze skalara to skalar
    // | 1 | == 1
    return this->numbers[0][0];
  }

  Matrix submatrix = Matrix(this->rowsCount() - 1, this->columnsCount() - 1);

  double determinant = 0;

  for (int i = 0; i < columnsCount(); i++)
  {
    //            szachownica +'ów i -'ów       
    //                  | + | - | + |                 
    //                  | - | + | - |     ustalamy, że wyznacznik liczymy
    //                  | + | - | + |     zawsze z wiersza indeks: 0
    double scalar0i = std::pow(-1, i) * numbers[0][i];

    // 
    int row = 0;
    int col = 0;

    // stwórzmy pod-macierz
    for (int ROW = 0; ROW < rowsCount(); ROW++)
    {
      if (ROW == 0)
      {
        // "wykreślamy" wiersz macierzy DUŻEJ
        continue;
      }

      for (int COL = 0; COL < columnsCount(); COL++)
      {
        if (COL == i)
        {
          // "wykreślamy" kolumnę macierzy DUŻEJ"
          continue;
        }

        submatrix.numbers[row][col++] = this->numbers[ROW][COL];
      }

      row++;
      col = 0;
    }

    //
    // ok, pod-macierz stworzona

    // teraz mnożymy skalar razy kolejny wyznacznik
    scalar0i *= submatrix.determinant();

    determinant += scalar0i;

  }

  return determinant;
}

//*****************************************************************************
void Matrix::fill(vector2Double numbers)
{
  // resize 
  int rowsCount = 0;
  int columnsCount = 0;
  this->getDimensions(numbers, rowsCount, columnsCount);

  resize(rowsCount, columnsCount);

  int rowI = 0;

  auto rowIterator = numbers.begin();

  // przechodzimy elementy std::vector-a (wiersze): [], [], [], .. ostatni
  while (rowIterator != numbers.end())
  {
    int columnI = 0;
    auto columnIterator = rowIterator->begin();

    // przechodzimy elementy std::vector-a (elementy wierszy): 0, 1, 2, .. ostatni
    while (columnIterator != rowIterator->end())
    {
      if (rowI >= this->rowsCount() || columnI >= this->columnsCount())
      {
        throw new std::out_of_range("numbers dont fit into matrix");
      }

      // tutaj odbywa się właściwe kopiowanie elementów z pomocniczego std::vector-a 2d
      // do wewnętrznego std::vector-a 2d
      // tak jakbyśmy chcieli kopiować kartki papieru, drukując nowe egzemplarze
      this->numbers[rowI][columnI++] = *(columnIterator++);
    }

    rowI++;
    rowIterator++;
  }
}

//*****************************************************************************
std::string Matrix::findLongestElement()
{
  std::string longestElement = "";

  for (int i = 0; i < this->rowsCount(); i++)
  {
    for (int j = 0; j < this->columnsCount(); j++)
    {
      std::stringstream ss;
      ss << numbers[i][j];
      std::string element = "";
      ss >> element;

      if (longestElement.length() < element.length())
      {
        longestElement = element;
      }

    }

  }

  return longestElement;
}

//*****************************************************************************
void Matrix::getDimensions(
  vector2Double numbers,
  int &rowsCount,
  int &columnsCount
)
{
  rowsCount = numbers.size();

  try
  {
    columnsCount = numbers.at(0).size();
  }
  catch (std::out_of_range)
  {
    columnsCount = 0;
  }

}

//*****************************************************************************

///
/// output
///   may produce [... -0 ...]
///

Matrix Matrix::inverse()
{
  if ( ! this->isSquare())
  {
    throw Exceptions::SquareMatrixException("Error: liczba wierszy oraz kolumn macierzy musi sie zgadzac !");
  }

  if (this->determinant() == 0)
  {
    // nie istnieje macierz odwrotna z macierzy osobliwej
    // wyobrazmy sobie przestrzeń transformowaną liniowo (macierzą liniową)
    // wyobrazmy sobie ścisnąć ją do przestrzeni 0d (punkt)
    // jak będzie wyglądać macierz odwrotna ?
    // (nie istnieje, nie da się przywrócić naszej przestrzeni dawnego wymiaru)
    throw Exceptions::ZeroDeterminantException("Error: wyznacznik nie moze byc = 0 !");
  }

  if (this->rowsCount() == 1)
  {
    // macierz zawierajaca 1 element
    this->numbers[0][0] = 1 / this->numbers[0][0];
    return *this;
  }

  Matrix M = this->copy();
  Matrix cofactor = Matrix::cofactorMatrix(Matrix::minorsMatrix(M));

  M = (1 / M.determinant()) * cofactor.transpose();

  // Macierz Kofaktorow uzyskuje sie mnozac elementy razy: -1
  // mozemy niechcacy uzyskac -0
  M.normalize();

  return M;

}

//*****************************************************************************
bool Matrix::isSquare()
{
  return this->rowsCount() == this->columnsCount();
}

//*****************************************************************************

/**
* desc
*   Matrix M   -> square, matrix to transform
*   minors     -> square, matrix of determinants
*/

Matrix Matrix::minorsMatrix(Matrix M)
{
  if (M.rowsCount() != M.columnsCount())
  {
    throw Exceptions::SquareMatrixException();
  }

  // zlozonosc przestrzenna algorytmu
  // to co najmniej 2-krotnosc danych poczatkowych
  // (potrzebujemy jeszcze raz tyle miejsca w pamieci RAM)
  Matrix determinants = M.copy();

  if (M.rowsCount() == 1)
  {
    //
    // just one row just one column
    // minor of a scalar == scalar
    return determinants;
  }

  int rowsCount = M.rowsCount();
  int columnsCount = M.columnsCount();

  // bardzo klopotliwa zlozonosc czasowa
  // w najgorszym przypadku O(n^4)

  for (int rowIndex = 0; rowIndex < rowsCount; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < columnsCount; columnIndex++)
    {
      //
      // tutaj zaczynamy liczyc kolejny minor

      Matrix submatrix = Matrix(rowsCount - 1, columnsCount - 1);

      int rowIndexOffset = 0;

      // [A] indeks wierszy małej macierzy <= liczbie wierszy dużej macierzy
      // ponieważ licząc na kartce też rozważamy całą dużą macierz
      // zakres indeksu to cala wysokosc macierzy zewnetrznej
      for (int rowIndexInternal = 0; rowIndexInternal <= submatrix.rowsCount(); rowIndexInternal++)
      {

        // rozpoczynamy wiersz: zawsze od pierwszej kolumny
        int columnIndexOffset = 0;

        // [A] tutaj też indeks <= liczbie kolumn
        // na kartce też rozważamy wszystkie kolumny dużej macierzy
        // zakres indeksu cala szerokosc macierzy zewnetrznej
        for (int columnIndexInternal = 0; columnIndexInternal <= submatrix.columnsCount(); columnIndexInternal++)
        {
          if (rowIndexInternal == rowIndex)
          {
            // [A] przesunięcie indeksu o -1, następuje kiedy wpadniemy na
            //     wiersz, który powinien być wykreślony
            rowIndexOffset = -1;

            // w C++ nie możemy niczego wykreślać
            // trzeba sobie radzić instrukcjami sterującymi
            // dlaczego break: ponieważ opuszczamy pętlę kolumn całkowicie
            break;
          }

          if (columnIndexInternal == columnIndex)
          {
            // [A] przesunięcie indeksu o -1, następuje kiedy wpadniemy na
            //     kolumnę, która powinna być wykreślona
            //     w C++ nie możemy niczego wykreślać, trzeba sobie radzić arytmetycznie
            columnIndexOffset = -1;

            // w C++ nie możemy niczego wykreślać
            // trzeba sobie radzić instrukcjami sterującymi
            // dlaczego continue: ponieważ przeskakujemy tylko 1 element obecnej kolumny
            continue;
          }

          int rowIndexOfMinor = rowIndexInternal + rowIndexOffset;            // 0,1,2,..    -    0,1
          int columnIndexOfMinor = columnIndexInternal + columnIndexOffset;   // 0,1,2,..    -    0,1

          // to jest pomijane dla "skreślonych" (break-owanych lub continue-owanych) wierszy lub kolumn
          // wiersze, break-ujemy
          // kolumny, continue-ujemy
          // zeby wykreslic
          submatrix.numbers[rowIndexOfMinor][columnIndexOfMinor] = M.numbers[rowIndexInternal][columnIndexInternal];

        } // column inner

      } // row inner

      //
      // POD-MACIERZ (zmienna: minor) już przygotowana, przykładowo
      
      // | 5 | 6 |     | 1 | 2 | 3 |
      // | 8 | 9 |  z  | 4 | 5 | 6 |
      //               | 7 | 8 | 9 |
      determinants[rowIndex][columnIndex] = submatrix.determinant();

    } // column outer

  } // row outer

  return determinants;

}

//*****************************************************************************

///
/// goal
///   remove negative zeros -0
/// 

void Matrix::normalize()
{

  for (auto &row : this->numbers)
  {
    for (auto &number : row)
    {
      // remove negative zeros -0
      number = number == 0 ? 0 : number;
    }
  }
}

//*****************************************************************************
Matrix Matrix::operator*(double scalar) const
{
  Matrix M = this->copy();
  for (int rowIndex = 0; rowIndex < M.rowsCount(); rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < M.columnsCount(); columnIndex++)
    {
      M[rowIndex][columnIndex] *= scalar;
    }
  }

  return M;
}

//*****************************************************************************
Matrix Matrix::operator*(Matrix B) const
{
  Matrix A = this->copy();

  //
  // Prepare dimensions
  //

  int columnsCountOfA     = A.columnsCount();
  int rowsCountOfA        = A.rowsCount();
  int columnsCountOfB     = B.columnsCount();
  int rowsCountOfB        = B.rowsCount();

  //
  // Check A: MxN  B: NxO
  //

  if (columnsCountOfA != rowsCountOfB)
  {
    throw Exceptions::MatrixSizeException("cannot multiply matrices because sizes mismatch");
  }

  // resultant matrix
  Matrix R = Matrix(rowsCountOfA, columnsCountOfB);

  for (int rowIndexOfA = 0; rowIndexOfA < rowsCountOfA; rowIndexOfA++)
  {
    for (int columnIndexOfB = 0; columnIndexOfB < columnsCountOfB; columnIndexOfB++)
    {
      double dotProduct = 0;

      for (int elementIndexOfEither = 0; elementIndexOfEither < columnsCountOfA; elementIndexOfEither++)
      {
        dotProduct += A[rowIndexOfA][elementIndexOfEither] *
          // elementIndexOfEither can be treated as row index
          B[elementIndexOfEither][columnIndexOfB];
      }

      R[rowIndexOfA][columnIndexOfB] = dotProduct;

    }

  }

  return R;
}

//*****************************************************************************

///
/// desc
///   [] -> vector
///

vectorDouble& Matrix::operator[](size_t index)
{
  return numbers[index];
}

//*****************************************************************************

///
/// desc
///   [] -> const objects
///

const vectorDouble& Matrix::operator[](size_t index) const
{
  return numbers[index];
}

//*****************************************************************************
void Matrix::resize(int rowsCount, int columnsCount)
{
  numbers.resize(rowsCount);

  for (auto &row : numbers)
  {
    row.resize(columnsCount);
  }
}

//*****************************************************************************
double Matrix::rowsCount()
{
  return numbers.size();
}

//*****************************************************************************

/**
* desc
*   find longest number signature
*   input: {{-2, 4, -128}}
*   output: "-128"
*/

std::string Matrix::toString()
{
  std::string matrixSignature = "";

  // find longest element
  std::string longestElement = this->findLongestElement();

  for (int i = 0; i < this->rowsCount(); i++)
  {
    if (i > 0)
    {
      matrixSignature += NEW_LINE;
    }

    matrixSignature += "|";

    for (int j = 0; j < this->columnsCount(); j++)
    {
      std::stringstream ss;
      ss << numbers[i][j];
      std::string element = "";
      ss >> element;

      int spacesOffset = longestElement.length() - element.length() + 1; // one extra space
      matrixSignature += std::string(spacesOffset, ' ');
      matrixSignature += element;
    }

    matrixSignature += " |";
  }

  return matrixSignature;
}

//*****************************************************************************

/**
* desc
*   swap rows with columns
*   matrix: square or not square
*/

Matrix Matrix::transpose()
{
  int rowsCount = this->rowsCount();
  int columnsCount = this->columnsCount();

  // podmianka szerokosci z wysokoscia
  // | 1 | 2 | 3 |    | 1 | 4 | 
  // | 4 | 5 | 6 | -> | 2 | 5 |
  //                  | 3 | 6 |
  Matrix T = Matrix(columnsCount, rowsCount);

  for (int row = 0; row < rowsCount; row++)
  {
    for (int column = 0; column < columnsCount; column++)
    {
      T[column][row] = this->numbers[row][column];
    }
  }

  return T;
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE

