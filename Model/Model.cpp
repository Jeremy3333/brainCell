//
// Created by tally on 09/09/24.
//

#include "Model.h"

#include <iostream>

Model::Model(Controller *controller) : controller_(controller) {}

void Model::update(const float p_dt) {
    world_.update(p_dt);
}

void Model::getCellPos(float& p_x, float& p_y) const
{
    world_.getCellPos(p_x, p_y);
}

void Model::getFoodPos(float& p_x, float& p_y) const
{
    world_.getFoodPos(p_x, p_y);
}
