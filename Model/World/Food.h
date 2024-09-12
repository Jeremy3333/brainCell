//
// Created by tally on 09/09/24.
//

#ifndef FOOD_H
#define FOOD_H



class Food {
public:
    Food();
    Food(int p_x, int p_y);
    ~Food();

    void getPos(float &p_x, float &p_y) const;
private:
    float x_, y_;
};



#endif //FOOD_H
