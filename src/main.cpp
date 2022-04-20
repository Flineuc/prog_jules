#include "play_guess_the_number.hpp"
#include "play_hangman.hpp"
#include "play_noughts_and_crosses.hpp"
#include <iostream>
#include <p6/p6.h>

/*
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
}*/

int main() {
  auto ctx = p6::Context{{1280, 720, "Hello p6"}};
  float n = 3;
  ctx.background({0.5f, 0.3f, 0.8f});
  for (float j = 1 / n; j < 1; j = j + 1 / n) {
    for (float i = 1 / n; i < 1; i = i + 1 / n) {
      ctx.stroke = {1, 1, 1, 1};
      ctx.square(p6::Center(j, i), p6::Radius{1 / n});
    }
  }
  // glm::vec2 mouse()
  // ctx.square(p6::Center{}, p6::Radius{0.1f});
  // ctx.fill = {1, 0, 0, 0.5};
  ctx.start();
}