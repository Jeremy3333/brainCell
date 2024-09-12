//
// Created by tally on 09/09/24.
//

#include "Cell.h"

Cell::Cell() : x_(0), y_(0) {}

Cell::Cell(const int p_x, const int p_y) : x_(p_x), y_(p_y) {}

Cell::~Cell()
= default;

void Cell::getPos(float& p_x, float& p_y) const
{
    p_x = x_;
    p_y = y_;
}


void Cell::update(float dt)
{

}

