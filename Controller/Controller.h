//
// Created by tally on 09/09/24.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/Model.h"
#include "../View/View.h"

class Controller {
public:
    Controller();

    void loop();
    void stopRunning();

    void getCellPos(float &p_x, float &p_y) const;
    void getFoodPos(float &p_x, float &p_y) const;
private:
    Model model_;
    View view_;

    bool running_;
};



#endif //CONTROLLER_H
