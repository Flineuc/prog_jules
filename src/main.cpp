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
  ctx.mouse_pressed =
      [&](p6::MouseButton) { /*
if (ctx.mouse().x > -(1 / n) && ctx.mouse().x < (1 / n) &&
ctx.mouse().y > -1 && ctx.mouse().y < -(1 / n))
std::cout << "milieu bas\n";
if (ctx.mouse().x > -1 && ctx.mouse().x < -(1 / n) && ctx.mouse().y > -1 &&
ctx.mouse().y < -(1 / n))
std::cout << "gauche bas\n";
if (ctx.mouse().x > (1 / n) && ctx.mouse().x < 1 && ctx.mouse().y > -1 &&
ctx.mouse().y < -(1 / n))
std::cout << "droit bas\n";

if (ctx.mouse().x > -(1 / n) && ctx.mouse().x < (1 / n) &&
ctx.mouse().y > -(1 / n) && ctx.mouse().y < (1 / n))
std::cout << "milieu milieu\n";
if (ctx.mouse().x > -1 && ctx.mouse().x < -(1 / n) &&
ctx.mouse().y > -(1 / n) && ctx.mouse().y < (1 / n))
std::cout << "gauche milieu\n";
if (ctx.mouse().x > (1 / n) && ctx.mouse().x < 1 &&
ctx.mouse().y > -(1 / n) && ctx.mouse().y < (1 / n))
std::cout << "droit milieu\n";

if (ctx.mouse().x > -(1 / n) && ctx.mouse().x < (1 / n) &&
ctx.mouse().y > (1 / n) && ctx.mouse().y < 1)
std::cout << "milieu haut \n";
if (ctx.mouse().x > -1 && ctx.mouse().x < -(1 / n) &&
ctx.mouse().y > (1 / n) && ctx.mouse().y < 1)
std::cout << "gauche haut\n";
if (ctx.mouse().x > (1 / n) && ctx.mouse().x < 1 &&
ctx.mouse().y > (1 / n) && ctx.mouse().y < 1)
std::cout << "droit haut\n";
};*/
                             ctx.background(
                                 {0.5f, 0.3f, 0.8f}); // std::cout << size;
                             const auto square_radius = 1 / n;
                             ctx.update = [&]() {
                               for (float i = -(1.0f); i <= (1.0f);
                                    i = i + (2.0f / n)) {
                                 for (float j = -(1.0f); j <= (1.0f);
                                      j = j + (2.0f / n)) {
                                   ctx.fill = {0.5f, 1.0f, 0.5f, 0.5f};
                                   ctx.square(p6::TopLeftCorner{i, j},
                                              p6::Radius{square_radius});
                                 }
                               }
                             };
                             ctx.start();
      }