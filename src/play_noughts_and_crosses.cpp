#include "play_noughts_and_crosses.hpp"
#include "joueur.hpp"
#include "random.hpp"
#include <iostream>
#include <p6/p6.h>

void play_noughts_and_crosses() {

  auto ctx = p6::Context{{720, 720, "Morpion Vert//Rouge"}};
  float n = 3;
  Joueur J1;
  Joueur J2;
  J1.setSigne('x');
  J2.setSigne('o');
  Joueur current = J1;
  bool endGame = false;

  cellule tab[3][3];
  tab[0][0].x = -1;
  tab[0][0].y = 1;
  tab[0][1].x = -1 + 2 * 0.33;
  tab[0][1].y = 1;
  tab[0][2].x = -1 + 4 * 0.33;
  tab[0][2].y = 1;

  tab[1][0].x = -1;
  tab[1][0].y = 0.33;
  tab[1][1].x = -1 + 2 * 0.33;
  tab[1][1].y = 0.33;
  tab[1][2].x = -1 + 4 * 0.33;
  tab[1][2].y = 0.33;

  tab[2][0].x = -1;
  tab[2][0].y = -0.33;
  tab[2][1].x = -1 + 2 * 0.33;
  tab[2][1].y = -0.33;
  tab[2][2].x = -1 + 4 * 0.33;
  tab[2][2].y = -0.33;

  ctx.background({1, 1, 1, 1});
  const auto square_radius = 1 / n;
  std::cout << "Au tour du premier joueur !" << std::endl;

  while (endGame == false) {
    ctx.update = [&]() {
      ctx.mouse_pressed = [&](p6::MouseButton) {
        std::vector<double> posMouse;
        posMouse.push_back(ctx.mouse().x);
        posMouse.push_back(ctx.mouse().y);
        cellule cell_clicked = current.getPosition(posMouse, tab);

        switch (cell_clicked.signe) {
        case ('x'):
          ctx.fill = {1, 0, 0, 1};
          ctx.square(p6::TopLeftCorner{(cell_clicked.x), (cell_clicked.y)},
                     p6::Radius{0.33f});
          break;
        case ('o'):
          ctx.fill = {0, 1, 0, 1};
          ctx.square(p6::TopLeftCorner{(cell_clicked.x), (cell_clicked.y)},
                     p6::Radius{0.33f});
          break;
        };

        if (current.testWinner(tab)) {
          endGame = true;
          std::cout << current.getSigne() << " a gagné ! Clique sur la croix."
                    << std::endl;
        } else {
          if (current.getSigne() == 'x') {
            current = J2;
            std::cout << "Au tour de l'autre joueur !" << std::endl;
          } else {
            current = J1;
            std::cout << "Au tour de l'autre joueur !" << std::endl;
          }
        }
      };
    };

    for (float i = -(1.0f); i <= (1.0f); i = i + (2.0f / n)) {
      for (float j = -(1.0f); j <= (1.0f); j = j + (2.0f / n)) {
        ctx.use_fill = true;
        ctx.square(p6::TopLeftCorner{i, j}, p6::Radius{square_radius});
      }
    }
    ctx.start();
  }
  std::cout << " FIN DU JEU !" << std::endl;
}