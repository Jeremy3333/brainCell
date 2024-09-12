//
// Created by tally on 11/09/24.
//

#include "Connection.h"
#include "../Utils.h"

Connection::Connection() : weight(Utils::randomDouble(-1.0, 1.0)), deltaWeight(0.0) {}

Connection::Connection(const double initialWeight) : weight(initialWeight), deltaWeight(0.0) {}

double Connection::getWeight() const {
  return weight;
}
