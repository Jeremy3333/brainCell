//
// Created by tally on 09/09/24.
//

#ifndef WORLD_H
#define WORLD_H

#include "Cell.h"
#include "Food.h"

class World
{
public:
    World();
    ~World();

    void update(float dt);

    void getCellPos(float &p_x, float &p_y) const;
    void getFoodPos(float &p_x, float &p_y) const;
private:
    Cell cell_;
    Food food_;
};



#endif //WORLD_H