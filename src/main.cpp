#include "play_guess_the_number.hpp"
#include "play_hangman.hpp"
#include <iostream>

void show_the_list_of_commands() {
  std::cout << "\nSALUT TOI, TU VEUX JOUER A QUOI ?\n 1: JEU Trouve le "
               "nombre \n 2: JEU du Pendu\n q: Quitter \n ";
}

char get_char_from_user() {
  std::cout << "ALORS ? ";
  char command;
  std::cin >> command;
  return command;
}

int main() {
  bool quit = false;
  while (!quit) {
    show_the_list_of_commands();
    const auto command = get_char_from_user();
    switch (command) {
    case '1':
      play_guess_the_number();
      break;
    case '2':
      play_hangman();
      break;
    case 'q':
      quit = true;
      break;
    default:
      std::cout << "Dsl, je connais pas cette commande..." << std::endl;
    }
  }
  return 0;
}