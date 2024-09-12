#include <iostream>
#include <cassert> // Pour les tests assert
#include "Model/World/Brain/Connection.h" // Inclusion du header de la classe Connection

int main() {
  // Test 1 : Initialisation par défaut
    const Connection conn1;
  std::cout << "Test 1: Initialisation par défaut\n";
  assert(conn1.getWeight() == 0.0 && "Le poids initial par défaut devrait être 0");
  assert(conn1.getDeltaWeight() == 0.0 && "Le deltaWeight initial par défaut devrait être 0");

  // Test 2 : Initialisation avec un poids spécifique
  constexpr double initialWeight = 0.5;
  Connection conn2(initialWeight);
  std::cout << "Test 2: Initialisation avec un poids spécifique\n";
  assert(conn2.getWeight() == initialWeight && "Le poids devrait être égal au poids initialisé");

  // Test 3 : Mise à jour du poids
  constexpr double newWeight = 0.8;
  conn2.setWeight(newWeight);
  std::cout << "Test 3: Mise à jour du poids\n";
  assert(conn2.getWeight() == newWeight && "Le poids n'a pas été correctement mis à jour");

  // Test 4 : Mise à jour du deltaWeight
  constexpr double newDeltaWeight = 0.1;
  conn2.setDeltaWeight(newDeltaWeight);
  std::cout << "Test 4: Mise à jour du deltaWeight\n";
  assert(conn2.getDeltaWeight() == newDeltaWeight && "Le deltaWeight n'a pas été correctement mis à jour");

  // Test 5 : Mise à jour du poids en fonction du deltaWeight et du taux d'apprentissage
   constexpr double learningRate = 0.05;
  conn2.updateWeight(learningRate);
  std::cout << "Test 5: Mise à jour du poids en fonction du deltaWeight et du taux d'apprentissage\n";
  assert(conn2.getWeight() == newWeight - learningRate * newDeltaWeight &&
         "Le poids n'a pas été mis à jour correctement en fonction du deltaWeight et du learningRate");

  // Si tous les tests sont passés
  std::cout << "Tous les tests sont passés avec succès !" << std::endl;

  return 0;
}

/*
#include "Controller/Controller.h"

int main() {
    Controller controller;
    controller.loop();
    return 0;
}
*/