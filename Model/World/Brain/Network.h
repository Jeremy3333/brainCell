//
// Created by tally on 11/09/24.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <vector>

#include "Layer.h"

class Network {
public:
    /**
     * @brief Constructeur par défaut du réseau.
     */
    Network();

    /**
     * @brief Ajoute une couche au réseau.
     *
     * @param layer La couche à ajouter au réseau.
     */
    void addLayer(const Layer& layer);

    /**
     * @brief Effectue la propagation avant des entrées à travers toutes les couches du réseau.
     *
     * @param input Vecteur des valeurs d'entrée pour la première couche du réseau.
     * @return Vecteur des valeurs de sortie de la dernière couche du réseau.
     */
    std::vector<double> feedForward(const std::vector<double>& input);

    /**
     * @brief Retourne le nombre de couches dans le réseau.
     *
     * @return Nombre de couches dans le réseau.
     */
    [[nodiscard]] int getNumLayers() const;

    /**
     * @brief Accès à une couche spécifique du réseau.
     *
     * @param index L'indice de la couche à récupérer.
     * @return Référence constante vers la couche.
     */
    [[nodiscard]] const Layer& getLayer(int index) const;

    /**
     * @brief Détruit le réseau et libère les ressources associées.
     */
 ~Network();

private:
 std::vector<Layer> layers;  // Liste des couches qui composent le réseau
};



#endif //NETWORK_H
