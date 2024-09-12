//
// Created by tally on 09/09/24.
//

#include "Controller.h"

#include <iostream>
#include <ostream>

Controller::Controller() : model_(this), view_(this), running_(true) {}

void Controller::loop() {
    float dt = 0;
    while (running_) {
        model_.update(dt);
        view_.input();
        view_.draw();
        view_.waitFrame(dt);
    }
}

void Controller::stopRunning() {
    running_ = false;
}

void Controller::getCellPos(float& p_x, float& p_y) const
{
    model_.getCellPos(p_x, p_y);
}

void Controller::getFoodPos(float& p_x, float& p_y) const
{
    model_.getFoodPos(p_x, p_y);
}

