/*
  Exercice 2 - Morpion

  Nous allons écrire un jeu simpliste de morpion. Le morpion est un jeu à deux
  joueurs qui consiste, à tour de rôle, de poser une croix (X) ou un rond (O)
  dans une grille 3x3. Un joueur gagne s'il aligne 3 symboles identiques en
  ligne, colonne ou diagonale.

  ? Q1 - Définissez un type 'grille' à base de std::array pour représenter la
  grille de jeu

  ? Q2 - Créez une valeur booléenne 'fin' valant false. Utilisez-la dans une
  boucle while dont la condition d'arrêt est le fait que cette variable vaille
  true. Vérifiez que le programme ne s'arrête pas.

  ? Q3 - Créez à l'endroit adéquat une variable 'symbole' de type char. Cette
  variable vaut 'X' au démarrage. Faites en sorte que, à chaque tour de boucle
  while, sa valeur alterne entre 'X' et 'O'.

  ? Q4 - Modifiez la boucle afin d'afficher un texte invitant le symbole courant à
  entrer sa position de jeu. Lisez ensuite une paire d'entiers entre 0 et 2.
  Cette paire d'entiers représente la coordonnée (x,y) dans la grille où le
  symbole courant doit être placé.

  ? Q5 - Construisez à l'endroit adéquat une variable de type 'grille' et mettez à
  jour sa valeur et affichez la à chaque itération.

  ? Q6 - Implémentez une série de tests qui vérifie après chaque coup si le joueur
  courant a gagné. Si c'est le cas, annoncez sa victoire et mettez la variable
  fin à true pour arrêter le jeu.

  ? QBONUS - Ajoutez tous les tests nécessaires à la capture des erreurs dues à
  l'entrée des positions des joueurs : case hors grille, case déjà utilisée, etc
  ...
*/

#include <array>
#include <iostream>

// ? Q1
using vecteur = std::array<std::string, 3>;
using grid = std::array<vecteur, 3>;

// ? Q2
bool fin = false;

// ? Q3
std::string symbole = "X";

void display_grid(grid const &g) {
  std::cout << "\n";
  for (int i = 0; i < g.size(); ++i) {
    std::cout << g[i][0] + " " + g[i][1] + " " + g[i][2] + "\n";
  }
}

void toggleTurn() {
  symbole == "X" ? symbole = "O" : symbole = "X";
}

void checkWin(grid &g, std::string symbole) {
  // ! check horizontaly
  for (int i = 0; i < g.size(); ++i) {
    if (g[i][0] == symbole && g[i][1] == symbole && g[i][2] == symbole) {
      fin = true;
      std::cout << "Le joueur " + symbole + " a gagné la partie !\n";
      return;
    }
  }
  // ! check verticaly
  for (int i = 0; i < g.size(); ++i) {
    if (g[0][i] == symbole && g[1][i] == symbole && g[2][i] == symbole) {
      fin = true;
      std::cout << "Le joueur " + symbole + " a gagné la partie !\n";
      return;
    }
  }
  // ! check diagonaly
  // Premier cas
  if (g[0][0] == symbole && g[1][1] == symbole && g[2][2] == symbole) {
    fin = true;
    std::cout << "Le joueur " + symbole + " a gagné la partie !\n";
    return;
  }
  // Second cas
  if (g[0][2] == symbole && g[1][1] == symbole && g[2][0] == symbole) {
    fin = true;
    std::cout << "Le joueur " + symbole + " a gagné la partie !\n";
    return;
  }
}

void turn(grid &g, int x, int y, std::string &symbole) {
  std::cout << "\n_____________________________\n\n";
  if (g[x][y] != "-") {
    std::cout << "Un symbole est déjà présent à cette position !\n";
    return;
  }

  g[x][y] = symbole;

  checkWin(g, symbole);
  toggleTurn(); 
}

int main(int, char **) { 
  // ? Q4
  int input_x, input_y;

  // ? Q5
  grid grid = {{{"-", "-", "-"}, {"-", "-", "-"}, {"-", "-", "-"}}};

  // ? QBonus

  while (!fin)
  {
    display_grid(grid);
    
    std::cout << "\nLe joueur " << symbole << " doit jouer\n";

    do {
      std::cout << "\nCoordonnées x (0-2): ";
      std::cin >> input_x;
    } while (input_x < 0 || input_x > 2);

    do {
      std::cout << "\nCoordonnées y (0-2): ";
      std::cin >> input_y;
    } while (input_y < 0 || input_y > 2);

    turn(grid, input_x, input_y, symbole);
  }
}
