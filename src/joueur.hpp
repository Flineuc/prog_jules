#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Joueur {
public:
  void setSigne(char lettre);
  char getSigne();
  Joueur joueur(const Joueur &J);
  void joue(Joueur J, std::vector<double> MousePos);
  std::vector<double> testPosition(std::vector<double> MousePos);

private:
  char signe;
};

#endif