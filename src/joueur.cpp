#include "joueur.hpp"
#include <iostream>
#include <p6/p6.h>
#include <string>
#include <string_view>
#include <vector>

void Joueur::setSigne(char lettre) { this->signe = lettre; }

char Joueur::getSigne() { return this->signe; }

void Joueur::getPosition(std::vector<double> MousePos) {
  cellule cellule;
  float n = 3;
  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    cellule.x = 2;
    cellule.y = 1;
  }
  //"milieu bas\n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    cellule.x = 2;
    cellule.y = 0;
  }
  //"gauche bas\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    cellule.x = 2;
    cellule.y = 2;
  }
  //"droit bas\n";
  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) &&
      MousePos[1] > -(1 / n) && MousePos[1] < (1 / n)) {
    cellule.x = 1;
    cellule.y = 1;
  }
  //"milieu milieu\n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > -(1 / n) &&
      MousePos[1] < (1 / n)) {
    cellule.x = 1;
    cellule.y = 0;
  }
  //"gauche milieu\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > -(1 / n) &&
      MousePos[1] < (1 / n)) {
    cellule.x = 1;
    cellule.y = 0;
  }
  //"droit milieu\n";
  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) &&
      MousePos[1] > (1 / n) && MousePos[1] < 1) {
    cellule.x = 0;
    cellule.y = 1;
  }
  //"milieu haut \n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > (1 / n) &&
      MousePos[1] < 1) {
    cellule.x = 0;
    cellule.y = 0;
  }
  //"gauche haut\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > (1 / n) &&
      MousePos[1] < 1) {
    cellule.x = 0;
    cellule.y = 2;
  }
  //"droit haut\n";
  cellule.signe = this->getSigne();
  std::cout << cellule.signe << " en [" << cellule.x << " , " << cellule.y
            << "] \n";
  // return cellule;
}
/*
void Joueur::joue(std::vector<double> MousePos, board tab) {
  cellule cell = this->getPosition(MousePos);
  cell.signe = this->getSigne();
  tab.cellules.push_back(cell);
}*/