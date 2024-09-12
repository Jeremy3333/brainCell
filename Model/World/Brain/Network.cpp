//
// Created by tally on 11/09/24.
//

#include "Network.h"

// Constructeur par défaut
Network::Network() {
    // Aucune couche n'est présente initialement
    // Le réseau est vide, et des couches peuvent être ajoutées plus tard avec addLayer()
    layers = std::vector<Layer>();  // Initialisation explicite d'un vecteur de couches vide
}

void Network::addLayer(const Layer& layer)
{
    layers.push_back(layer);
}
