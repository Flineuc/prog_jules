#include "joueur.hpp"
#include <iostream>
#include <p6/p6.h>
#include <string>
#include <string_view>
#include <vector>

void Joueur::setSigne(char lettre) { this->signe = lettre; }

char Joueur::getSigne() { return this->signe; }

cellule Joueur::getPosition(std::vector<double> MousePos, cellule tab[3][3]) {
  cellule cell;
  float n = 3;
  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    tab[2][1].signe = this->getSigne();
    std::cout << this->getSigne() << " en 2,1" << std::endl;
    return tab[2][1];
  }
  //"milieu bas\n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    tab[2][0].signe = this->getSigne();
    std::cout << this->getSigne() << " en 2,0" << std::endl;
    return tab[2][0];
  }
  //"gauche bas\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > -1 &&
      MousePos[1] < -(1 / n)) {
    tab[2][2].signe = this->getSigne();
    std::cout << this->getSigne() << " en 2,2" << std::endl;
    return tab[2][2];
  }
  //"droit bas\n";
  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) &&
      MousePos[1] > -(1 / n) && MousePos[1] < (1 / n)) {
    tab[1][1].signe = this->getSigne();
    std::cout << this->getSigne() << " en 1,1" << std::endl;
    return tab[1][1];
  }
  //"milieu milieu\n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > -(1 / n) &&
      MousePos[1] < (1 / n)) {
    tab[1][0].signe = this->getSigne();
    std::cout << this->getSigne() << " en 1,0" << std::endl;
    return tab[1][0];
  }
  //"gauche milieu\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > -(1 / n) &&
      MousePos[1] < (1 / n)) {
    tab[1][2].signe = this->getSigne();
    std::cout << this->getSigne() << " en 1,2" << std::endl;
    return tab[1][2];
  }
  //"droit milieu\n";
  if (MousePos[0] > -(1 / n) && MousePos[0] < (1 / n) &&
      MousePos[1] > (1 / n) && MousePos[1] < 1) {
    tab[0][1].signe = this->getSigne();
    std::cout << this->getSigne() << " en 0,1" << std::endl;
    return tab[0][1];
  }
  //"milieu haut \n";
  if (MousePos[0] > -1 && MousePos[0] < -(1 / n) && MousePos[1] > (1 / n) &&
      MousePos[1] < 1) {
    tab[0][0].signe = this->getSigne();
    std::cout << this->getSigne() << " en 0,0" << std::endl;
    return tab[0][0];
  }
  //"gauche haut\n";
  if (MousePos[0] > (1 / n) && MousePos[0] < 1 && MousePos[1] > (1 / n) &&
      MousePos[1] < 1) {
    tab[0][2].signe = this->getSigne();
    std::cout << this->getSigne() << " en 0,2" << std::endl;
    return tab[0][2];
  } else {
    cell.x = -1;
    cell.y = -1;
    return cell;
  }
}

bool Joueur::testWinner(cellule board[3][3]) {
  int i = 0;
  // Test sur les lignes
  for (i = 0; i < 3; i++) {
    if ((board[i][0].signe == 'x' || board[i][0].signe == 'o') &&
        (board[i][0].signe == board[i][1].signe) &&
        (board[i][1].signe == board[i][2].signe)) {
      return true;
    }
  }
  // Test sur les colonnes.signe
  for (i = 0; i < 3; i++) {
    if ((board[0][i].signe == 'x' || board[0][i].signe == 'o') &&
        (board[0][i].signe == board[1][i].signe) &&
        (board[1][i].signe == board[2][i].signe)) {
      return true;
    }
  }
  // Test sur les diagonales
  if ((board[0][0].signe == 'x' || board[0][0].signe == 'o') &&
      (board[0][0].signe == board[1][1].signe) &&
      (board[1][1].signe == board[2][2].signe)) {
    return true;
  }
  // Test sur les diagonales
  if ((board[0][2].signe == 'x' || board[0][2].signe == 'o') &&
      (board[0][2].signe == board[1][1].signe) &&
      (board[1][1].signe == board[2][0].signe)) {
    return true;
  }
  return false;
}

bool testEndGame(cellule board[3][3]) {
  int i = 0, j = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j].signe == 'x' || board[i][j].signe == 'o') {
        return true;
      }
    }
  }
  return false;
}

// void Joueur::draw(p6::Context ctx, char tab[3][3]) {

//}
