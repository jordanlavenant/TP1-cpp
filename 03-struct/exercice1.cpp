/*
  Exercice 1 - Fraction

  Fournissez une implémentation d'une structure fraction représentant un nombre
  fractionnaire. Vous implémenterez sous forme de fonction ou d'opérateur
  surchargés les fonctionnalités suivantes:

  - addition fraction/fraction, entier/fraction, fraction/entier
  - soustraction fraction/fraction, entier/fraction, fraction/entier
  - multiplication fraction/fraction, entier/fraction, fraction/entier
  - division fraction/fraction, entier/fraction, fraction/entier
  - négation de fraction
  - conversion de la fraction en nombre réel double précision
  - insertion et extraction depuis un flux
*/

#include <iostream>

struct fraction {
  int num;
  int den;

  void display() {
    std::cout << this->num << "/" << this->den << "\n";
  }
};

double add(fraction x, fraction y) {
  return (static_cast<double>(x.num) / x.den) + (static_cast<double>(y.num) / y.den);
}

double substract(fraction x, fraction y) {
  return (static_cast<double>(x.num) / x.den) - (static_cast<double>(y.num) / y.den);
}

double multiply(fraction x, fraction y) {
  return (static_cast<double>(x.num) / x.den) * (static_cast<double>(y.num) / y.den);
}

double divided(fraction x, fraction y) {
  return (static_cast<double>(x.num) / x.den) / (static_cast<double>(y.num) / y.den);
}

double convert_to_double(fraction x) {
  return static_cast<double>(x.num) / x.den;
}

fraction convert_to_fraction(int x) {
  return fraction{x, 1};
}

int main() {
  fraction f1{1, 4};

  int entier = 2;

  f1.display();

  std::cout << add(f1, convert_to_fraction(entier)) << "\n";
}
