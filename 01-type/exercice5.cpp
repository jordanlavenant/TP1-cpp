#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/**
Exercice 5 - Structures de contrôle et vecteurs

  Pour chaque fonction, utilisez les éléments de l'interface des conteneurs
adéquats et les structures de contrôle adéquates pour répondre à la
problématique des fonctions.

  Pensez à tester les éventuels corner cases.
**/

std::array<int, 4> revert(std::array<int, 4> const &tab) {
  // Renvoyer un array contenant les valeurs de tab rangées dans l'ordre inverse
  std::array<int, 4> rev;
  for (int i = 0; i < tab.size(); ++i) {
    rev[i] = tab[tab.size() - 1 - i];
  }
  return rev;
}

std::vector<int> find_all(std::array<int, 4> const &tab, int value) {
  // Renvoyer un tableau contenant tous les index où la valeur de tab vaut value
  std::vector<int> indexes;
  for (int i = 0; i < tab.size(); ++i) {
    if (tab[i] == value) indexes.push_back(i);
  }
  return indexes;
}

std::vector<int> uniques(std::array<int, 4> const &tab) {
  // Renvoyer un conteneur contenant la liste des valeurs uniques stockées dans
  // tab Ex:
  //  tab = [ 1 2 5 4 4 1 2 3 6 2 1 5 8 ]
  // renvoit
  //  [ 1 2 5 4 3 6 8 ]
  std::vector<int> uniques;
  for (int i = 0; i < tab.size(); ++i) {
    if (i == 0) uniques.push_back(tab[i]);
    else {
      if (std::find(uniques.begin(), uniques.end(), tab[i])==uniques.end()) {
        uniques.push_back(tab[i]);
      } 
    } 
  }
  return uniques;
}

int unique_sum(std::array<int, 4> const &tab) {
  // Renvoyer la somme des valeurs uniques de tab
  std::vector<int> v = uniques(tab);
  return std::accumulate(v.begin(), v.end(), 0);
}

void display_array(std::array<int, 4> const &tab) {
  std::string chaine = "[ ";
  for (int i = 0; i < tab.size(); ++i) {
    chaine += std::to_string(tab[i]) + " ";
  }
  chaine += "]\n";

  std::cout << chaine;
}

void display_vector(std::vector<int> const &vector) {
  std::string chaine = "[ ";
  for (int i = 0; i < vector.size(); ++i) {
    chaine += std::to_string(vector[i]) + " ";
  }
  chaine += "]\n";

  std::cout << chaine;
}

int main() {
  std::array<int, 4> tab = {1, 2, 2, 3};

  std::cout << "Initial array : ";
  display_array(tab);

  std::array<int, 4> res = revert(tab);
  std::cout << "Reversed array (revert) : ";
  display_array(res);

  std::vector<int> indexes = find_all(tab, 2);
  std::cout << "Find all indexes for value = 2 (find_all) : ";
  display_vector(indexes);

  std::vector<int> unique_values = uniques(tab);
  std::cout << "Uniques value in array (uniques) : ";
  display_vector(unique_values);

  int sum_unique_values = unique_sum(tab);
  std::cout << "Sum of uniques value in array (unique_sum) : " << sum_unique_values << "\n";
}