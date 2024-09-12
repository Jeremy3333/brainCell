#ifndef RECEPTIVE_FIELD_H
#define RECEPTIVE_FIELD_H

#include <vector>
#include "Connection.h"  // Inclure la classe Connection pour les liens d'entrée

/**
 * @class ReceptiveField
 * @brief Représente un champ récepteur pour un neurone.
 *
 * Un champ récepteur contient plusieurs connexions, chacune représentant un lien d'entrée
 * vers le neurone. Chaque connexion est caractérisée par un poids.
 */
class ReceptiveField {
public:
  /**
   * @brief Constructeur par défaut de la classe ReceptiveField.
   */
  ReceptiveField();

  /**
   * @brief Ajoute une nouvelle connexion au champ récepteur.
   *
   * @param connection La connexion à ajouter.
   */
  void addConnection(const Connection& connection);

  /**
   * @brief Récupère toutes les connexions du champ récepteur.
   *
   * @return std::vector<Connection> Liste des connexions.
   */
  [[nodiscard]] std::vector<Connection> getConnections() const;

  /**
   * @brief Modifie le poids d'une connexion spécifique.
   *
   * @param index L'indice de la connexion à modifier.
   * @param weight Le nouveau poids à attribuer.
   */
  void setConnectionWeight(size_t index, double weight);

  /**
   * @brief Calcule la somme pondérée des entrées.
   *
   * @return double La somme pondérée des entrées du champ récepteur.
   */
  [[nodiscard]] double computeWeightedSum() const;

  /**
   * @brief Destructeur de la classe ReceptiveField.
   */
  ~ReceptiveField();

private:
  std::vector<Connection> connections;  ///< Liste des connexions (ou liens) d'entrée
};

#endif // RECEPTIVE_FIELD_H
