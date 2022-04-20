#include "play_noughts_and_crosses.hpp"
#include "random.hpp"
#include <iostream>
#include <p6/p6.h>

/*
int get_int_from_user() {
  int testedValue;
  std::cin >> testedValue;
  return testedValue;
}

void play_guess_the_number() {
  int value = rand(0, 20);
  std::cout << "J'ai choisi un nombre entre 0 et 20. Trouve le !" << std::endl;
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
}*/