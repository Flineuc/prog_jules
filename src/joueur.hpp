#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct cellule {
  float x;
  float y;
  char signe;
};

class Joueur {
public:
  void setSigne(char lettre);
  char getSigne();
  Joueur joueur(const Joueur &J);
  cellule getPosition(std::vector<double> MousePos, cellule tab[3][3]);
  bool testWinner(cellule board[3][3]);

private:
  char signe;
};

bool testEndGame(cellule board[3][3]);

#endif