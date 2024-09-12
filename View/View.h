//
// Created by tally on 09/09/24.
//

#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>

class Controller;


class View {
public:
    explicit View(Controller *controller);
    ~View();

    void input() const;
    void draw() const;
    void waitFrame(float &dt);
private:
    SDL_Window* sdl_window_;
    SDL_Renderer* sdl_renderer_;
    float lastFrameTime_;
    Controller* controller_;

    void drawBackground(int r, int g, int b, int a) const;
    void Render() const;

    void drawCells() const;
    void drawFoods() const;

    void fillCircle(float x, float y, float r) const;

};



#endif //VIEW_H
