#include "joueur.hpp"
#include "random.hpp"
#include <iostream>
#include <p6/p6.h>
#include <string>
#include <string_view>
#include <vector>

void Joueur::setSigne(char lettre) { this->signe = lettre; }

char Joueur::getSigne() { return signe; }

std::vector<double> testPosition(std::vector<double> MousePos) {
  std::vector<double> cellule;
  float n = 3;
  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    cellule.push_back(2);
    cellule.push_back(1);
    return cellule;
  }
  //"milieu bas\n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    cellule.push_back(2);
    cellule.push_back(0);
    return cellule;
  }
  //"gauche bas\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    cellule.push_back(2);
    cellule.push_back(2);
    return cellule;
  }
  //"droit bas\n";

  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) &&
      MousePos[1] > -(1 / n) && MousePos[1] < (1 / n)) {
    cellule.push_back(1);
    cellule.push_back(1);
    return cellule;
  }
  //"milieu milieu\n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > -(1 / n) &&
      MousePos[1] < (1 / n)) {
    cellule.push_back(1);
    cellule.push_back(0);
    return cellule;
  }
  //"gauche milieu\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > -(1 / n) &&
      MousePos[1] < (1 / n)) {
    cellule.push_back(1);
    cellule.push_back(2);
    return cellule;
  }
  //"droit milieu\n";

  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) &&
      MousePos[1] > (1 / n) && MousePos[1] < 1) {
    cellule.push_back(0);
    cellule.push_back(1);
    return cellule;
  }
  //"milieu haut \n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > (1 / n) &&
      MousePos[1] < 1) {
    cellule.push_back(0);
    cellule.push_back(0);
    return cellule;
  }
  //"gauche haut\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > (1 / n) &&
      MousePos[1] < 1) {
    cellule.push_back(0);
    cellule.push_back(2);
    return cellule;
  }
  //"droit haut\n";
}

void joue(Joueur J, std::vector<double> MousePos) {
  std::vector<double> posCellule = J.testPosition(MousePos);
  switch (J.getSigne()) {
  case 'x':
    std::cout << "x en [" << posCellule[0] << " , " << posCellule[1] << "]";
  case 'o':
    std::cout << "o en [" << posCellule[0] << " , " << posCellule[1] << "]";
  }
}