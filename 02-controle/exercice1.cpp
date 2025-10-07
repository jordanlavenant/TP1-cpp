/*
  Exercice 1 - Avis de recherche

  Q1 - Obtenez un entier aléatoire entre 0 et RAND_MAX.
  Pour ce faire, consultez la documentation de std::rand.

  Q2 - Convertissez le en réel compris dans l'intervalle [1, 20]

  Q3 - De la même façon, remplissez le tableau data de valeurs réelles
  aléatoires comprises entre 1 et 20.

  Q4 - Affichez le contenu du tableau ainsi rempli

  Q5 - Ecrivez le code nécessaire pour
  parcourir le tableau data et insérer dans un tableau resultats les index des
  valeurs supérieurs à 15

  Q6 - Affichez le tableau ainsi rempli et vérifiez vos résultats

*/

#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

int main(int, char **) {
  std::srand(std::time(nullptr));

  std::vector<float> data(20);

  // Q1

  // Q2

  // Q3

  // Q4

  return 0;
}
