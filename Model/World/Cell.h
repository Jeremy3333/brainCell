//
// Created by tally on 09/09/24.
//

#ifndef CELL_H
#define CELL_H



class Cell {
public:
    Cell();
    Cell(int p_x, int p_y);
    ~Cell();

    void getPos(float &p_x, float &p_y) const;
    void update(float dt);
private:
    float x_, y_;
};



#endif //CELL_H
