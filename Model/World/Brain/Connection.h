#ifndef CONNECTION_H
#define CONNECTION_H

class Connection {
public:
  // Constructeur par défaut : initialise la connexion avec un poids aléatoire et un delta de 0
  Connection();

  // Constructeur paramétré : permet d'initialiser la connexion avec un poids donné
  explicit Connection(double initialWeight);

  // Accesseur : retourne le poids actuel de la connexion
  [[nodiscard]] double getWeight() const;

  // Modificateur : met à jour le poids de la connexion
  void setWeight(double newWeight);

  // Accesseur : retourne la valeur actuelle du deltaWeight
  [[nodiscard]] double getDeltaWeight() const;

  // Modificateur : met à jour la valeur du deltaWeight
  void setDeltaWeight(double newDeltaWeight);

  // Méthode pour mettre à jour le poids en fonction du deltaWeight et d'un taux d'apprentissage
  void updateWeight(double learningRate);

  // Affiche les informations de la connexion (poids et deltaWeight)
  void printInfo() const;

private:
  // Poids de la connexion (la force du lien entre deux neurones)
  double weight;

  // Valeur du gradient pour ajuster le poids pendant l'apprentissage
  double deltaWeight;
};

#endif // CONNECTION_H
