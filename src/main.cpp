#include "play_guess_the_number.hpp"
#include "play_hangman.hpp"
#include <iostream>

void show_the_list_of_commands() {
  std::cout << "\nSALUT TOI, TU VEUX JOUER A QUOI ?\n 1: JEU Guess the"
               "Number \n 2: JEU Hangman\n q: Quitter \n ";
}

const auto get_input_from_user<char>() {
  std::cout << "ALORS ?";
  char command;
  std::cin >> command;
  return command;
}

int main() {
  bool quit = false;
  while (!quit) {
    show_the_list_of_commands();
    const auto command = get_input_from_user<char>();
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