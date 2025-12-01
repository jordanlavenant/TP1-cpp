/*
  Exercice 3 - Nuage de points

  ? Q1 - Implémentez une structure représentant un point 3D pondéré par un réel.

  ? Q2 - Implémentez les opérateurs nécessaires pour extraire et insérer une
  instance de cette structure dans un flux.

  ? Q3 - Renseignez vous sur la fonction std::getline.
    Utilisez la pour lire un fichier texte contenant une quantité
    arbitraire de points pondérés. Cette fonction prendra en paramètre le nom du
    fichier à lire et renverra un std::vector de point 3D pondéré.

  ? Q4 - Implémentez une fonction calculant la distance entre deux points pondérés

  ? Q5 - Implémentez une fonction renvoyant le point le plus éloigné d'un point
    donné parmi tous les points stockés dans un std::vector de points pondérés.

  ? Q6 - Implémentez une fonction renvoyant le point le plus proche d'un point
    donné parmi tous les points stockés dans un std::vector de points pondérés.

  ? Q7 - Implémentez une fonction calculant le barycentre d'un ensemble de point
    stocké dans un std::vector. 
    
  ? Q8 - Implémentez une fonction calculant la
    distance entre le point le plus proche et le plus éloigné du barycentre d'un
    ensemble de points.

  Chaque fonction devra être testée en isolation afin de s'assurer de son
  fonctionnement correct.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>

// ? Q1
struct point3D {
  int x;
  int y;
  int z;
};

// ? Q2
std::ostream& operator<<(std::ostream& os, point3D const &p) {
  os << "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ", " + std::to_string(p.z) + ")\n";
  return os;
}

std::vector<point3D> open_file(std::string path) {
  std::ifstream file(path);
  if (!file) {
    std::cout << "Erreur lors de l'ouverture du fichier donné.\n";
    return std::vector<point3D>();
  }

  std::string line;
  std::vector<point3D> res;

  std::cout << "Fichier choisi : " << path << std::endl;

  while (std::getline(file, line)) {
    std::istringstream coordinates(line);
    std::string value;
    point3D point;
    
    // Parse X
    if (std::getline(coordinates, value, ',')) {
      point.x = std::stoi(value);
    }
    // Parse Y
    if (std::getline(coordinates, value, ',')) {
      point.y = std::stoi(value);
    }
    // Parse Z
    if (std::getline(coordinates, value)) {
      point.z = std::stoi(value);
    }
    
    res.push_back(point);
  }
  
  return res;
}

double distance_ponderee(point3D A, point3D B) {
  return sqrt(std::pow(B.x - A.x, 2.0) + std::pow(B.y - A.y, 2.0) + std::pow(B.z - A.z, 2.0));
}

point3D furthest_point(std::vector<point3D> points, point3D point) {
  double max;
  int index_max;
  for (int i = 0; i < points.size(); ++i) {
    double current = distance_ponderee(points[i], point);
    if (current > max) {
      max = current;
      index_max = i;
    }
  }
  return points[index_max];
}

point3D nearest_point(std::vector<point3D> points, point3D point) {
  double min = distance_ponderee(points[0], point);
  int index_min = 0;
  for (int i = 1; i < points.size(); ++i) {
    double current = distance_ponderee(points[i], point);
    if (current < min) {
      min = current;
      index_min = i;
    }
  }
  return points[index_min];
}

point3D barycentre(std::vector<point3D> points) {
  point3D centre{0, 0, 0};
  for (point3D point : points) {
    centre.x += point.x;
    centre.y += point.y;
    centre.z += point.z;
  }
  centre.x /= points.size();
  centre.y /= points.size();
  centre.z /= points.size();
  return centre;
}

int main() {
  // ? Q3
  // std::string file_path;
  // std::cout << "Entrez le nom du fichier : ";
  // std::cin >> file_path;

  // std::vector<point3D> points = open_file(file_path);

  // for (point3D point : points) {
  //   std::cout << point;
  // }

  // ? Q4
  point3D A{0, 0, 0};
  // point3D B{1, 1, 1};

  // std::cout << distance_ponderee(A, B);

  // ? Q5
  std::vector<point3D> points = { point3D{0, 0, 1}, point3D{2, 3, 1}, point3D{4, 3, 2}};
  // std::cout << furthest_point(points, A);

  // ? Q6
  // std::cout << nearest_point(points, A);

  // ? Q7
  // std::cout << barycentre(points);

  // ? Q8
  point3D centre = barycentre(points);
  std::cout << distance_ponderee(nearest_point(points, centre), furthest_point(points, centre));
}
