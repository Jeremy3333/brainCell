#ifndef NEURON_H
#define NEURON_H

#include <vector>

// Déclaration anticipée des classes pour éviter les dépendances circulaires
class ReceptiveField;
class Connection;

class Neuron {
private:
    // Identifiant unique pour ce neurone
    int id;

    // Valeur d'activation du neurone après le calcul (souvent après application de la fonction d'activation)
    double activationValue;

    // Biais ajouté à la somme pondérée des entrées pour ajuster la fonction d'activation
    double bias;

    // Liste des connexions entrantes, représentant les liens qui transmettent les signaux à ce neurone
    std::vector<Connection*> inputConnections;

    // Liste des connexions sortantes, représentant les liens qui transmettent les signaux vers d'autres neurones
    std::vector<Connection*> outputConnections;

    // Le champ récepteur du neurone, qui représente la région où les signaux sont reçus et traités
    ReceptiveField* receptiveField;

public:
    /**
     * @brief Constructeur de la classe Neuron
     * @param neuronId Identifiant unique du neurone
     * @param bias Valeur du biais initial (par défaut à 0.0)
     */
    explicit Neuron(int neuronId, double bias = 0.0);

    /**
     * @brief Destructeur pour libérer la mémoire (le cas échéant)
     */
    ~Neuron();

    /**
     * @brief Définir la valeur d'activation du neurone après le calcul des entrées
     * @param value La nouvelle valeur d'activation
     */
    void setActivationValue(double value);

    /**
     * @brief Obtenir la valeur actuelle d'activation du neurone
     * @return La valeur d'activation actuelle
     */
    [[nodiscard]] double getActivationValue() const;

    /**
     * @brief Définir la valeur du biais du neurone
     * @param newBias La nouvelle valeur du biais
     */
    void setBias(double newBias);

    /**
     * @brief Obtenir la valeur actuelle du biais du neurone
     * @return La valeur du biais
     */
    [[nodiscard]] double getBias() const;

    /**
     * @brief Ajouter une connexion entrante au neurone (un lien entrant)
     * @param connection Pointeur vers la connexion entrante
     */
    void addInputConnection(Connection* connection);

    /**
     * @brief Ajouter une connexion sortante du neurone (un lien sortant)
     * @param connection Pointeur vers la connexion sortante
     */
    void addOutputConnection(Connection* connection);

    /**
     * @brief Obtenir la liste des connexions entrantes du neurone
     * @return Référence constante à la liste des connexions entrantes
     */
    [[nodiscard]] const std::vector<Connection*>& getInputConnections() const;

    /**
     * @brief Obtenir la liste des connexions sortantes du neurone
     * @return Référence constante à la liste des connexions sortantes
     */
    [[nodiscard]] const std::vector<Connection*>& getOutputConnections() const;

    /**
     * @brief Calculer la somme pondérée des entrées reçues par ce neurone (avant activation)
     * @return La somme pondérée des entrées
     */
    [[nodiscard]] double computeWeightedInput() const;

    /**
     * @brief Appliquer une fonction d'activation sur la somme pondérée (par exemple, une fonction sigmoïde ou ReLU)
     * @return La valeur après application de la fonction d'activation
     */
    double activate();

    /**
     * @brief Méthode optionnelle pour afficher les informations du neurone (utile pour le débogage)
     */
    void displayInfo() const;
};

#endif // NEURON_H
