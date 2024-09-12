//
// Created by tally on 09/09/24.
//

#include "Food.h"

Food::Food() : x_(0), y_(0) {}

Food::Food(const int p_x, const int p_y) : x_(p_x), y_(p_y) {}

Food::~Food()
= default;

void Food::getPos(float& p_x, float& p_y) const
{
    p_x = x_;
    p_y = y_;
}
