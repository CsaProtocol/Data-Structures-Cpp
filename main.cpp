
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << "\n";
  std::cout << "Seleziona il test da eseguire:" << "\n";
  std::cout << "1. zlasdtest" << "\n";
  std::cout << "2. zmytest" << "\n";
  int choice;
  std::cin >> choice;
  switch(choice) {
    case 1:
      lasdtest();
      break;
    case 2:
      mytest();
      break;
    default:
      std::cout << "Scelta non valida" << "\n";
  }
  return 0;
}
