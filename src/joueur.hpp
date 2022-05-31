#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct cellule {
  double x;
  double y;
  char signe;
};

struct board {
  std::vector<cellule> cellules;
};

class Joueur {
public:
  void setSigne(char lettre);
  char getSigne();
  Joueur joueur(const Joueur &J);
  void joue(std::vector<double> MousePos, board tab);
  void getPosition(std::vector<double> MousePos);

private:
  char signe;
};

#endif