/*
  Exercice 2 - Manipulation de chaines de caractères

  ? Q1 - Construisez une variable de type chaine contenant 10 symboles '#'

  ? Q2 - Construisez une variable de type chaine contenant deux symboles '#'
  séparés par 8 espaces

  ? Q3 - En vous aidant des variables ci-dessus, affichez le motif suivant :

  ##########
  #        #
  #        #
  #        #
  ##########

  ? Q4 - En vous aidant du code précédent, construisez une variable de type chaine de caractère contenant ce motif et affichez-la.
*/

#include <iostream>
#include <string>

int main(int, char **) {
  // Q1
  int width = 10;
  std::string chain1 = "";
  for (int i = 0; i < width; i++) {
    chain1 = chain1 + "#";
  }
  std::cout << "La chaine 1 est: " << chain1 << "\n";

  // Q2
  int space = 8;
  std::string chain2 = "#";
  for (int i = 0; i < space; i++) {
    chain2 = chain2 + " ";
  }
  chain2 = chain2 + "#";
  std::cout << "La chaine 2 est: " << chain2 << "\n";

  // Q3
  std::cout << chain1 << "\n";
  for (int i = 0; i < 3; i++) {
    std::cout << chain2 << "\n";
  }
  std::cout << chain1 << "\n";

  // Q4
  std::string pattern = chain1 + "\n";
  for (int i = 0; i < 3; i++) {
    pattern = pattern + chain2 + "\n";
  }
  pattern = pattern + chain1 + "\n";
  std::cout << "Le motif est:\n" << pattern;

  return 0;
}
