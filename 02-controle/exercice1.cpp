/*
  Exercice 1 - Avis de recherche

  ? Q1 - Obtenez un entier aléatoire entre 0 et RAND_MAX. Pour ce faire, consultez la documentation de std::rand.

  ? Q2 - Convertissez le en réel compris dans l'intervalle [1, 20]

  ? Q3 - De la même façon, remplissez le tableau data de valeurs réelles aléatoires comprises entre 1 et 20.

  ? Q4 - Affichez le contenu du tableau ainsi rempli

  ? Q5 - Ecrivez le code nécessaire pour parcourir le tableau data et insérer dans un tableau resultats les index des valeurs supérieurs à 15

  ? Q6 - Affichez le tableau ainsi rempli et vérifiez vos résultats

*/

#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

int main(int, char **) {
  std::srand(std::time(nullptr));

  std::vector<float> data(20);

  // ? Q1
  std::cout << std::rand() << "\n";

  // ? Q2
  std::cout << std::rand() % 20 + 1 << "\n";

  // ? Q3
  for (int i = 0; i < data.size(); ++i) {
    data[i] = std::rand() % 20 + 1;
  }  

  // ? Q4
  std::cout << "Random numbers : [ ";
  for (int i = 0; i < data.size(); ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << "]\n";

  // ? Q5
  std::vector<int> resultats;
  for (int i = 0; i < data.size(); ++i) {
    if (data[i] > 15) {
      resultats.push_back(i);
    }
  }

  // ? Q6
  std::cout << "Indexes (value > 15): [ ";
  for (int i = 0; i < resultats.size(); ++i) {
    std::cout << resultats[i] << " ";
  }
  std::cout << "]\n";
}
