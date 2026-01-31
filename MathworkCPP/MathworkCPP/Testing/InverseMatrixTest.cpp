#include "InverseMatrixTest.h"

using namespace MathworkCPP;

//*****************************************************************************

void Testing::InverseMatrixTest::test()
{
  // klasa uzywajaca std::cout i std::cin (wrapper komunikacyjny)
  ConsoleInterface console;

  console.log(NEW_PARA);
  console.log(NEW_LINE + "//-----------------------------------------------------------------------------");
  console.log(NEW_LINE + "Testing class Matrix");

  console.log(NEW_LINE + "//*****************************************************************************");
  console.log(NEW_LINE + "Testing inverse()");

  // tutaj bedziemy przechowywac wynik
  Matrix inverse;
  Matrix matrix;

  // flaga do oznaczania bledow
  bool isFailure;
  
  do
  {
    // domniemanie zakladamy brak bledu
    isFailure = 0;

    // komunikat zachety
    console.log("Prosze podac macierz (format: \"{{a,b},{c,d}}\"): ", true);

    // wczytujemy napis uzytkownika
    std::string reading { console.read() };

    // wczesniej zdefiniowany obiekt      przypisanie=      niejawne wywolanie konstruktora
    matrix = reading.c_str();

    try
    {
      // obliczanie odwrotnosci macierzy
      inverse = matrix.inverse();
    }
    catch (Exceptions::Exception e)
    {
      // nie udalo sie obliczyc odwrotnosci
      console.log(e.getMessage(), true);

      // ustawienie flagi bledu
      isFailure = 1;
    }

    // isFailure has to be inside: outer scope
  } while (isFailure);

  // (eleganckie) wypisanie macierzy
  console.log(matrix.toString(), true);

  // tytul macierzy odwrotnej
  console.log("Macierz A^-1", true);

  // wypisanie odwrotnosci
  console.log(inverse.toString(), true);
}
