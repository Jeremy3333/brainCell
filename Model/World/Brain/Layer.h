#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "Neuron.h"  // Inclusion de la classe Neuron

/**
 * @class Layer
 * @brief Représente une couche dans un réseau de neurones.
 *
 * Une couche contient un ensemble de neurones. Elle est responsable de gérer
 * l'activation de chaque neurone en fonction des entrées fournies.
 */
class Layer {
public:
    /**
     * @brief Constructeur par défaut.
     * Crée une couche vide.
     */
    Layer();

    /**
     * @brief Constructeur avec un nombre de neurones.
     *
     * @param numNeurons Le nombre de neurones dans la couche.
     * Crée une couche avec un nombre spécifique de neurones initialisés.
     */
    explicit Layer(int numNeurons);

    /**
     * @brief Active la couche.
     *
     * Cette méthode calcule la sortie de chaque neurone dans la couche en fonction des entrées données.
     *
     * @param inputs Un vecteur contenant les valeurs d'entrée pour chaque neurone.
     * @return std::vector<double> Un vecteur des valeurs de sortie des neurones de la couche.
     */
    std::vector<double> activate(const std::vector<double>& inputs);

    /**
     * @brief Retourne une référence au vecteur de neurones.
     *
     * @return const std::vector<Neuron>& Une référence constante au vecteur de neurones de la couche.
     */
    [[nodiscard]] const std::vector<Neuron>& getNeurons() const;

    /**
     * @brief Ajoute un neurone à la couche.
     *
     * @param neuron Le neurone à ajouter à la couche.
     */
    void addNeuron(const Neuron& neuron);

    /**
     * @brief Retourne le nombre de neurones dans la couche.
     *
     * @return int Le nombre de neurones dans la couche.
     */
    [[nodiscard]] int size() const;
private:
    std::vector<Neuron> neurons;  ///< Vecteur contenant tous les neurones de la couche.
};

#endif // LAYER_H
