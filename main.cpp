
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  std::cout << "Seleziona il test da eseguire:" << std::endl;
  std::cout << "1. zlasdtest" << std::endl;
  std::cout << "2. zmytest" << std::endl;
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
      std::cout << "Scelta non valida" << std::endl;
  }
  return 0;
}
