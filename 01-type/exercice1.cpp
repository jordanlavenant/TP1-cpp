/*
  Exercice 1 - Type de bases

  Le programme suivant calcule la moyenne de 10 valeurs numériques.
  Le résultat est ensuite affiché.

  ? Q1 - Le résultat est il correct ?

  Non, le résultat n'est pas correct.

  ? Q2 - Quelle est la source de l'erreur ?

  La source de l'erreur est que la variable "moyenne" est déclarée comme un entier (int), ce qui entraîne une perte de précision lors du calcul de la moyenne.

  ? Q3 - Corrigez le code afin d'obtenir le bon résultat.

  Il faut déclarer la variable "moyenne" comme un nombre à virgule flottante (float ou double) pour conserver la précision lors du calcul de la moyenne.
*/

#include <iostream>

int main(int, char **) {
  float moyenne = 0.0f;

  moyenne = moyenne + 3.0f;
  moyenne = moyenne + 5.0f;
  moyenne = moyenne + 1.0f;
  moyenne = moyenne + 9.0f;
  moyenne = moyenne + 4.0f;
  moyenne = moyenne + 2.0f;
  moyenne = moyenne + 8.0f;
  moyenne = moyenne + 17.0f;
  moyenne = moyenne + 9.0f;
  moyenne = moyenne + 11.0f;

  std::cout << "Somme totale: " << moyenne << "\n";

  moyenne = moyenne / 10.0f;

  std::cout << "La moyenne est: " << moyenne << "\n";
}
