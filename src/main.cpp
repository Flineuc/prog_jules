#include "joueur.hpp"
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
  auto ctx = p6::Context{{720, 720, "Hello p6"}};
  float n = 3;
  Joueur J1;
  Joueur J2;
  J1.setSigne('x');
  J2.setSigne('o');
  Joueur current = J1;
  board tab;

  // for (int i = 0; i < 5; i++) {
  ctx.mouse_pressed = [&](p6::MouseButton) {
    std::vector<double> posMouse;
    posMouse.push_back(ctx.mouse().x);
    posMouse.push_back(ctx.mouse().y);
    // cellule cell;
    current.getPosition(posMouse);
    // current.joue(posMouse, tab);
    // std::cout << tab.cellules[0].x << " et " << tab.cellules[0].y <<
    // std::endl;
    if (current.getSigne() == 'x')
      current = J2;
    else
      current = J1;
  };

  ctx.background({0.5f, 0.3f, 0.8f}); // std::cout << size;
  const auto square_radius = 1 / n;
  ctx.update = [&]() {
    for (float i = -(1.0f); i <= (1.0f); i = i + (2.0f / n)) {
      for (float j = -(1.0f); j <= (1.0f); j = j + (2.0f / n)) {
        ctx.fill = {0.5f, 1.0f, 0.5f, 0.5f};
        ctx.square(p6::TopLeftCorner{i, j}, p6::Radius{square_radius});
      }
    }
  };
  ctx.start();
}