#include "play_guess_the_number.hpp"
#include "random.hpp"
#include <iostream>

int get_int_from_user() {
  int testedValue;
  std::cin >> testedValue;
  return testedValue;
}

void play_guess_the_number() {
  int value = rand(0, 20);
  std::cout << "\nJ'ai choisi un nombre entre 0 et 20. Trouve le !"
            << std::endl;
  std::cout << "Essaie :\n";
  int valueTested = get_int_from_user();
  while (value != valueTested) {
    if (valueTested < value)
      std::cout << "Trop petit !";
    else
      std::cout << "Trop grand !";
    std::cout << " Reessaie :\n";
    valueTested = get_int_from_user();
  }
  std::cout << "Bravo, tu as trouvé ! C'était bien le nombre " << value << " !"
            << std::endl;
}