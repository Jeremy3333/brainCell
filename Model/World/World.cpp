//
// Created by tally on 09/09/24.
//

#include "World.h"

World::World() : cell_(200, 200), food_(400, 400) {}

World::~World()
= default;

void World::update(const float dt)
{
    cell_.update(dt);
}

void World::getCellPos(float& p_x, float& p_y) const
{
    cell_.getPos(p_x, p_y);
}

void World::getFoodPos(float& p_x, float& p_y) const
{
    food_.getPos(p_x, p_y);
}