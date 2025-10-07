#include <array>
#include <iostream>
#include <vector>

/**
Exercice 5 - Structures de contrôle et vecteurs

  Pour chaque fonction, utilisez les éléments de l'interface des conteneurs
adéquats et les structures de contrôle adéquates pour répondre à la
problématique des fonctions.

  Pensez à tester les éventuels corner cases.
**/

std::array<int, 4> revert(std::array<int, 4> const &tab) {
  // Renvoyer un array contenant les valeurs de tab rangées dans l'ordre inverse
}

/* ??? */ find_all(std::array<int, 4> const &tab, int value) {
  // Renvoyer un tableau contenant tous les index où la valeur de tab vaut value
}

/* ??? */ uniques(std::array<int, 4> const &tab) {
  // Renvoyer un conteneur contenant la liste des valeurs uniques stockées dans
  // tab Ex:
  //  tab = [ 1 2 5 4 4 1 2 3 6 2 1 5 8 ]
  // renvoit
  //  [ 1 2 5 4 3 6 8 ]
}

/* ??? */ unique_sum(std::array<int, 4> const &tab) {
  // Renvoyer la somme des valeurs uniques de tab
}

int main() {
  std::array<int, 4> tab = {1, 2, 2, 3};
  // on peut passer ce tableau en argument d'une fonction comme ceci :
  revert(tab);
  return 0;
}