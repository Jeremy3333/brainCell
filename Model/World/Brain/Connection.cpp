//
// Created by tally on 11/09/24.
//

#include <iostream>

#include "Connection.h"

Connection::Connection() : weight(0), deltaWeight(0.0) {}

Connection::Connection(const double initialWeight) : weight(initialWeight), deltaWeight(0.0) {}

double Connection::getWeight() const {
  return weight;
}

void Connection::setWeight(const double newWeight)
{
    weight = newWeight;
}

double Connection::getDeltaWeight() const
{
    return deltaWeight;
}

void Connection::setDeltaWeight(const double newDeltaWeight)
{
    deltaWeight = newDeltaWeight;
}

// Méthode pour mettre à jour le poids en fonction du deltaWeight et du taux d'apprentissage
void Connection::updateWeight(const double learningRate) {
    // Vérifie si le taux d'apprentissage est valide
    if (learningRate <= 0) {
        std::cerr << "Error: Learning rate must be positive." << std::endl;
        return;
    }

    // Mise à jour du poids
    weight -= learningRate * deltaWeight;

    // Optionnel : réinitialiser deltaWeight après la mise à jour
    deltaWeight = 0.0;
}

// Affiche les informations de la connexion
void Connection::printInfo() const {
    std::cout << "Weight: " << weight << ", Delta Weight: " << deltaWeight << std::endl;
}