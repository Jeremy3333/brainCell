//
// Created by tally on 09/09/24.
//

#ifndef MODEL_H
#define MODEL_H

#include "World/World.h"

class Controller;

class Model {
public:
    explicit Model(Controller *controller);

    void update(float p_dt);
    void getCellPos(float &p_x, float &p_y) const;
    void getFoodPos(float &p_x, float &p_y) const;

private:
    Controller* controller_;
    World world_;
};



#endif //MODEL_H
